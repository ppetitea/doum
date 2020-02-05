/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:37:42 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/05 16:41:45 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/entity_update.h"
#include "engine/game/game_init.h"
#include "engine/map/map_init.h"
#include "utils/error.h"
#include "build.h"

static t_result	build_map_animation_type_with_obj(t_map_texture *m_texture,
				t_dnon_object *map_texture_obj)
{
	if (map_texture_obj == NULL || map_texture_obj == NULL)
		return (throw_error("build_entity_animation_type", "NULL pointer"));
	if (strcmp_obj("animation", "stop", map_texture_obj))
		m_texture->animation = STOP;
	else if (strcmp_obj("animation", "in_progress", map_texture_obj))
		m_texture->animation = IN_PROGRESS;
	else if (strcmp_obj("animation", "final", map_texture_obj))
		m_texture->animation = FINAL;
	else if (strcmp_obj("animation", "ephemeral", map_texture_obj))
		m_texture->animation = EPHEMERAL;
	else if (strcmp_obj("animation", "none", map_texture_obj))
		m_texture->animation = NONE;
	else
	{
		m_texture->animation = NONE;
		throw_warning("entity_animation", "unknow animation type detected", 3);
	}
	return (OK);
}

t_result	build_voxel_map_texture_with_obj(t_list_head *images,
				t_map_texture *map_texture, t_dnon_object *m_texture_obj)
{
	if (images == NULL || map_texture == NULL)
		return (throw_error("build_voxel_map_texture", "NULL pointer"));
	if (m_texture_obj == NULL)
		return (ERROR);
	if (!build_textures_with_obj(images, &map_texture->textures,
				get_child_list_object_by_key(m_texture_obj, "textures")))
		return (ERROR);
	build_map_animation_type_with_obj(map_texture, m_texture_obj);
	return (OK);
}

t_result	build_voxel_map_textures_with_obj(t_list_head *images,
				t_map *map, t_dnon_object *map_obj)
{
	t_result result;

	if (images == NULL || map == NULL || map_obj == NULL)
		return (throw_error("build_voxel_map_with_obj", "NULL pointer"));
	result = build_voxel_map_texture_with_obj(images, &map->sky,
				get_child_list_object_by_key(map_obj, "sky"));
	throw_warning("sky textures:\t", result ? "OK" : "FAIL", 3);
	result = build_voxel_map_texture_with_obj(images, &map->color_map,
				get_child_list_object_by_key(map_obj, "color_map"));
	throw_warning("map textures:\t", result ? "OK" : "FAIL", 3);
	result = build_voxel_map_texture_with_obj(images, &map->height_map,
				get_child_list_object_by_key(map_obj, "height_map"));
	throw_warning("height_map textures:", result ? "OK" : "FAIL", 3);
	map->sky.curr = (t_texture*)map->sky.textures.next;
	map->color_map.curr =
		(t_texture*)map->color_map.textures.next;
	map->height_map.curr =
		(t_texture*)map->height_map.textures.next;
	return (OK);
}

t_result	add_entity_to_map(t_map *map, t_entity *entity,
				t_dnon_object *map_entity_obj)
{
	if (map == NULL || entity == NULL || map_entity_obj == NULL)
		return (throw_error("add_entity_to_map", "NULL pointer"));
	if (get_int_value_by_key(map_entity_obj, "oriented", 0))
	{
		if (get_int_value_by_key(map_entity_obj, "current_player", 0))
			map->character_ref = (t_character*)entity;
		else if (entity->status.display)
			list_add_entry(&entity->node, &map->e_oriented);
		else
			list_add_entry(&entity->node, &map->e_oriented_storage);
	}
	else
	{
		if (entity->status.display)
			list_add_entry(&entity->node, &map->e_static);
		else
			list_add_entry(&entity->node, &map->e_static_storage);
	}
	return (OK);
}

t_result	build_map_entity_with_obj(t_game_resources *resources,
				t_map *map, t_dnon_object *map_entity_obj)
{
	t_entity	*src;
	t_entity	*entity;
	char		*name;

	if (resources == NULL || map == NULL || map_entity_obj == NULL)
		return (throw_error("build_map_entity_with_obj", "NULL pointer"));
	if (!(name = get_string_value_by_key(map_entity_obj, "key", NULL)))
		return (throw_error("build_map_entity_with_obj", "name not found"));
	throw_debug("add entity:", name, 0);
	if (!(src = get_entity_by_name(&resources->entities, name)))
		return (throw_error("build_map_entity_with_obj", "entity not found"));
	if (!(entity = duplicate_entity_by_type(src)))
		return (throw_error("build_map_entity_with_obj", "entity_dup failed"));
	if (!overwrite_entity_by_type_with_obj(entity, map_entity_obj))
		return (throw_error("build_map_entity_with_obj", "entity_over failed"));
	add_entity_to_map(map, entity, map_entity_obj);
	return (OK);
}

