/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:36:09 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 09:01:19 by ppetitea         ###   ########.fr       */
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

static void	initialize_game_interface(t_game_interface *interface)
{
	init_list_head(&interface->keys_bind);
	interface->mouse.drag = FALSE;
	interface->mouse.down = FALSE;
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
	init_list_head(&self->entities.ui_components);
	init_list_head(&self->entities.sprites);
	init_list_head(&self->resources.images);
	initialize_renderer(self);
	initialize_game_interface(&self->interface);
	initialize_images_list(self);
	initialize_entities(self);
	self->is_running = FALSE;
	return (self);
}
