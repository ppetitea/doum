/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:04:35 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 17:42:06 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors/rgb.h"

t_rgb	ft_rgb(t_u8 r, t_u8 g, t_u8 b)
{
	t_rgb	ret;

	ret.r = r;
	ret.g = g;
	ret.b = b;
	return (ret);
}