/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:55:41 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 05:12:56 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resources/textures/texture.h"
#include "engine/resources/resources.h"
#include "utils/error.h"
#include "libft.h"

t_result	init_texture(t_texture *self, char *name, t_usize size)
{
	if (self == NULL || name == NULL)
		return (throw_error("init_texture", "NULL pointer provided"));
	if (!(self->pixels = (uint32_t*)malloc(sizeof(uint32_t)
		* size.x * size.y)))
		return (throw_error("init_texture", "pixels array -> malloc failed"));
	self->name = NULL;
	if (!(self->name = ft_strdup(name)))
		return (throw_error("init_texture", "ft_strdup failed"));
	init_list_head(&self->node);
	self->offset = ft_vec2i(0, 0);
	self->size = size;
	self->delay_ms = 50;
	return (OK);
}

t_texture		*init_new_texture(char *name, t_usize size)
{
	t_texture *self;

	if (name == NULL)
		return (throw_null("new_texture", "NULL pointer provided"));
	if (!(self = (t_texture*)malloc(sizeof(t_texture))))
		return (throw_null("new_texture", "texture -> malloc failed"));
	if (!(self->pixels = (uint32_t*)malloc(sizeof(uint32_t)
		* size.x * size.y)))
		return (throw_null("new_texture", "pixels array -> malloc failed"));
	self->name = NULL;
	if (!(self->name = ft_strdup(name)))
		return (throw_null("new_texture", "ft_strdup failed"));
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
