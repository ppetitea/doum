/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_oriented_build.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:52:35 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/25 00:55:38 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

t_result	build_oriented_textures(t_list_head *images,
				t_oriented_textures *textures, t_dnon_object *o_textures_obj)
{
	t_result	result;
	
	if (images == NULL || textures == NULL)
		return (throw_error("build_oriented_textures", "NULL pointer"));
	throw_debug("oriented textures:", "", 0);
	if (o_textures_obj == NULL)
		return (throw_warning_ok("oriented textures", "FAIL", 3));
	result = build_textures_with_obj(images, &textures->front,
		get_child_list_object_by_key(o_textures_obj, "front"));
		throw_warning_ok("front textures\t", result ? "OK" : "FAIL", 3);
	result = build_textures_with_obj(images, &textures->front_l,
		get_child_list_object_by_key(o_textures_obj, "front_l"));
		throw_warning_ok("front_left textures", result ? "OK" : "FAIL", 3);
	result = build_textures_with_obj(images, &textures->front_r,
		get_child_list_object_by_key(o_textures_obj, "front_r"));
		throw_warning_ok("front_right textures", result ? "OK" : "FAIL", 3);
	result = build_textures_with_obj(images, &textures->left,
		get_child_list_object_by_key(o_textures_obj, "left"));
		throw_warning_ok("left textures\t", result ? "OK" : "FAIL", 3);
	result = build_textures_with_obj(images, &textures->right,
		get_child_list_object_by_key(o_textures_obj, "right"));
		throw_warning_ok("right textures\t", result ? "OK" : "FAIL", 3);
	result = build_textures_with_obj(images, &textures->back,
		get_child_list_object_by_key(o_textures_obj, "back"));
		throw_warning_ok("back textures\t", result ? "OK" : "FAIL", 3);
	result = build_textures_with_obj(images, &textures->back_l,
		get_child_list_object_by_key(o_textures_obj, "back_l"));
		throw_warning_ok("back_left textures", result ? "OK" : "FAIL", 3);
	result = build_textures_with_obj(images, &textures->back_r,
		get_child_list_object_by_key(o_textures_obj, "back_r"));
		throw_warning_ok("back_right textures", result ? "OK" : "FAIL", 3);
	return (OK);
}
