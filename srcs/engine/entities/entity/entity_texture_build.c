/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_texture_build.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:30:43 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/27 22:23:57 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

t_result	build_entity_animation_type_with_obj(t_entity_texture *e_texture,
				t_dnon_object *e_texture_obj)
{
	if (e_texture_obj == NULL || e_texture_obj == NULL)
		return (throw_error("build_entity_animation_type", "NULL pointer"));
	if (strcmp_obj("animation", "stop", e_texture_obj))
		e_texture->animation = STOP;
	else if (strcmp_obj("animation", "in_progress", e_texture_obj))
		e_texture->animation = IN_PROGRESS;
	else if (strcmp_obj("animation", "final", e_texture_obj))
		e_texture->animation = FINAL;
	else if (strcmp_obj("animation", "ephemeral", e_texture_obj))
		e_texture->animation = EPHEMERAL;
	else if (strcmp_obj("animation", "none", e_texture_obj))
		e_texture->animation = NONE;
	else
	{
		e_texture->animation = NONE;
		throw_warning("entity_animation", "unknow animation type detected", 3);
	}
	return (OK);
}

t_result	memalloc_entity_textures(t_entity_texture *self)
{
	if (self == NULL)
		return (throw_error("memalloc_entity_textures", "NULL pointer"));
	if (!(self->normal = (t_list_head*)malloc(sizeof(t_list_head))))
		return (throw_error("memalloc_entity_textures", "malloc failed"));
	init_list_head(self->normal);
	if (!(self->hover = (t_list_head*)malloc(sizeof(t_list_head))))
		return (throw_error("memalloc_entity_textures", "malloc failed"));
	init_list_head(self->hover);
	if (!(self->dragged = (t_list_head*)malloc(sizeof(t_list_head))))
		return (throw_error("memalloc_entity_textures", "malloc failed"));
	init_list_head(self->dragged);
	return (OK);
}

t_result	init_entity_current_texture(t_entity_texture *self,
				t_list_head *texture)
{
	if (self == NULL || texture == NULL)
		return (throw_error("build_entity_current_texture", "NULL pointer"));
	if (texture == texture->next)
		return (throw_error("build_entity_current_texture", "no texture"));
	self->curr = (t_texture*)texture->next;
	self->curr_head = texture;
	self->prev = (t_texture*)texture->next;
	self->prev_head = texture;
	return (OK);
}

t_result	build_entity_textures_with_obj(t_list_head *images,
				t_entity_texture *e_texture, t_dnon_object *e_texture_obj)
{
	t_result result;

	if (images == NULL || e_texture == NULL || e_texture_obj == NULL)
		return (throw_error("build_entity_texture", "NULL pointer provided"));
	if (!memalloc_entity_textures(e_texture))
		return (throw_error("build_entity_texture", "memalloc_textures fail"));
	build_entity_animation_type_with_obj(e_texture, e_texture_obj);
	init_vec2i_with_obj(&e_texture->anchor,
		get_child_list_object_by_key(e_texture_obj, "anchor"));
	init_vec2i_with_obj(&e_texture->offset,
		get_child_list_object_by_key(e_texture_obj, "offset"));
	e_texture->scale = get_float_value_by_key(e_texture_obj, "scale", 1.0f);
	result = build_textures_with_obj(images, e_texture->normal,
		get_child_list_object_by_key(e_texture_obj, "normal"));
	throw_warning("normal texture:\t", result ? "OK" : "FAIL", 3);
	result = build_textures_with_obj(images, e_texture->hover,
		get_child_list_object_by_key(e_texture_obj, "hover"));
	throw_warning("hover texture:\t", result ? "OK" : "FAIL", 3);
	result = build_textures_with_obj(images, e_texture->dragged,
		get_child_list_object_by_key(e_texture_obj, "dragged"));
	throw_warning("dragged texture:", result ? "OK" : "FAIL", 3);
	init_entity_current_texture(e_texture, e_texture->normal);
	return (OK);
}
