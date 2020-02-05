/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:22:44 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/04 16:54:36 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/entity_update.h"
#include "engine/component/action.h"
#include "engine/game/game_init.h"
#include "utils/error.h"

#include <stdio.h>

t_result		hide_scene_entity(t_game *game, char *name)
{
	t_entity	*entity;
	t_list_head	*pos;
	t_list_head	*next;

	if (game == NULL || name == NULL)
		return (throw_error("hide_scene_entity", "NULL pointer provided"));
	if (game->curr_scene == NULL)
		return (throw_error("hide_scene_entity", "scene not found"));
	pos = &game->curr_scene->entities;
	next = pos->next;
	while ((pos = next) != &game->curr_scene->entities)
	{
		next = next->next;
		entity = (t_entity*)pos;
		if (!ft_strcmp(entity->name, name))
		{
			list_del_entry(&entity->node);
			list_add_entry(&entity->node, &game->curr_scene->entities_storage);
			return (OK);
		}
	}
	return (throw_error("hide_scene_entity", "entity not found"));
}
t_result		display_scene_entity(t_game *game, char *name)
{
	t_entity	*entity;
	t_list_head	*pos;
	t_list_head	*next;

	if (game == NULL || name == NULL)
		return (throw_error("display_scene_entity", "NULL pointer provided"));
	if (game->curr_scene == NULL)
		return (throw_error("display_scene_entity", "scene not found"));
	pos = &game->curr_scene->entities_storage;
	next = pos->next;
	while ((pos = next) != &game->curr_scene->entities_storage)
	{
		next = next->next;
		entity = (t_entity*)pos;
		if (!ft_strcmp(entity->name, name))
		{
			list_del_entry(&entity->node);
			list_add_entry(&entity->node, &game->curr_scene->entities);
			return (OK);
		}
	}
	return (throw_error("display_scene_entity", "entity not found"));
}

t_result	scene_entities_display_next(t_game *game, t_list_head *keys,
				int	offset, int amount)
{
	t_list_head		*pos;
	t_dnon_object	*entity_key_obj;
	int				i;

	if (game == NULL || keys == NULL)
		return (throw_error("entities_display_next", "NULL pointer"));
	i = 0;
	while (i < offset + amount * 2)
	{
		pos = keys;
		while ((pos = pos->next) != keys)
		{
			if (i >= offset && i < offset + amount)
			{
				entity_key_obj = (t_dnon_object*)pos;
				if (entity_key_obj->type == STRING)
					hide_scene_entity(game, (char*)entity_key_obj->value);
			}
			else if (i >= offset + amount && i < offset + amount * 2)
			{
				entity_key_obj = (t_dnon_object*)pos;
				if (entity_key_obj->type == STRING)
					display_scene_entity(game, (char*)entity_key_obj->value);
			}
			i++;
		}
	}
	return (OK);
}

t_result	entities_display_next(void *game_resource,
				t_resource_type resource_type, t_dnon_object *args)
{
	t_game			*game;
	t_dnon_object	*entity_keys_obj;
	t_list_head		*entity_keys;
	int				offset;
	int				amount;

	if (game_resource == NULL || args == NULL)
		return (throw_error("display_next", "NULL pointer provided"));
	if (resource_type != R_GAME)
		return (throw_error("display_next", "resource must be game instance"));
	game = (t_game*)game_resource;
	if (game->curr_scene == NULL)
		return (throw_error("display_next", "curr_scene not found"));
	if (!(entity_keys_obj = get_child_list_object_by_key(args, "keys")))
		return (throw_error("display_next", "wrong arg detected"));
	entity_keys = (t_list_head*)entity_keys_obj->value;
	if ((offset = get_int_value_by_key(args, "offset", 0)) < 0)
		offset = 0;
	if ((amount = get_int_value_by_key(args, "amount", 1)) < 1)
		amount = 1;
	scene_entities_display_next(game, entity_keys, offset, amount);
	if (offset + amount > (int)list_lenght(entity_keys))
		set_int_value_by_key(args, "offset", offset + amount - (int)list_lenght(entity_keys));
	else
		set_int_value_by_key(args, "offset", offset + amount);
	return (OK);
}

t_result	drag_entity(void *entity_resource,
				t_resource_type resource_type, t_dnon_object *args)
{
	t_entity	*entity;
	t_game		*game;

	ft_putstr("drag OK\n");
	if (entity_resource == NULL)
		return (throw_error("drag_entity", "NULL pointer provided"));
	if (resource_type != R_ENTITY)
		return (throw_error("drag_entity", "resource must be an entity"));
	game = game_singleton(NULL);
	entity = (t_entity*)entity_resource;
	entity->texture.anchor = game->interface.mouse.pos;
	(void)args;
	return (OK);
}