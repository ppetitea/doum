/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 23:50:37 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/08 13:59:15 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/sdl_init.h"
#include "utils/error.h"
#include "SDL.h"

t_result	init_sdl(t_sdl *self, size_t width, size_t height)
{
	if (!self)
		return (throw_error("build_sdl", "NULL pointer provided"));
	if (SDL_Init(SDL_INIT_VIDEO) == SDL_ERROR)
		return (throw_error("build_sdl", "SDL_Init() failed"));
	if (!(self->window = SDL_CreateWindow("DOUM", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN)))
		return (throw_error("build_sdl", "SDL_CreateWindow() failed"));
	if (!(self->renderer = SDL_CreateRenderer(self->window, -1,
		SDL_RENDERER_SOFTWARE)))
		return (throw_error("build_sdl", "SDL_CreateRenderer() failed"));
	SDL_SetRenderDrawBlendMode(self->renderer, SDL_BLENDMODE_ADD);
	if (!(self->texture =  SDL_CreateTexture(self->renderer,
		SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, width, height)))
		return (throw_error("build_sdl", "SDL_CreateTexture() failed"));
	SDL_SetTextureBlendMode(self->texture, SDL_BLENDMODE_ADD);
	return (OK);
}