/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:56:53 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/22 03:04:07 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resources/textures/texture.h"
#include "engine/resources/resources.h"
#include "engine/entities/ui/update_button.h"
#include "engine/entities/ui/init_button.h"
#include "engine/entities/init_entity.h"
#include "engine/entities/update_entity.h"
#include "utils/parser.h"
#include "utils/error.h"
#include "build.h"

t_result	build_button_hover_texture(t_list_head *list, t_button *self,
				t_dnon_object *hover_obj)
{
	t_bitmap_texture	*hover;
	
	if (list == NULL || self == NULL || hover_obj == NULL)
		return (throw_error("build_b_hover_t", "NULL pointer provided"));
	if (!(hover = get_bmp_by_texture_obj(list, hover_obj)))
		return (throw_error("build_b_hover_t", "get_bmp_by_obj failed"));
	if (!(init_usize_with_obj(&self->hover.size,
			get_child_list_object_by_key(hover_obj, "size"))))
		return (throw_error("build_b_hover_t", "init_usize_with_obj failed"));
	if (!(init_texture(&self->hover, self->hover.size)))
		return (throw_error("build_b_hover_t", "init_new_texture failed"));
	if (!fill_texture_with_bmp(&self->hover, hover))
		return (throw_error("init_button_textures", "fill texture failed"));
	if (!(init_vec2i_with_obj(&self->hover.offset,
			get_child_list_object_by_key(hover_obj, "offset"))))
		return (throw_error("build_b_hover_t", "init_usize_with_obj failed"));
	return (OK);
}

t_result	build_button_select_texture(t_list_head *list, t_button *self,
				t_dnon_object *select_obj)
{
	t_bitmap_texture	*select;

	if (list == NULL || self == NULL || select_obj == NULL)
		return (throw_error("build_b_select_t", "NULL pointer provided"));
	if (!(select = get_bmp_by_texture_obj(list, select_obj)))
		return (throw_error("build_b_select_t", "get_bmp_by_obj failed"));
	if (!(init_usize_with_obj(&self->selected.size,
			get_child_list_object_by_key(select_obj, "size"))))
		return (throw_error("build_b_select_t", "init_usize_with_obj failed"));
	if (!(init_texture(&self->selected, self->selected.size)))
		return (throw_error("build_b_select_t", "init_new_texture failed"));
	if (!fill_texture_with_bmp(&self->selected, select))
		return (throw_error("init_button_textures", "fill texture failed"));
	if (!(init_vec2i_with_obj(&self->selected.offset,
			get_child_list_object_by_key(select_obj, "offset"))))
		return (throw_error("build_b_select_t", "init_usize_with_obj failed"));
	return (OK);
}

t_result	build_button_textures(t_scene *scene, t_button *self,
				t_dnon_object *textures_obj)
{
	t_list_head	*images;

	if (scene == NULL || self == NULL || textures_obj == NULL)
		return (throw_error("build_button_textures", "NULL pointer provided"));
	images = &scene->resources.images;
	if (!build_button_hover_texture(images, self,
			get_child_list_object_by_key(textures_obj, "hover")))
		return (throw_error("build_button_textures", "build hover failed"));
	if (!build_button_select_texture(images, self,
			get_child_list_object_by_key(textures_obj, "select")))
		return (throw_error("build_button_textures", "buidl select failed"));
	if (!(texture_filter(&self->normal, self->hover, FILTER_HOVER)))
		return (throw_error("build_button_textures", "filter texture failed"));
	self->super.texture.curr = &self->normal;
	self->super.texture.curr_head = &self->normal.node;
	self->super.texture.prev = &self->normal;
	self->super.texture.prev_head = &self->normal.node;
	return (OK);
}

t_result	init_button_action_with_obj(t_button *button, 
			char *action)
{
	if (button == NULL || action == NULL)
		return (throw_error("init_button_action", "NULL pointer provided"));
	if (!ft_strcmp(action, "toogle_display"))
		button->action = toggle_display_entity;
	else
		return (throw_error("init_button_action", "action not found"));
	return (OK);
}

t_result	build_button(t_scene *scene, t_dnon_object *button_obj)
{
	t_button		*button;

	if (!(button = init_new_button()))
		return (throw_error("build_button", "init_new_button failed"));
	if (!build_button_textures(scene, button,
			get_child_list_object_by_key(button_obj, "textures")))
		return (throw_error("build_button", "build_textures failed"));
	if (!init_entity_with_obj(&button->super, &scene->renderer.ui_components,
			&scene->entities.ui_components,
			get_child_list_object_by_key(button_obj, "entity")))
		return (throw_error("build_button", "build_entity failed"));
	if (!overwrite_button_entity_actions(&button->super.trigger))
		return (throw_error("build_button", "overwrite actions failed"));
	if (!init_button_action_with_obj(button,
			get_string_value_by_key(button_obj, "action", NULL)))
		return (throw_error("build_button", "init_button_action failed"));
	return (OK);
}
