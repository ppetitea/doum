/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:36:09 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 18:03:38 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/init_screen.h"
#include "engine/init_game.h"
#include "utils/error.h"
#include "libft.h"
#include "init.h"

t_game	*game_singleton(t_game *init)
{
	static t_game *game = NULL;

	if (game == NULL && init == NULL)
		return (throw_null("game_singleton", "NULL pointer provided at init"));
	if (game == NULL)
		game = init;
	return (game);
}

t_game	*init_new_game(t_usize window_size)
{
	t_game	*self;

	if (!(self = (t_game*)malloc(sizeof(t_game))))
		return(throw_null("build_game", "malloc failed"));
	if (!(init_sdl(&self->sdl, window_size.x, window_size.y)))
		return(throw_null("build_game", "build_sdl failed"));
	if (!init_screen(&self->screen, window_size))
		return(throw_null("build_game", "screen initialization failed"));
	init_list_head(&self->scenes);
	self->is_running = FALSE;
	self->curr_scene = NULL;
	game_singleton(self);
	return (self);
}
