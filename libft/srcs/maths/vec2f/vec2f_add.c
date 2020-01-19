/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2f_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 01:00:06 by freezee           #+#    #+#             */
/*   Updated: 2019/12/17 23:54:02 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec2f.h"

t_vec2f	vec2f_add(t_vec2f a, t_vec2f b)
{
	return (ft_vec2f(a.x + b.x, a.y + b.y));
}