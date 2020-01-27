/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:27:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/27 14:09:23 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_H
# define BUILD_H

# include "engine/resource/image/bitmap_list.h"
# include "engine/resource/image/texture_init.h"
# include "engine/entity/character_init.h"
# include "engine/game/game_init.h"
# include "utils/parser.h"
# include "utils/error.h"

/*
**	game
*/
t_game		*build();

/*
** resources
*/
t_result	build_textures_with_obj(t_list_head *images,
				t_list_head *list, t_dnon_object *textures_obj);
t_texture	*build_texture_with_obj(t_list_head *images,
				t_list_head *list, t_dnon_object *texture_obj);
t_result	build_oriented_textures(t_list_head *images,
				t_oriented_textures *textures, t_dnon_object *o_textures_obj);

/*
** entities
*/
t_result	build_game_entities(t_game_resources *resources,
				t_dnon_object *entities_obj);
t_result	build_new_entity_with_obj(t_game_resources *resources,
				t_dnon_object *ui_obj);
t_result	build_entity_with_obj(t_game_resources *resources,
				t_entity *entity, t_dnon_object *entity_obj);
t_result	build_entity_textures_with_obj(t_list_head *images,
				t_entity_texture *e_texture, t_dnon_object *e_texture_obj);
t_result	build_entity_animation_type_with_obj(t_entity_texture *e_texture,
				t_dnon_object *e_texture_obj);
t_result	build_entity_status_with_obj(t_listener *status,
				t_dnon_object *status_obj);
t_result	build_character_with_obj(t_game_resources *resources,
				t_dnon_object *char_obj);
void		build_character_type_with_obj(t_character *character,
				t_dnon_object *char_obj);
t_result	build_character_die_with_obj(t_game_resources *resources,
				t_character *character, t_dnon_object *die_obj);
t_result	build_character_weapons_with_obj(t_game_resources *resources,
				t_character *character, t_dnon_object *weapons_obj);
t_result	build_character_weapon_with_obj(t_game_resources *resources,
				t_character *character, t_dnon_object *weapon_obj);
t_result	build_character_weapon_textures(t_list_head *images,
				t_weapon *weapon, t_dnon_object *w_textures_obj);
t_result	build_point_of_view_textures(t_list_head *images,
				t_pov_textures *pov, t_dnon_object *pov_textures_obj);
t_result	build_weapon_type_with_obj(t_weapon *weapon,
				t_dnon_object *weapon_obj);
void		build_character_camera_with_obj(t_camera *self,
				t_dnon_object *camera_obj);

/*
**	maps
*/

t_result	build_game_resources_maps(t_game *game,
				t_dnon_object *maps_obj);
t_result	build_new_map_with_obj(t_game *game,
				t_dnon_object *map_obj);



/*
**	scenes
*/
// t_result	build_scenes(t_game *game, t_dnon_object *obj);
// t_scene		*build_menu_scene(t_game *game, t_dnon_object *scene_obj);
// t_scene		*init_map_editor_scene(t_game *game, t_dnon_object *scene_obj);
// t_scene		*build_game_scene(t_game *game, t_dnon_object *scene_obj);

// /*
// **		map editor
// */
// t_result	init_map_editor_interface(t_scene *scene);
// t_result	init_map_editor_resources(t_scene *scene);
// t_result	init_map_editor_entities(t_scene *scene);
// /*
// **			map editor resources
// */
// t_result	load_editor_button_down_images(t_list_head *images);
// t_result	load_editor_button_up_images(t_list_head *images);
// t_result	load_editor_button_plus_images(t_list_head *images);
// t_result	load_editor_button_x_images(t_list_head *images);
// /*
// **			map editor entities
// */
// t_result	init_map_editor_button_down(t_scene *scene);
// t_result	init_map_editor_button_up(t_scene *scene);
// t_result	init_map_editor_spawner_sprite(t_scene *scene);


// /*
// **	game
// */
// t_result	init_game_interface(t_scene *scene);
// t_result	init_game_resources(t_scene *scene);
// t_result	init_game_entities(t_scene *scene);
// /*
// **			game resources
// */
// t_result	load_pistol_images(t_list_head *images);
// t_result	load_shootgun_images(t_list_head *images);
// t_result	load_ennemy_images(t_list_head *images);
/*
**			game entities
*/
// t_player	*build_game_player(t_scene *scene);
// t_result	build_game_ennemy(t_scene *scene, t_player *player);



#endif