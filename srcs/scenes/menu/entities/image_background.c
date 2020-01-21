/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:39:17 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 20:42:13 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/ui/init_image.h"
#include "engine/resources/resources.h"
#include "engine/scenes/init_scene.h"
#include "utils/error.h"
#include "libft.h"
#include "init.h"

static t_result	init_menu_image_background_entity(t_image *image,
					t_scene *scene)
{
	if (!overwrite_image_entity_listener(&image->super,
		&scene->renderer.ui_components, &scene->entities.ui_components, TRUE))
		return (throw_error("init_image_bg", "overwrite listener failed"));
	if (!overwrite_image_entity_texture(&image->super.texture,
			&image->texture, ft_vec2i(0, 0)))
		return (throw_error("init_image_bg", "overwrite e_texture failed"));
	return (OK);
}

t_image		*init_menu_image_background(t_scene *scene)
{
	t_list_head			*images;
	t_bitmap_texture	*bmp;
	t_image				*image;
	t_usize				size;

	if (scene == NULL)
		return (throw_null("init_image_bg", "NULL pointer provided"));
	images = &scene->resources.images;
	if (!(bmp = get_image_by_name(images, "menu_background")))
		return (throw_null("init_image_bg", "image_bg failed"));
	size = scene->interface.screen_ref->size;
	if (!(image = init_new_image()))
		return (throw_null("init_image_bg", "build image failed"));
	if (!init_menu_image_background_entity(image, scene))
		return (throw_null("init_image_bg", "build image entity failed"));
	if (!init_image_textures(image, *bmp, size))
		return (throw_null("init_image_bg", "build b_textures failed"));
	return (image);
}
