/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_vtx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 11:44:43 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/17 16:47:53 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/matrix.h"

t_pos2f    to_vtx(t_matrix m, t_vec2f vtx)
{
    t_pos2f ret;

    ret.x = m.x[0] * vtx.x + m.x[1] * vtx.y + m.x[2] * 1;
    ret.y = m.y[0] * vtx.x + m.y[1] * vtx.y + m.y[2] * 1;
    return ret;
}