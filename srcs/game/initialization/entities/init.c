/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:33:04 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/16 06:43:56 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "entities/ui/button.h"
#include "entities/ui/spawner.h"
#include "resources/textures/bitmap.h"
#include "resources/textures/texture.h"
#include "resources/resources.h"
#include "entities/player.h"
#include "utils/error.h"
#include "libft.h"

t_result	initialize_entities(t_game *game)
{
	initialize_buttons_entities(game);
	initialize_spawners_entities(game);
	initialize_sprites_entities(game);
	initialize_player(game);
	return (OK);
}