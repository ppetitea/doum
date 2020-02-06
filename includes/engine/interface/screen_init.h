/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_init.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:27:11 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/06 18:50:48 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_INIT_H
# define SCREEN_INIT_H

# include "sizes/usize.h"
# include "types.h"

typedef struct			s_screen
{
	t_usize	size;
	t_u32	*pixels;
}						t_screen;

t_result	init_screen(t_screen *self, t_usize window_size);
void		reset_screen(t_screen screen);
t_screen	*game_screen();

#endif