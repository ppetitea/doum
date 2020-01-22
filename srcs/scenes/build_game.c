/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_game.c                                        :+:      :+:    :+:   */
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

t_result	build_game_interface(t_scene *scene)
{
	if (scene == NULL)
		return (throw_error("init_game_interface", "NULL pointer provided"));
	new_bind_key(&scene->interface.key_binds, SDLK_ESCAPE,
		swap_to_menu_scene);
	return (OK);
}

t_result	build_game_resources(t_scene *scene, t_dnon_object *resources_obj)
{
	t_dnon_object *images_obj;

	if (scene == NULL || resources_obj == NULL)
		return (throw_error("build_game_resources", "NULL pointer provided"));
	if (!(images_obj = get_child_list_object_by_key(resources_obj, "images")))
		return (throw_error("build", "fail to find game r images in file"));
	if (!resources_load_images(&scene->resources.images, images_obj))
		return (throw_error("build_game_resources", "load_resources failed"));
	return (OK);
}

t_result	build_game_entities(t_scene *scene, t_dnon_object *entities_obj)
{
	if (scene == NULL || entities_obj  == NULL)
		return (throw_error("init_game_entities", "NULL pointer provided"));
	if (entities_obj->type != LIST)
		return (throw_error("init_game_entities", "obj must be type LIST"));
	if (!build_entities(scene, (t_list_head*)entities_obj->value))
		return (throw_error("init_game_entities", "failed to build entities"));
	return (OK);
}

t_scene	*build_game_scene(t_game *game, t_dnon_object *scene_obj)
{
	char			*name;
	t_scene			*scene;
	t_dnon_object	*resources_obj;
	t_dnon_object	*entities_obj;

	name = NULL;
	if (game == NULL || scene_obj == NULL)
		return (throw_null("build_game", "NULL pointer provided"));
	if (!(resources_obj = get_child_list_object_by_key(scene_obj, "resources")))
		return (throw_null("build", "fail to find game resources in file"));
	if (!(entities_obj = get_child_list_object_by_key(scene_obj, "entities")))
		return (throw_null("build", "fail to find game entities in file"));
	if (!(name = ft_strdup("game")))
		return (throw_null("build_game", "strdup failed"));
	if (!(scene = init_new_scene(name, &game->screen)))
		return (throw_null("build_game", "init_new_scene failed"));
	if (!build_game_interface(scene))
		return (throw_null("build_game", "build_game_interface failed"));
	if (!build_game_resources(scene, resources_obj))
		return (throw_null("build_game", "build_game_resources failed"));
	list_add_entry(&scene->node, &game->scenes);
	return (scene);
}
