/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:36:31 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/25 01:54:21 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resource/image/bitmap_parser.h"
#include "engine/resource/image/texture_init.h"
#include "utils/parser.h"
#include "utils/error.h"
#include "libft.h"
#include <stdlib.h>

#include <stdio.h>

static t_result		fill_pixels(FILE *file, uint32_t *pixels,
						int32_t width, int32_t height)
{
	t_rgba			color;
	int32_t			x;
	int32_t			y;

	if (file == NULL || pixels == NULL)
		return (throw_error("fill_pixels", "NULL pointer provided"));
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			fread(&color, 1, 3, file);
			pixels[x + (height - y - 1) * width] = color.px;
			color.rgba.a = 255;
			x++;
		}
		fseek(file, (x * 3) % 4, SEEK_CUR);
		y++;
	}
	return (OK);
}

t_bitmap_texture	*load_bmp(char *path)
{
	FILE				*file;
	t_bitmap_texture	*bmp;

	if (path == NULL)
		return (throw_null("load_bmp", "NULL pointer provided"));
	if (!(bmp = (t_bitmap_texture*)malloc(sizeof(t_bitmap_texture))))
		return (throw_null("load_bmp", "bmp texture -> malloc failed"));
	if (!(file = fopen(path, "rb")))
		return (throw_null("load_bmp", "wrong path provided"));
	fread(&bmp->head, sizeof(t_bitmap_header), 1, file);
	if (bmp->head.width % 2)
		bmp->head.width++;
	if (bmp->head.height % 2)
		bmp->head.height++;
	fseek(file, bmp->head.offset, SEEK_SET);
	if (bmp->head.type != 0x4d42)
		return (throw_null("load_bmp", "file provided is not a bmp"));
	if (!(bmp->pixels = (uint32_t*)malloc(sizeof(uint32_t)
		* bmp->head.width * bmp->head.height)))
		return (throw_null("load_bmp", "pixels array -> malloc failed"));
	if (!(fill_pixels(file, bmp->pixels, bmp->head.width, bmp->head.height)))
		return (throw_null("load_bmp", "bmp_to_pixel_array failed"));
	return (bmp);
}

t_result	resources_load_images(t_list_head *images, t_dnon_object *images_obj)
{
	t_list_head			*pos;
	t_list_head			*next;
	t_dnon_object		*child;
	t_bitmap_texture	*bmp;

	if (images == NULL || images_obj == NULL)
		return (throw_error("resources_load_images", "NULL pointer provided"));
	if (images_obj->type != LIST)
		return (throw_error("resources_load_images", "obj isn't list"));
	pos = (t_list_head*)images_obj->value;
	next = pos->next;
	while ((pos = next) != (t_list_head*)images_obj->value)
	{
		next = next->next;
		child = (t_dnon_object*)pos;
		if (child->type != STRING)
			return (throw_error("resources_load_images", "isn't string"));
		if (!(bmp = load_bmp(child->value)))
			return (throw_error("load_img", child->key));
		list_add_image(images, bmp, child->key);
	}
	return (OK);
}