t_result	build_map_entities_with_obj(t_game_resources *resources,
				t_map *map, t_dnon_object *map_entities_obj)
{
	t_dnon_object	*map_entity_obj;
	t_list_head		*pos;
	t_list_head		*next;
	t_result		result;
	
	if (resources == NULL || map == NULL)
		return (throw_error("build_map_entities_with_obj", "NULL pointer"));
	if (map_entities_obj == NULL)
		return (ERROR);
	pos = (t_list_head*)map_entities_obj->value;
	next = pos->next;
	while ((pos = next) != (t_list_head*)map_entities_obj->value)
	{
		next = next->next;
		map_entity_obj = (t_dnon_object*)pos;
		if (map_entity_obj->type == LIST)
		{
			result = build_map_entity_with_obj(resources, map, map_entity_obj);
			throw_warning("entity added:\t\t\t\t", result ? "OK" : "FAIL", 0);
		}
	}
	return (OK);
}

t_result	build_voxel_map_with_obj(t_game_resources *resources,
				t_map *map, t_dnon_object *map_obj)
{
	t_dnon_object	*map_entities_obj;
	t_result		result;

	if (resources == NULL || map == NULL || map_obj == NULL)
		return (throw_error("build_voxel_map_with_obj", "NULL pointer"));
	map->type = VOXEL_MAP;
	if (!(map->name = get_string_value_by_key(map_obj, "name", NULL)))
		return (throw_error("build_voxel_map_with_obj", "map name unknow"));
	throw_debug("new map:", map->name, 1);
	if (!build_voxel_map_textures_with_obj(&resources->images, map, map_obj))
		return (throw_error("build_voxel_map_with_obj", "textures failed"));
	map_entities_obj = get_child_list_object_by_key(map_obj, "entities");
	result = build_map_entities_with_obj(resources, map,
		get_child_list_object_by_key(map_entities_obj, "oriented"));
	throw_debug("oriented entity list:\t\t\t", result ? "OK" : "FAIL", 0);
	result = build_map_entities_with_obj(resources, map,
		get_child_list_object_by_key(map_entities_obj, "static"));
	throw_debug("static entity list:\t\t\t", result ? "OK" : "FAIL", 0);
	return (OK);
}

t_result	build_int_map_with_obj(t_game_resources *resources,
				t_map *map, t_dnon_object *map_obj)
{
	if (resources == NULL || map == NULL || map_obj == NULL)
		return (throw_error("build_int_map_with_obj", "NULL pointer"));
	(void)resources;
	(void)map;
	(void)map_obj;
	return (OK);
}

t_result	build_map_by_type_with_obj(t_game_resources *resources,
				t_map *map, t_dnon_object *map_obj)
{
	if (resources == NULL || map == NULL || map_obj == NULL)
		return (throw_error("build_map_by_type_with_obj", "NULL pointer"));
	if (strcmp_obj("type", "voxel", map_obj))
	{
		if (!build_voxel_map_with_obj(resources, map, map_obj))
			return (throw_error("build_map_by_type", "build_voxel_map fail"));
	}
	else if (strcmp_obj("type", "int", map_obj))
	{
		if (!build_int_map_with_obj(resources, map, map_obj))
			return (throw_error("build_map_by_type", "build_int_map fail"));
	}
	else
		return (throw_error("build_map_by_type_with_obj", "unknow map type"));
	return (OK);
}

t_result	build_new_map_with_obj(t_game *game,
				t_dnon_object *map_obj)
{
	t_map *map;

	if (game == NULL || map_obj == NULL)
		return (throw_error("build_new_map_with_obj", "NULL pointer"));
	if (!(map = init_new_map()))
		return (throw_error("build_new_map_with_obj", "malloc failed"));
	if (!build_map_by_type_with_obj(&game->resources, map, map_obj))
		return (throw_error("build_new_map_with_obj", "build_map failed"));
	if (get_int_value_by_key(map_obj, "current", 0))
		game->curr_map = map;
	list_add_entry(&map->node, &game->resources.voxel_maps);
	return (OK);
}

t_result	build_game_resources_maps(t_game *game,
				t_dnon_object *maps_obj)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_dnon_object	*map_obj;

	if (game == NULL || maps_obj == NULL)
		return (throw_error("build_game_maps", "NULL pointer provided"));
	pos = (t_list_head*)maps_obj->value;
	next = pos->next;
	while ((pos = next) != (t_list_head*)maps_obj->value)
	{
		next = next->next;
		map_obj = (t_dnon_object*)pos;
		if (maps_obj->type == LIST)
		{
			if (!build_new_map_with_obj(game, map_obj))
				throw_warning("build_maps", "build_map fail", 3);
		}
	}
	return (OK);
}
