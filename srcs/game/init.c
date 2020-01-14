/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:36:09 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/14 00:31:55 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game/game.h"
#include "screen/screen.h"
#include "sdl/sdl_init.h"
#include "utils/error.h"
#include "user_interface/ui.h"
#include "textures/image_list.h"

static void	initialize_mouse_state(t_mouse_state *mouse)
{
	mouse->down = FALSE;
	mouse->drag = FALSE;
}

t_game	*initialize_game()
{
	t_game	*self;
	t_usize	size;

	size = ft_usize(640, 480);
	if (!(self = (t_game*)malloc(sizeof(t_game))))
		return(throw_null("initialize_game", "malloc failed"));
	if (!(initialize_sdl(&self->sdl, size.x, size.y)))
		return(throw_null("initialize_game", "sdl initialization failed"));
	if (!initialize_screen(&self->screen, size.x, size.y))
		return(throw_null("initialize_game", "screen initialization failed"));
	init_list_head(&self->images);
	initialize_images_list(self);
	init_list_head(&self->ui_components);
	initialize_user_interface(self);
	initialize_mouse_state(&self->mouse);
	self->is_running = FALSE;
	return (self);
}
