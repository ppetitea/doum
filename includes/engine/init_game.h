/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:52:07 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 21:49:48 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_GAME_H
# define INIT_GAME_H

# include "engine/interface/init_screen.h"
# include "engine/interface/init_sdl.h"
# include "scenes/init_scene.h"
# include "libft.h"

typedef struct			s_game
{
	t_sdl				sdl;
	t_screen			screen;
	t_list_head			scenes;
	t_scene				*curr_scene;
	t_bool				is_running;
}						t_game;

t_game					*init_new_game();

#endif
