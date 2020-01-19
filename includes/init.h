/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:27:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 23:56:44 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "engine/game.h"
# include "engine/entities/build_entity.h"
# include "engine/scenes/build_scene.h"

/*
**	game
*/
t_game		*init_game();


/*
**	scenes
*/
t_result	*init_scenes(t_game *game);
t_result	init_menu_scene(t_game *game);
t_result	init_map_editor_scene(t_game *game);
t_result	init_game_scene(t_game *game);

/*
**		menu
*/
t_result	init_menu_interface(t_scene *scene);
t_result	init_menu_resources(t_scene *scene);
t_result	init_menu_entities(t_scene *scene);
/*
**			menu resources
*/
t_result	load_menu_button_down_images(t_list_head *images);
/*
**			menu entities
*/
t_result	init_menu_button_start(t_scene *scene);


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
t_result	init_map_editor_spawner_exemple(t_scene *scene);


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
t_result	load_ennemy_images(t_game *game);
/*
**			game entities
*/



#endif