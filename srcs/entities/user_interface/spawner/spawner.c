/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 01:39:22 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 08:12:53 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "entities/ui/spawner.h"
#include "entities/entities.h"
#include "resources/textures/texture.h"

static t_result	duplicate_spawner(t_game *game, t_entity *entity)
{
	t_spawner	*self;

	if (entity->type != SPAWNER)
		return (throw_error("duplicate_spawner", "type isn't SPAWNER"));
	self = (t_spawner*)entity;
	if (self->initial_texture->offset.x != self->normal->offset.x ||
		self->initial_texture->offset.y != self->normal->offset.y)
		return (OK);
	if (!(self = self->create_spawner(game, self->initial_texture, TRUE)))
		return (throw_error("duplicate_spawner", "malloc failed"));
	return (OK);
}

static	t_listener_args entity_spawner_listener_args(t_game *game,
			t_bool display)
{
	t_listener_args	args;

	args.display = display;
	args.render_list = &game->renderer.ui_components;
	args.storage_list = &game->entities.ui_components;
	args.is_hoverable = TRUE;
	args.is_selectable = FALSE;
	args.action_select = NULL;
	args.is_draggable = TRUE;
	args.action_drag = (t_result(*)(t_game*, void*))duplicate_spawner;
	return (args);
}

static	t_entity_texture_args	entity_spawner_texture_args(
	t_texture *texture, t_animation_status animation)
{
	t_entity_texture_args	args;

	args.anchor = ft_vec2i(0, 0);
	args.texture = texture;
	args.animation = animation;
	args.update_anchor = (t_result(*)(void*, t_vec2i))update_spawner_anchor;
	args.update_offset = (t_result(*)(void*, t_vec2i))update_spawner_offset;
	args.update_texture = 
		(t_result(*)(void*))update_spawner_texture_with_status;
	return (args);
}

static	t_entity_args	entity_spawner_args(t_game *game, t_texture *texture,
			t_animation_status animation, t_bool display)
{
	t_entity_args	args;

	args.texture_args = entity_spawner_texture_args(texture, animation);
	args.listener_args = entity_spawner_listener_args(game, display);
	args.type = SPAWNER;
	args.pos = ft_vec2f(0, 0);
	args.dir = ft_vec2f(0, 0);
	return (args);
}

t_spawner	*create_spawner(t_game *game, t_texture *texture, t_bool display)
{
	t_spawner		*self;
	t_entity_args	args;

	if (!(self = (t_spawner*)malloc(sizeof(t_spawner))))
		return (throw_null("create_spawner", "malloc failed"));
	self->initial_texture = texture;
	if (!(self->normal = texture_filter(*texture, FILTER_HOVER)))
		return (throw_null("create_spawner", "filter failed"));
	if (!(self->hover = texture_filter(*texture, FILTER_NONE)))
		return (throw_null("create_spawner", "filter failed"));
	if (!(self->dragged = texture_filter(*texture, FILTER_BLEND)))
		return (throw_null("create_spawner", "filter failed"));
	self->create_spawner = create_spawner;
	args = entity_spawner_args(game, self->normal, NONE, display);
	build_entity(&self->super, args);
	return (self);
}
