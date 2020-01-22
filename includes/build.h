/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:27:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/22 00:58:28 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_H
# define BUILD_H

# include "engine/init_game.h"
# include "engine/entities/init_entity.h"
# include "engine/scenes/init_scene.h"
# include "engine/entities/init_player.h"
# include "engine/entities/ui/init_image.h"
# include "engine/resources/resources.h"
# include "engine/entities/ui/build_button.h"
# include "engine/entities/ui/build_image.h"
# include "engine/entities/build_entities.h"
# include "utils/parser.h"

/*
**	game
*/
t_game		*build();


/*
**	scenes
*/
t_result	build_scenes(t_game *game, t_dnon_object *obj);
t_scene		*build_menu_scene(t_game *game, t_dnon_object *scene_obj);
t_scene		*init_map_editor_scene(t_game *game, t_dnon_object *scene_obj);
t_scene		*build_game_scene(t_game *game, t_dnon_object *scene_obj);

/*
**		map editor
*/
t_result	init_map_editor_interface(t_scene *scene);
t_result	init_map_editor_resources(t_scene *scene);
t_result	init_map_editor_entities(t_scene *scene);
/*
**			map editor resources
*/
t_result	load_editor_button_down_images(t_list_head *images);
t_result	load_editor_button_up_images(t_list_head *images);
t_result	load_editor_button_plus_images(t_list_head *images);
t_result	load_editor_button_x_images(t_list_head *images);
/*
**			map editor entities
*/
t_result	init_map_editor_button_down(t_scene *scene);
t_result	init_map_editor_button_up(t_scene *scene);
t_result	init_map_editor_spawner_sprite(t_scene *scene);


/*
**	game
*/
t_result	init_game_interface(t_scene *scene);
t_result	init_game_resources(t_scene *scene);
t_result	init_game_entities(t_scene *scene);
/*
**			game resources
*/
t_result	load_pistol_images(t_list_head *images);
t_result	load_shootgun_images(t_list_head *images);
t_result	load_ennemy_images(t_list_head *images);
/*
**			game entities
*/
t_player	*build_game_player(t_scene *scene);
t_result	build_game_ennemy(t_scene *scene, t_player *player);



#endif