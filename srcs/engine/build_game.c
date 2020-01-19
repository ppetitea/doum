/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:36:09 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 15:53:05 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/screen.h"
#include "utils/error.h"
#include "libft.h"
#include "init.h"

t_game	*build_game(t_usize window_size)
{
	t_game	*self;

	if (!(self = (t_game*)malloc(sizeof(t_game))))
		return(throw_null("build_game", "malloc failed"));
	if (!(build_sdl(&self->sdl, window_size.x, window_size.y)))
		return(throw_null("build_game", "build_sdl failed"));
	if (!build_screen(&self->screen, window_size))
		return(throw_null("build_game", "screen initialization failed"));
	init_list_head(&self->scenes);
	self->is_running = FALSE;
	self->curr_scene = NULL;
	return (self);
}
