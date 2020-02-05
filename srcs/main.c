/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:59:39 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/28 15:39:51 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"
#include "utils/error.h"

int		main()
{
	t_game *game;

	// build();
	if ((game = build()) != NULL)
		loop(game);
	return (0);
}
