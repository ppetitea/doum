/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:52:07 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/17 16:29:58 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "interface/screen.h"
# include "interface/sdl_init.h"
# include "libft.h"

/*
** Listes des entites rendus a l'ecran
*/

typedef struct			s_game_renderer
{
	t_list_head			ui_components;
	t_list_head			sprites;
}						t_game_renderer;

/*
** Listes des entites du jeu
*/

typedef struct			s_game_entities
{
	t_list_head			ui_components;
	t_list_head			sprites;
}						t_game_entities;

/*
** Listes des resources du jeu
*/

typedef struct			s_game_resources
{
	t_list_head			images;
	t_list_head			songs;
}						t_game_resources;

/*
** Gestion de l'interface du jeu (fenetre, ecran, souris, clavier)
*/

typedef struct			s_mouse
{
	t_bool	drag;
	t_bool	down;
	t_vec2i	pos;
}						t_mouse;

typedef struct			s_game_interface
{
	t_sdl				sdl;
	t_screen			screen;
	t_mouse				mouse;
	t_list_head			keys_bind;
}						t_game_interface;

/*
** Instance de jeu
*/

typedef struct			s_game
{
	t_game_interface	interface;
	t_game_renderer		renderer;
	t_game_entities		entities;
	t_game_resources	resources;
	t_bool				is_running;
}						t_game;

t_game					*initialize_game();
void					loop(t_game *game);
t_result				render(t_game *game);

#endif