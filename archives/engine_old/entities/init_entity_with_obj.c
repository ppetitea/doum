/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entity_with_obj.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:52:40 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/22 03:24:10 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/init_entity.h"
#include "engine/entities/update_entity.h"
#include "engine/entities/get_entity.h"
#include "utils/error.h"
#include "utils/parser.h"
#include "build.h"

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

t_result	init_entity_childs_with_obj(t_entity *parent, t_list_head *render,
				t_list_head *storage, t_dnon_object *childs_obj)
{
	t_list_head			*pos;
	t_list_head			*next;
	t_dnon_object		*child_obj;
	t_entity			*child;
	
	if (childs_obj ==  NULL)
		return (OK);
	if (render == NULL || storage == NULL || parent == NULL)
		return (throw_error("init_entity_childs", "NULL pointer provided"));
	pos = (t_list_head*)childs_obj->value;
	next = pos->next;
	while ((pos = next) != (t_list_head*)childs_obj->value)
	{
		next = next->next;
		child_obj = (t_dnon_object*)pos;
		if (child_obj->type != STRING)
			return (throw_error("init_entity_childs", "obj must be STRING"));
		if ((child = get_entity(render, child_obj->value)) != NULL)
			entity_add_child(parent, child);
		else if ((child = get_entity(storage, child_obj->value)) != NULL)
			entity_add_child(parent, child);
	}
	return (OK);
}

t_result	init_entity_with_obj(t_entity *self, t_list_head *render,
				t_list_head *storage, t_dnon_object *entity_obj)
{
	if (render == NULL || storage == NULL || self == NULL || entity_obj == NULL)
		return (throw_error("init_entity_with_obj", "NULL pointer provided"));
	if (!(self->name = get_string_value_by_key(entity_obj, "name", NULL)))
		return (throw_error("init_entity_with_obj", "get_string failed"));
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
	init_entity_childs_with_obj(self, render, storage,
			get_child_list_object_by_key(entity_obj, "childs"));
	return (OK);
}
