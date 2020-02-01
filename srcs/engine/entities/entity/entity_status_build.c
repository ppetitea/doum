/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_status_build.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:33:01 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/01 00:29:04 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

t_result	build_entity_status_with_obj(t_listener *status,
				t_dnon_object *status_obj)
{
	if (status == NULL)
		return (throw_error("build_entity_status", "NULL pointer provided"));
	else if (status_obj == NULL)
		return (throw_warning_error("build_entity_status", "no status", 3));
	status->display = get_int_value_by_key(status_obj, "display", 0);
	status->is_hoverable = get_int_value_by_key(status_obj, "hoverable", 0);
	status->is_selectable = get_int_value_by_key(status_obj, "selectable", 0);
	status->is_draggable = get_int_value_by_key(status_obj, "draggable", 0);
	return (OK);
}
