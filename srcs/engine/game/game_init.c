/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:36:09 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/29 02:29:43 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/screen_init.h"
#include "engine/game/game_init.h"
#include "utils/error.h"
#include "libft.h"
#include "build.h"

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
	if (!(init_sdl(&self->interface.sdl, window_size.x, window_size.y)))
		return(throw_null("build_game", "build_sdl failed"));
	if (!init_screen(&self->interface.screen, window_size))
		return(throw_null("build_game", "screen initialization failed"));
	self->interface.mouse.down = FALSE;
	self->interface.mouse.drag = FALSE;
	init_list_head(&self->resources.images);
	init_list_head(&self->resources.songs);
	init_list_head(&self->resources.entities);
	init_list_head(&self->resources.donjon_maps);
	init_list_head(&self->resources.voxel_maps);
	init_list_head(&self->resources.scenes);
	self->curr_scene = NULL;
	self->curr_map = NULL;
	self->is_running = FALSE;
	game_singleton(self);
	return (self);
}
