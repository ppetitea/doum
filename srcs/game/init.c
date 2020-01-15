/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:36:09 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 04:59:44 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game.h"
#include "interface/screen.h"
#include "interface/sdl_init.h"
#include "utils/error.h"
#include "entities/entities.h"
#include "resources/resources.h"
#include "entities/sprites/sprites.h"

static void	initialize_mouse_state(t_mouse *mouse)
{
	mouse->down = FALSE;
	mouse->drag = FALSE;
}

static void	initialize_renderer(t_game *game)
{
	init_list_head(&game->renderer.sprites);
	init_list_head(&game->renderer.ui_components);
}

t_game	*initialize_game()
{
	t_game	*self;
	t_usize	size;

	size = ft_usize(640, 480);
	if (!(self = (t_game*)malloc(sizeof(t_game))))
		return(throw_null("initialize_game", "malloc failed"));
	if (!(initialize_sdl(&self->interface.sdl, size.x, size.y)))
		return(throw_null("initialize_game", "sdl initialization failed"));
	if (!initialize_screen(&self->interface.screen, size.x, size.y))
		return(throw_null("initialize_game", "screen initialization failed"));
	initialize_renderer(self);
	init_list_head(&self->resources.images);
	initialize_images_list(self);
	init_list_head(&self->entities.ui_components);
	init_list_head(&self->entities.sprites);
	initialize_entities(self);
	initialize_mouse_state(&self->interface.mouse);
	self->is_running = FALSE;
	return (self);
}
