/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu_entities.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:18:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 09:33:21 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/ui/init_checkbox.h"
#include "engine/entities/ui/update_checkbox.h"
#include "engine/resources/textures/texture.h"
#include "engine/resources/resources.h"
#include "engine/entities/ui/init_button.h"
#include "engine/entities/ui/init_image.h"
#include "engine/scenes/init_scene.h"
#include "engine/init_game.h"
#include "utils/error.h"
#include "utils/parser.h"
#include "init.h"

#include <stdio.h>

t_result	init_usize_with_obj(t_usize *self, t_dnon_object *size_obj)
{
	if (self == NULL || size_obj == NULL)
		return (throw_error ("init_usize_with_obj", "NULL pointer provided"));
	self->x = (size_t)get_int_value_by_key(size_obj, "x", 0);
	self->y = (size_t)get_int_value_by_key(size_obj, "y", 0);
	return (OK);
}
t_result	init_vec2i_with_obj(t_vec2i *self, t_dnon_object *vec2i_obj)
{
	if (self == NULL || vec2i_obj == NULL)
		return (throw_error ("init_usize_with_obj", "NULL pointer provided"));
	self->x = get_int_value_by_key(vec2i_obj, "x", 0);
	self->y = get_int_value_by_key(vec2i_obj, "y", 0);
	return (OK);
}
t_result	init_vec2f_with_obj(t_vec2f *self, t_dnon_object *vec2f_obj)
{
	if (self == NULL || vec2f_obj == NULL)
		return (throw_error ("init_usize_with_obj", "NULL pointer provided"));
	self->x = get_float_value_by_key(vec2f_obj, "x", 0.0f);
	self->y = get_float_value_by_key(vec2f_obj, "y", 0.0f);
	return (OK);
}

t_result	init_entity_listener_with_obj(t_entity *self, t_list_head *render,
				t_list_head *storage, t_dnon_object *status_obj)
{
	t_listener *status;

	if (render == NULL || storage == NULL || self == NULL || status_obj == NULL)
		return (throw_error("init_e_listener_with_obj", "NULL pointer"));
	status = &self->status;
	status->display = get_int_value_by_key(status_obj, "display", 0);
	status->is_hoverable = get_int_value_by_key(status_obj, "hoverable", 0);
	status->is_selectable = get_int_value_by_key(status_obj, "selectable", 0);
	status->is_draggable = get_int_value_by_key(status_obj, "draggable", 0);
	status->render_list = render;
	status->storage_list = storage;
	if (status->display && get_int_value_by_key(status_obj, "first", 0))
		list_add_first(&self->node, render);
	else if (status->display)
		list_add_entry(&self->node, render);
	else
		list_add_entry(&self->node, storage);
	return (OK);
}

t_result	init_entity_texture_with_obj(t_entity_texture *self,
				t_dnon_object *e_texture_obj)
{
	char	*defaut;
	char	*anim;
	
	if (self == NULL || e_texture_obj == NULL)
		return (throw_error("init_entity_t_with_obj", "NULL pointer provided"));
	if (!init_vec2i_with_obj(&self->anchor,
			get_child_list_object_by_key(e_texture_obj, "anchor")))
		return (throw_error("init_entity_t_with_obj", "init_vec2i failed"));
	if (!(defaut = ft_strdup("none")))
		return (throw_error("init_entity_t_with_obj", "ft_strdup failed"));
	if (!(anim = get_string_value_by_key(e_texture_obj, "animation", defaut)))
		return (throw_error("init_entity_t_with_obj", "get_string_value fail"));
	if (!(ft_strcmp(anim, "stop")))
		self->animation = STOP;
	if (!(ft_strcmp(anim, "infinite")))
		self->animation = INFINITE;
	if (!(ft_strcmp(anim, "final")))
		self->animation = FINAL;
	else
		self->animation = NONE;
	return (OK);
}

t_result	init_entity_with_obj(t_entity *self, t_list_head *render,
				t_list_head *storage, t_dnon_object *entity_obj)
{
	if (render == NULL || storage == NULL || self == NULL || entity_obj == NULL)
		return (throw_error("init_entity_with_obj", "NULL pointer provided"));
	if (!init_vec2f_with_obj(&self->pos,
			get_child_list_object_by_key(entity_obj, "position")))
		return (throw_error("init_entity_with_obj", "init_vec2f failed"));
	if (!init_vec2f_with_obj(&self->dir,
			get_child_list_object_by_key(entity_obj, "direction")))
		return (throw_error("init_entity_with_obj", "init_vec2f failed"));
	if (!init_entity_listener_with_obj(self, render, storage, 
			get_child_list_object_by_key(entity_obj, "status")))
		return (throw_error("init_entity_with_obj", "init_listener failed"));
	if (!init_entity_texture_with_obj(&self->texture,
			get_child_list_object_by_key(entity_obj, "texture")))
		return (throw_error("init_entity_with_obj", "init_texture failed"));
	return (OK);
}

