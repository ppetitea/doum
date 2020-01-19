/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:24:43 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 19:34:15 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resources/textures/texture.h"
#include "utils/color.h"
#include "utils/error.h"

t_texture	*texture_filter(t_texture old, t_filter_type filter)
{
	t_texture 		*new;
	t_usize			i;

	if (!(new = init_new_texture(old.name, old.size)))
		return (throw_null("hover_filter", "new_texture failed"));
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
	return (new);
}