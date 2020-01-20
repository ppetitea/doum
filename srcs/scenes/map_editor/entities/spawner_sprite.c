/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 23:23:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 21:25:57 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/ui/init_spawner.h"
#include "engine/resources/resources.h"
#include "engine/scenes/init_scene.h"
#include "utils/error.h"
#include "libft.h"

static t_result	init_map_editor_spawner_sprite_entity(t_spawner *spawner, t_scene *scene)
{
	if (!overwrite_spawner_entity_texture(&spawner->super.texture,
			&spawner->normal, ft_vec2i(0, 0)))
		return (throw_error("init_spawner", "overwrite e_texture failed"));
	if (!overwrite_spawner_entity_actions(&spawner->super.trigger))
		return (throw_error("init_spawner", "overwrite e_actions failed"));
	if (!overwrite_spawner_entity_listener(&spawner->super,
		&scene->renderer.ui_components, &scene->entities.ui_components, TRUE))
		return (throw_error("init_spawner", "overwrite listener failed"));
	return (OK);
}

t_result	init_map_editor_spawner_sprite(t_scene *scene)
{
	t_list_head			*images;
	t_bitmap_texture	*bmp;
	t_spawner			*spawner;
	t_usize				size;
	t_usize				screen;

	
	if (scene == NULL)
		return (throw_error("init_spawner", "NULL pointer provided"));
	images = &scene->resources.images;
	if (!(bmp = get_image_by_name(images, "button_x_orange")))
		return (throw_error("init_spawner", "spawner failed"));
	size = ft_usize(100, 100);
	if (!(spawner = init_new_spawner()))
		return (throw_error("init_spawner", "build spawner failed"));
	screen = scene->interface.screen_ref->size;
	if (!init_spawner_textures(spawner, *bmp, size,
		ft_vec2i(screen.x -200, screen.y - 200)))
		return (throw_error("init_spawner", "build s_textures failed"));
	if (!init_map_editor_spawner_sprite_entity(spawner, scene))
		return (throw_error("init_spawner", "build s_entity failed"));
	return (OK);
}

