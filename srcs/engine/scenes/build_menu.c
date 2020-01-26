/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:18:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 23:14:05 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/events/keyboard.h"
#include "engine/scenes/init_scene.h"
#include "engine/scenes/update_scene.h"
#include "engine/init_game.h"
#include "engine/update_game.h"
#include "utils/error.h"
#include "build.h"

t_result	build_menu_interface(t_scene *scene)
{
	if (scene == NULL)
		return (throw_error("init_menu_interface", "NULL pointer provided"));
	new_bind_key(&scene->interface.key_binds, SDLK_ESCAPE,
		destroy_game);
	return (OK);
}

t_result	build_menu_resources(t_scene *scene, t_dnon_object *resources_obj)
{
	t_dnon_object *images_obj;

	if (scene == NULL || resources_obj == NULL)
		return (throw_error("build_menu_resources", "NULL pointer provided"));
	if (!(images_obj = get_child_list_object_by_key(resources_obj, "images")))
		return (throw_error("build", "fail to find menu r images in file"));
	if (!resources_load_images(&scene->resources.images, images_obj))
		return (throw_error("build_menu_resources", "load_resources failed"));
	return (OK);
}

t_result	build_menu_entities(t_scene *scene, t_dnon_object *entities_obj)
{
	if (scene == NULL || entities_obj  == NULL)
		return (throw_error("init_menu_entities", "NULL pointer provided"));
	if (entities_obj->type != LIST)
		return (throw_error("init_menu_entities", "obj must be type LIST"));
	if (!build_entities(scene, (t_list_head*)entities_obj->value))
		return (throw_error("init_menu_entities", "failed to build entities"));
	return (OK);
}

t_scene	*build_menu_scene(t_game *game, t_dnon_object *scene_obj)
{
	char			*name;
	t_scene			*scene;
	t_dnon_object	*resources_obj;
	t_dnon_object	*entities_obj;

	name = NULL;
	if (game == NULL || scene_obj == NULL)
		return (throw_null("build_menu", "NULL pointer provided"));
	if (!(resources_obj = get_child_list_object_by_key(scene_obj, "resources")))
		return (throw_null("build", "fail to find menu resources in file"));
	if (!(entities_obj = get_child_list_object_by_key(scene_obj, "entities")))
		return (throw_null("build", "fail to find menu entities in file"));
	if (!(name = ft_strdup("menu")))
		return (throw_null("build_menu", "strdup failed"));
	if (!(scene = init_new_scene(name, &game->screen)))
		return (throw_null("build_menu", "init_new_scene failed"));
	if (!build_menu_interface(scene))
		return (throw_null("build_menu", "build_menu_interface failed"));
	if (!build_menu_resources(scene, resources_obj))
		return (throw_null("build_menu", "build_menu_resources failed"));
	if (!build_menu_entities(scene, entities_obj))
		return (throw_null("build_menu", "build_menu_entities failed"));
	list_add_entry(&scene->node, &game->scenes);
	return (scene);
}
