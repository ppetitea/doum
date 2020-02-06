/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:55:41 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/06 18:53:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/resource/image/texture_init.h"
#include "utils/error.h"
#include "libft.h"

t_result	init_texture(t_texture *self, t_usize size)
{
	if (self == NULL)
		return (throw_error("init_texture", "NULL pointer provided"));
	if (!(self->pixels = (t_u32*)malloc(sizeof(t_u32)
		* size.x * size.y)))
		return (throw_error("init_texture", "pixels array -> malloc failed"));
	init_list_head(&self->node);
	self->offset = ft_vec2i(0, 0);
	self->size = size;
	self->delay_ms = 50;
	return (OK);
}

t_result	init_oriented_textures(t_oriented_textures *self)
{
	if (self == NULL)
		return (throw_error("init_oriented_textures", "NULL pointer"));
	init_list_head(&self->front);
	init_list_head(&self->front_l);
	init_list_head(&self->front_r);
	init_list_head(&self->left);
	init_list_head(&self->right);
	init_list_head(&self->back);
	init_list_head(&self->back_l);
	init_list_head(&self->back_r);
	return (OK);
}

t_texture		*init_new_texture(t_usize size)
{
	t_texture *self;

	if (!(self = (t_texture*)malloc(sizeof(t_texture))))
		return (throw_null("new_texture", "texture -> malloc failed"));
	if (!(self->pixels = (t_u32*)malloc(sizeof(t_u32)
		* size.x * size.y)))
		return (throw_null("new_texture", "pixels array -> malloc failed"));
	init_list_head(&self->node);
	self->offset = ft_vec2i(0, 0);
	self->size = size;
	self->delay_ms = 50;
	return (self);
}

t_result		overwrite_texture_params(t_texture *self, t_vec2i offset,
					uint32_t delay_ms)
{
	if (self == NULL)
		return (throw_error("overwrite_texture_p", "NULL pointer provided"));
	self->delay_ms = delay_ms;
	self->offset = offset;
	return (OK);
}
