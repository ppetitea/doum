/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2f.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:19:45 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/17 06:06:32 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

#ifndef VEC2F_H
# define VEC2F_H

/*
** Two-dimensional float vector
*/
typedef struct	s_vec2f
{
	float	x;
	float	y;
}				t_vec2f;

#define t_pos2f t_vec2f

/*
** Constructors
*/
t_vec2f			ft_vec2f(float x, float y);
#define 		ft_pos2f ft_vec2f

/*
** Operations
*/
t_vec2f			vec2f_opposite(t_vec2f v);
t_vec2f			vec2f_add(t_vec2f a, t_vec2f b);
t_vec2f			vec2f_sub(t_vec2f a, t_vec2f b);
float			vec2f_dot(t_vec2f a, t_vec2f b);
t_vec2f			vec2f_scalar(t_vec2f src, float a);
float			vec2f_magnitude(t_vec2f v);
t_vec2f			vec2f_normalize(t_vec2f v);
t_bool			is_pos2f_equal(t_pos2f p1, t_pos2f p2);


#endif
