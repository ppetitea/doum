/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawner_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 23:23:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 21:25:57 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/ui/build_spawner.h"
#include "engine/resources/resources.h"
#include "engine/scenes/init_scene.h"
#include "libft.h"

static t_result	init_map_editor_spawner_entity(t_spawner *spawner, t_scene *scene)
{
	if (!build_spawner_entity_listener(&spawner->super,
		&scene->renderer.ui_components, &scene->entities.ui_components, TRUE))
		return (throw_error("init_spawner_up", "build listener failed"));
	if (!build_spawner_entity_texture(&spawner->super.texture, spawner->normal,
			ft_vec2i(0, 0)))
		return (throw_error("init_spawner_up", "build e_texture failed"));
	return (OK);
}

t_result	init_map_editor_spawner_exemple(t_scene *scene)
{
	t_list_head			*images;
	t_bitmap_texture	*bmp;
	t_spawner			*spawner;
	t_usize				size;
	
	if (scene == NULL)
		return (throw_error("init_spawner_up", "NULL pointer provided"));
	images = &scene->resources.images;
	if (!(bmp == get_image_by_name(images, "spawner_up")))
		return (throw_error("init_spawner_up", "spawner_up failed"));
	size = ft_usize(100, 100);
	if (!(spawner = build_spawner()))
		return (throw_error("init_spawner_up", "build spawner failed"));
	if (!build_spawner_textures(spawner, *bmp, size))
		return (throw_error("init_spawner_up", "build b_textures failed"));
	return (OK);
}