t_bitmap_texture	*get_bmp_by_texture_obj(t_list_head *list,
						t_dnon_object *texture_obj)
{
	t_bitmap_texture	*bmp;
	char				*key;
	char				*defaut;
	
	if (list == NULL || texture_obj == NULL)
		return (throw_null("get_bmp_by_texture_obj", "NULL pointer provided"));
	if (!(defaut = ft_strdup("default")))
		return (throw_null("get_bmp_by_texture_obj", "ft_strdup failed"));
	if (!(key = get_string_value_by_key(texture_obj, "key", defaut)))
		return (throw_null("get_bmp_by_texture_obj", "get_string_value fail"));
	if (!(bmp = get_image_by_name(list, key)))
		return (throw_null("build_button_textures", "get_img_by_name failed"));
	free(defaut);
	return (bmp);
}

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

t_result	build_button(t_scene *scene, t_dnon_object *entity_obj)
{
	t_button		*button;

	if (!(button = init_new_button()))
		return (throw_error("build_button", "init_new_button failed"));
	if (!build_button_textures(scene, button,
			get_child_list_object_by_key(entity_obj, "textures")))
		return (throw_error("build_button", "build_textures failed"));
	if (!init_entity_with_obj(&button->super, &scene->renderer.ui_components,
			&scene->entities.ui_components,
			get_child_list_object_by_key(entity_obj, "entity")))
		return (throw_error("build_button", "build_entity failed"));
	if (!overwrite_button_entity_actions(&button->super.trigger))
		return (throw_error("build_button", "overwrite actions failed"));
	return (OK);
}

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
t_result	build_image(t_scene *scene, t_dnon_object *entity_obj)
{
	t_image		*image;

	if (!(image = init_new_image()))
		return (throw_error("build_image", "init_new_image failed"));
	if (!build_image_texture(&scene->resources.images, image,
			get_child_list_object_by_key(entity_obj, "texture")))
		return (throw_error("build_image", "build_textures failed"));
	if (!init_entity_with_obj(&image->super, &scene->renderer.ui_components,
			&scene->entities.ui_components,
			get_child_list_object_by_key(entity_obj, "entity")))
		return (throw_error("build_image", "build_entity failed"));
	return (OK);
}

t_result	build_entity_by_type(t_scene *scene, t_dnon_object *entity_obj,
				char *entity_type)
{
	if (!ft_strcmp(entity_type, "button"))
		return (build_button(scene, entity_obj));
	if (!ft_strcmp(entity_type, "image"))
		return (build_image(scene, entity_obj));
	// else if (!ft_strcmp(entity_type, "button"))
	// 	return (build_buttton(scene, entity_obj));
	return (throw_error("build_entity_by_type", "unknow type detected"));
}

t_result	build_entities(t_scene *scene, t_list_head *entities)
{
	t_list_head			*pos;
	t_list_head			*next;
	t_dnon_object		*entity;

	if (scene == NULL || entities == NULL)
		return (throw_error("build_entities", "NULL pointer provided"));
	pos = entities;
	next = pos->next;
	while ((pos = next) != entities)
	{
		next = next->next;
		entity = (t_dnon_object*)pos;
		if (entity->type != LIST)
			return (throw_error("build_entities", "obj must be type LIST"));
		if (!build_entity_by_type(scene, entity,
				get_string_value_by_key(entity, "type", NULL)))
			return (throw_error("build_entities", "failed to build"));
	}
	return (OK);
}

t_result	init_menu_entities(t_scene *scene, t_dnon_object *entities_obj)
{
	// t_checkbox	*checkbox;
	// t_image		*image;

	if (scene == NULL || entities_obj  == NULL)
		return (throw_error("init_menu_entities", "NULL pointer provided"));
	if (entities_obj->type != LIST)
		return (throw_error("init_menu_entities", "obj must be type LIST"));
	if (!build_entities(scene, (t_list_head*)entities_obj->value))
		return (throw_error("init_menu_entities", "failed to build entities"));
	// if (!(button = init_menu_button_down(scene)))
	// 	return (throw_error("init_menu_entities", "init button down failed"));
	// if (!(image = init_menu_image_background(scene)))
	// 	return (throw_error("init_menu_entities", "init button down failed"));
	// link_entity_to_checkbox(checkbox, &button->super);
	return (OK);
}
