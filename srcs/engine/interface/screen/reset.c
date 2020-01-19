/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:24:16 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 19:09:46 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/init_screen.h"

void	reset_screen(t_screen screen)
{
	ft_memset(screen.pixels, 0x00000000, sizeof(uint32_t) *
			screen.size.x * screen.size.y);
}