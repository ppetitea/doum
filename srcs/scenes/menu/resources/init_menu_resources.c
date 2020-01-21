/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu_resources.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:18:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 03:38:34 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/events/keyboard.h"
#include "engine/resources/textures/texture.h"
#include "engine/resources/resources.h"
#include "engine/scenes/init_scene.h"
#include "utils/error.h"
#include "init.h"

t_result	resources_load_images(t_list_head *images, t_dnon_object *images_obj)
{
	t_list_head			*pos;
	t_list_head			*next;
	t_dnon_object		*child;
	t_bitmap_texture	*bmp;

	if (images == NULL || images_obj == NULL)
		return (throw_error("resources_load_images", "NULL pointer provided"));
	if (images_obj->type != LIST)
		return (throw_error("resources_load_images", "obj isn't list"));
	pos = (t_list_head*)images_obj->value;
	next = pos->next;
	while ((pos = next) != (t_list_head*)images_obj->value)
	{
		next = next->next;
		child = (t_dnon_object*)pos;
		if (child->type != STRING)
			return (throw_error("resources_load_images", "isn't string"));
		if (!(bmp = load_bmp(child->value)))
			return (throw_error("load_img", child->key));
		list_add_image(images, bmp, child->key);
	}
	return (OK);
}

t_result	init_menu_resources(t_scene *scene, t_dnon_object *resources_obj)
{
	t_dnon_object *images_obj;

	if (scene == NULL || resources_obj == NULL)
		return (throw_error("init_menu_resources", "NULL pointer provided"));
	if (!(images_obj = get_child_list_object_by_key(resources_obj, "images")))
		return (throw_error("init", "fail to find menu r images in file"));
	if (!resources_load_images(&scene->resources.images, images_obj))
		return (throw_error("init_menu_resources", "load_resources failed"));
	return (OK);
}
