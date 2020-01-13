/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 02:40:52 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/13 04:04:09 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DN_COLOR_H
# define DN_COLOR_H

# include "libft.h"

typedef struct		s_rgba_uchar
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}					t_rgba_uchar;

typedef union		u_rgba
{
	t_rgba_uchar	rgba;
	u_int32_t		px;
}					t_rgba;

typedef struct		s_argb_uchar
{
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_argb_uchar;

typedef union		u_argb
{
	t_argb_uchar	argb;
	u_int32_t		px;
}					t_argb;

u_int32_t	blend_add(t_rgba current, t_rgba old);
u_int32_t	blend_add_average(t_rgba current, t_rgba old);

#endif