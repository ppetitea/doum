/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 23:51:42 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/14 15:27:31 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_INIT_H
# define SDL_INIT_H

# include <SDL_video.h>
# include <SDL_render.h>
# include <SDL_events.h>
# include <string.h>
# include "types.h"

# define SDL_OK 0
# define SDL_ERROR -1
# define NUM_CHAN 32

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	SDL_Event		event;
}					t_sdl;

t_result			init_sdl(t_sdl *self, size_t width, size_t height);

#endif