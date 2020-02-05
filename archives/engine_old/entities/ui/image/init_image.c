/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:57:16 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 06:20:37 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/ui/init_image.h"
#include "engine/entities/init_entity.h"
#include "utils/error.h"
#include "libft.h"

t_image	*init_new_image()
{
	t_image	*self;

	if (!(self = (t_image*)malloc(sizeof(t_image))))
		return (throw_null("init_image", "malloc failed"));
	if (!init_entity(&self->super, IMAGE))
		return (throw_null("init_image", "init entity failed"));
	self->texture.pixels = NULL;
	return (self);
}

t_result	init_image_textures(t_image *self, t_bitmap_texture texture,
				t_usize size)
{
	if (self == NULL)
		return (throw_error("init_image_textures", "NULL pointer provided"));
	if (!init_texture(&self->texture, size))
		return (throw_error("init_image_textures", "normal texture failed"));
	if (!fill_texture_with_bmp(&self->texture, &texture))
		return (throw_error("init_image_textures", "fill texture failed"));
	return (OK);
}
