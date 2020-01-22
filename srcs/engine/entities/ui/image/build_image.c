/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:58:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 23:49:18 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resources/textures/texture.h"
#include "engine/resources/resources.h"
#include "engine/entities/ui/init_image.h"
#include "engine/entities/init_entity.h"
#include "engine/entities/update_entity.h"
#include "utils/parser.h"
#include "utils/error.h"
#include "build.h"

t_result	build_image_texture(t_list_head *images, t_image *self,
				t_dnon_object *texture_obj)
{
	t_bitmap_texture	*texture;

	if (images == NULL || self == NULL || texture_obj == NULL)
		return (throw_error("build_image_textures", "NULL pointer provided"));
	if (!(texture = get_bmp_by_texture_obj(images, texture_obj)))
		return (throw_error("build_b_texture_t", "get_bmp_by_obj failed"));
	if (!(init_usize_with_obj(&self->texture.size,
			get_child_list_object_by_key(texture_obj, "size"))))
		return (throw_error("build_b_texture_t", "init_usize_with_obj failed"));
	if (!(init_texture(&self->texture, self->texture.size)))
		return (throw_error("build_b_texture_t", "init_new_texture failed"));
	if (!fill_texture_with_bmp(&self->texture, texture))
		return (throw_error("init_button_textures", "fill texture failed"));
	if (!(init_vec2i_with_obj(&self->texture.offset,
			get_child_list_object_by_key(texture_obj, "offset"))))
		return (throw_error("build_b_texture_t", "init_usize_with_obj failed"));
	self->super.texture.curr = &self->texture;
	self->super.texture.curr_head = &self->texture.node;
	self->super.texture.prev = &self->texture;
	self->super.texture.prev_head = &self->texture.node;
	return (OK);
}

t_result	build_image(t_scene *scene, t_dnon_object *image_obj)
{
	t_image		*image;

	if (!(image = init_new_image()))
		return (throw_error("build_image", "init_new_image failed"));
	if (!build_image_texture(&scene->resources.images, image,
			get_child_list_object_by_key(image_obj, "texture")))
		return (throw_error("build_image", "build_textures failed"));
	if (!init_entity_with_obj(&image->super, &scene->renderer.ui_components,
			&scene->entities.ui_components,
			get_child_list_object_by_key(image_obj, "entity")))
		return (throw_error("build_image", "build_entity failed"));
	return (OK);
}
