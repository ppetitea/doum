/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:55:08 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 00:45:06 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef screen_H
# define screen_H

# include "libft.h"
# include "SDL.h"

typedef struct			s_screen
{
	t_usize				size;
	uint32_t			*pixels;
}						t_screen;

t_result	initialize_screen(t_screen *self, size_t width, size_t height);
void		reset_screen(t_screen screen);

#endif