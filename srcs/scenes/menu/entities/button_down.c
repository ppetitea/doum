/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 23:23:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 04:23:36 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/ui/init_button.h"
#include "engine/resources/resources.h"
#include "engine/scenes/init_scene.h"
#include "utils/error.h"
#include "libft.h"

static t_result	init_menu_button_down_entity(t_button *button, t_scene *scene)
{
	if (!overwrite_button_entity_listener(&button->super,
		&scene->renderer.ui_components, &scene->entities.ui_components, TRUE))
		return (throw_error("init_button_down", "overwrite listener failed"));
	if (!overwrite_button_entity_texture(&button->super.texture,
			&button->normal, ft_vec2i(0, 0)))
		return (throw_error("init_button_down", "overwrite e_texture failed"));
	if (!overwrite_button_entity_actions(&button->super.trigger))
		return (throw_error("init_button_down", "overwrite actions failed"));
	return (OK);
}

t_result	init_menu_button_down(t_scene *scene)
{
	t_list_head			*images;
	t_bitmap_texture	*bmp_hover;
	t_bitmap_texture	*bmp_selected;
	t_button			*button;
	t_usize				size;

	if (scene == NULL)
		return (throw_error("init_button_down", "NULL pointer provided"));
	images = &scene->resources.images;
	if (!(bmp_hover = get_image_by_name(images, "button_down_white")))
		return (throw_error("init_button_down", "button_down_white failed"));
	if (!(bmp_selected = get_image_by_name(images, "button_down_orange")))
		return (throw_error("init_button_down", "button_down_orange failed"));
	size = ft_usize(100, 100);
	if (!(button = init_new_button()))
		return (throw_error("init_button_down", "build button failed"));
	if (!init_menu_button_down_entity(button, scene))
		return (throw_error("init_button_down", "build button entity failed"));
	if (!init_button_textures(button, *bmp_hover, *bmp_selected, size))
		return (throw_error("init_button_down", "build b_textures failed"));
	return (OK);
}
