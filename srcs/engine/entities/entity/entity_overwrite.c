/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_overwrite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 06:49:05 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/26 08:27:17 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity/entity_init.h"
#include "utils/error.h"
#include "build.h"

t_result	overwrite_listener_with_obj(t_listener *listener,
				t_dnon_object *listener_obj)
{
	int		result_i;
	
	if (listener == NULL || listener_obj == NULL)
		return (throw_error("overwrite_listener", "NULL pointer provided"));
	if ((result_i = get_int_value_by_key(listener_obj, "display", -1)) != -1)
		listener->display = (result_i == 1) ? TRUE : FALSE;
	if ((result_i = get_int_value_by_key(listener_obj, "hoverable", -1)) != -1)
		listener->is_hoverable = (result_i == 1) ? TRUE : FALSE;
	if ((result_i = get_int_value_by_key(listener_obj, "selectable", -1)) != -1)
		listener->is_selectable = (result_i == 1) ? TRUE : FALSE;
	if ((result_i = get_int_value_by_key(listener_obj, "draggable", -1)) != -1)
		listener->is_draggable = (result_i == 1) ? TRUE : FALSE;
	return (OK);
}

t_result	overwrite_entity_texture_with_obj(t_entity_texture *self,
				t_dnon_object *e_texture_obj)
{
	char			*string;
	float			result_f;
	t_dnon_object	*vec2i_obj;

	if (self == NULL || e_texture_obj == NULL)
		return (throw_error("overwrite_e_texture", "NULL pointer provided"));
	if ((result_f = get_float_value_by_key(e_texture_obj, "scale", -1)) != -1)
		self->scale = result_f;
	if ((vec2i_obj = get_child_list_object_by_key(e_texture_obj, "offset")))
		init_vec2i_with_obj(&self->offset, vec2i_obj);
	if ((vec2i_obj = get_child_list_object_by_key(e_texture_obj, "anchor")))
		init_vec2i_with_obj(&self->anchor, vec2i_obj);
	if ((string = get_string_value_by_key(e_texture_obj, "animation", NULL)))
		build_entity_animation_type_with_obj(self, e_texture_obj);
	return (OK);
}

t_result	overwrite_entity_with_obj(t_entity *self, t_dnon_object *entity_obj)
{
	t_dnon_object	*listener_obj;
	t_dnon_object	*e_texture_obj;
	
	if (self == NULL || entity_obj == NULL)
		return (throw_error("overwrite_entity", "NULL pointer provided"));
	if ((listener_obj = get_child_list_object_by_key(entity_obj, "listener")))
		overwrite_listener_with_obj(&self->status, listener_obj);
	if ((e_texture_obj = get_child_list_object_by_key(entity_obj, "listener")))
		overwrite_entity_texture_with_obj(&self->texture, e_texture_obj);
	return (OK);
}
