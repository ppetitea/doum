/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:52:07 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/14 06:00:47 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "screen/screen.h"
# include "sdl/sdl_init.h"
# include "libft.h"

typedef struct			s_mouse_state
{
	t_bool	drag;
	t_bool	down;
}						t_mouse_state;

typedef struct			s_game
{
	t_bool				is_running;
	t_sdl				sdl;
	t_screen			screen;
	t_list_head			ui_components;
	t_list_head			images;
	t_list_head			sprites;
	t_mouse_state		mouse;
}						t_game;

t_game					*initialize_game();
void					loop(t_game *game);
t_result				render(t_game *game);

#endif