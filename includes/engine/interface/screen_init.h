/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_init.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:27:11 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/02 05:29:20 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_INIT_H
# define SCREEN_INIT_H

# include "libft.h"
# include "SDL.h"

typedef struct			s_screen
{
	t_usize				size;
	uint32_t			*pixels;
}						t_screen;

t_result	init_screen(t_screen *self, t_usize window_size);
void		reset_screen(t_screen screen);
t_screen	*game_screen();

#endif