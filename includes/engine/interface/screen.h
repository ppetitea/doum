/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:55:08 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 16:34:07 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

# include "libft.h"
# include "SDL.h"

typedef struct			s_screen
{
	t_usize				size;
	uint32_t			*pixels;
}						t_screen;

t_result	build_screen(t_screen *self, t_usize window_size);
void		reset_screen(t_screen screen);

#endif