/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:24:43 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 06:19:40 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resources/textures/texture.h"
#include "utils/color.h"
#include "utils/error.h"

t_result	texture_filter(t_texture *new, t_texture old, t_filter_type filter)
{
	t_usize			i;

	if (new == NULL)
		return (throw_error("texture_filter", "NULL pointer provided"));
	if (!(init_texture(new, old.size)))
		return (throw_error("hover_filter", "init_texture failed"));
	overwrite_texture_params(new, old.offset, old.delay_ms);
	i.y = 0;
	while (i.y < new->size.y)
	{
		i.x = 0;
		while (i.x < new->size.x)
		{
			if (filter == FILTER_HOVER)
				set_texture_pixel_circular_shadow(old, new, i);
			if (filter == FILTER_BLEND)
				set_texture_pixel_blend(old, new, i);
			if (filter == FILTER_NONE)
				set_texture_pixel(old, new, i);
			i.x++;
		}
		i.y++;
	}
	return (OK);
}

t_texture	*new_texture_filter(t_texture old, t_filter_type filter)
{
	t_texture 		*new;

	if (!(new = init_new_texture(old.size)))
		return (throw_null("hover_filter", "new_texture failed"));
	if (!texture_filter(new, old, filter))
		return (throw_null("hover_filter", "filter failed"));
	return (new);
}