/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:15:15 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/27 14:00:12 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# include "engine/scene/scene_init.h"
# include "SDL.h"
# include "libft.h"

void	handle_mouse_motion(t_scene *scene, SDL_MouseMotionEvent event);
void	handle_mouse_down(t_scene *scene, SDL_MouseButtonEvent event);
void	handle_mouse_up(t_scene *scene, SDL_MouseButtonEvent event);

#endif