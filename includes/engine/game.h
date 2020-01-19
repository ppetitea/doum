/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:52:07 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 20:58:10 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_GAME_H
# define BUILD_GAME_H

# include "engine/interface/screen.h"
# include "engine/interface/sdl.h"
# include "libft.h"

typedef struct			s_game
{
	t_sdl				sdl;
	t_screen			screen;
	t_list_head			scenes;
	t_list_head			*curr_scene;
	t_bool				is_running;
}						t_game;

t_game					*build_game(t_usize window_size);
void					loop(t_game *game);
t_result				render(t_game *game);

#endif
