/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:18:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 20:58:19 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/game.h"
#include "scenes/init.h"
#include "utils/error.h"
#include "libft.h"

t_game	*init_game()
{
	t_game		*game;
	t_usize 	window;
	
	window = ft_usize(640, 480);
	if (!(game = build_game(window)))
		return (throw_null("init_game", "build_game failed"));
	if (!init_scenes(game))
		return (throw_null("init_game", "init_scenes failed"));
	return (game);
}