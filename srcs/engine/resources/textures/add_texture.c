/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:55:41 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 06:09:38 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resources/textures/texture.h"
#include "engine/resources/resources.h"
#include "utils/error.h"
#include "libft.h"

#include <stdio.h>

t_result	add_texture(t_list_head *textures, t_list_head *bmp_src,
				char *name, t_texture_args args)
{
	t_image_node		*img;
	t_list_head			*pos;
	t_list_head			*next;
	t_texture			*texture;

	if (textures == NULL || bmp_src == NULL || name == NULL)
		return (throw_error("add_texture", "NULL pointer provided"));
	pos = bmp_src;
	next = pos->next;
	while ((pos = next) != bmp_src)
	{
		next = next->next;
		img = (t_image_node*)pos;
		// printf("img name '%s' -> ", img->name);
		// printf("search '%s'-> ", name);
		// printf("diff '%d'\n", ft_strcmp(img->name, name));
		if (!ft_strcmp(img->name, name))
		{
			if (!(texture = init_new_texture(args.size)))
				return (throw_error("add_texture", "build_texture failed"));
			overwrite_texture_params(texture, args.offset, args.delay_ms);
			if (!fill_texture_with_bmp(texture, img->image))
				return (throw_error("add_texture", "fill_texture failed"));
			list_add_entry(&texture->node, textures);
			return (OK);
		}
	}
	return (throw_error("add_texture", "error 404 not found"));
}
