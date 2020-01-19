/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 23:23:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 21:25:57 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/ui/build_button.h"
#include "engine/resources/resources.h"
#include "engine/scenes/build_scene.h"
#include "libft.h"

static t_result	init_map_editor_button_up_entity(t_button *button, t_scene *scene)
{
	if (!build_button_entity_listener(&button->super,
		&scene->renderer.ui_components, &scene->entities.ui_components, TRUE))
		return (throw_error("init_button_up", "build listener failed"));
	if (!build_button_entity_texture(&button->super.texture, button->normal,
			ft_vec2i(0, 0)))
		return (throw_error("init_button_up", "build e_texture failed"));
	return (OK);
}

t_result	init_map_editor_button_up(t_scene *scene)
{
	t_list_head			*images;
	t_bitmap_texture	*bmp_hover;
	t_bitmap_texture	*bmp_selected;
	t_button			*button;
	t_usize				size;

	if (scene == NULL)
		return (throw_error("init_button_up", "NULL pointer provided"));
	images = &scene->resources.images;
	if (!(bmp_hover == get_image_by_name(images, "button_up_hover")))
		return (throw_error("init_button_up", "button_up_hover failed"));
	if (!(bmp_selected == get_image_by_name(images, "button_up_select")))
		return (throw_error("init_button_up", "button_up_hover failed"));
	size = ft_usize(100, 100);
	if (!(button = build_button()))
		return (throw_error("init_button_up", "build button failed"));
	if (!build_button_textures(button, *bmp_hover, *bmp_selected, size))
		return (throw_error("init_button_up", "build b_textures failed"));
	return (OK);
}
