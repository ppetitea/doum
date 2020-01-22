/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:36:09 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 23:22:41 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/init_screen.h"
#include "engine/init_game.h"
#include "utils/error.h"
#include "libft.h"
#include "build.h"

t_result	destroy_game()
{
	t_game	*game;

	game = game_singleton(NULL);
	game->is_running = FALSE;
	return (OK);
}
