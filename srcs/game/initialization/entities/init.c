/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:33:04 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/17 23:27:41 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "utils/error.h"
#include "libft.h"

t_result	initialize_entities(t_game *game)
{
	t_player *player;
	
	initialize_buttons_entities(game);
	initialize_spawners_entities(game);
	initialize_sprites_entities(game);
	player = initialize_player(game);
	initialize_ennemy(game, player);
	return (OK);
}