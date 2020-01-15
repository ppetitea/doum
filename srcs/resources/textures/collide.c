/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:59:39 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 05:17:19 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "resources/textures/texture.h"

t_bool	is_texture_collide(t_texture self, t_vec2i pos, t_vec2i anchor)
{
	if (pos.x < self.offset.x + anchor.x ||
		pos.x > (int)self.size.x + self.offset.x + anchor.x)
		return (FALSE);
	if (pos.y < self.offset.y + anchor.y ||
		pos.y > (int)self.size.y + self.offset.y + anchor.y)
		return (FALSE);
	return (TRUE);
}