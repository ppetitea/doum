/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:52:07 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/25 01:31:22 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_GAME_H
# define INIT_GAME_H

# include "engine/interface/screen_init.h"
# include "engine/interface/sdl_init.h"
# include "engine/map/init_map.h"
# include "scenes/init_scene.h"
# include "libft.h"

typedef struct			s_game_resources
{
	t_list_head			images;
	t_list_head			songs;
	t_list_head			entities;
	t_list_head			donjon_maps;
	t_list_head			voxel_maps;
	t_list_head			scenes;
}						t_game_resources;

typedef struct			s_game_interface
{
	t_sdl				sdl;
	t_screen			screen;
}						t_game_interface;

typedef struct			s_game
{
	t_game_interface	interface;
	t_game_resources	resources;
	t_scene				*curr_scene;
	t_map				*curr_map;
	t_bool				is_running;
}						t_game;

t_game					*init_new_game();
t_game					*game_singleton(t_game *init);


#endif