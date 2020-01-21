/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:59:39 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 03:40:58 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "engine/update_game.h"

int		main()
{
	t_game *game;

	if ((game = init()) != NULL)
		loop(game);
	return (0);
}
