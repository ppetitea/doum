/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2f_opposite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:29:38 by ppetitea          #+#    #+#             */
/*   Updated: 2019/12/17 06:06:52 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec2f.h"
#include <math.h>

t_vec2f	vec2f_opposite(t_vec2f v)
{
	return (ft_vec2f(-v.x, -v.y));
}