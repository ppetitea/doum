/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2f_is_equal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:52:53 by ppetitea          #+#    #+#             */
/*   Updated: 2019/11/26 14:00:19 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"maths/vec2f.h"
#include	"types.h"

t_bool is_pos2f_equal(t_pos2f p1, t_pos2f p2)
{
	if (p1.x == p2.x && p1.y == p2.y)
		return (TRUE);
	return (FALSE);
}