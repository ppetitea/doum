// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   texture.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2020/01/12 23:55:41 by ppetitea          #+#    #+#             */
// /*   Updated: 2020/01/17 23:07:54 by ppetitea         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "engine/resources/textures/texture.h"
// #include "engine/resources/resources.h"
// #include "utils/error.h"
// #include "libft.h"
// #include <sys/time.h>

// t_vec2i		get_texture_center(t_texture texture)
// {
// 	t_vec2i center;

// 	center.x = texture.offset.x + texture.size.x * 0.5;
// 	center.y = texture.offset.y + texture.size.y * 0.5;
// 	return (center);
// }

// t_texture_args	texture_args(char *name, t_vec2i offset, t_usize size,
// 					float delay_ms)
// {
// 	t_texture_args	ret;

// 	ret.name = name;
// 	ret.offset = offset;
// 	ret.size = size;
// 	ret.delay_ms = delay_ms;
// 	return (ret);
// }

// t_texture		*create_texture(t_texture_args args)
// {
// 	t_texture *self;

// 	if (!(self = (t_texture*)malloc(sizeof(t_texture))))
// 		return (throw_null("create_texture", "texture -> malloc failed"));
// 	if (!(self->pixels = (u_int32_t*)malloc(sizeof(u_int32_t)
// 		* args.size.x * args.size.y)))
// 		return (throw_null("create_texture", "pixels array -> malloc failed"));
// 	init_list_head(&self->node);
// 	self->name = ft_strdup(args.name);
// 	self->offset = args.offset;
// 	self->size = args.size;
// 	self->delay_ms = args.delay_ms;
// 	return (self);
// }

// static void		set_texture_pixel(t_texture *self, t_bitmap_texture bmp,
// 	t_usize i, t_usize j)
// {
// 	t_bgra	color;

// 	color.px = bmp.pixels[j.x + j.y * bmp.head.width];
// 	if (color.bgra.r == 0 && color.bgra.g >= 162 && color.bgra.b >= 232)
// 		color.bgra.a = 0;
// 	// printf("r %d ", color.bgra.r);
// 	// printf("g %d ", color.bgra.g);
// 	// printf("b %d ", color.bgra.b);
// 	// printf("a %d \n", color.bgra.a);
// 	self->pixels[i.x + i.y * self->size.x] = color.px;
// }

// t_texture		*create_texture_with_bmp(t_texture_args args,
// 	t_bitmap_texture bmp)
// {
// 	t_texture		*self;
// 	t_usize			i;
// 	t_usize			j;
// 	t_vec2f			scale;

// 	if (!(self = create_texture(args)))
// 		return (throw_null("create_texture_with_bmp", "create_texture failed"));
// 	scale.x = (float)bmp.head.width / (float)self->size.x;
// 	scale.y = (float)bmp.head.height / (float)self->size.y;
// 	i.y = 0;
// 	while (i.y < self->size.y)
// 	{
// 		i.x = 0;
// 		while (i.x < self->size.x)
// 		{
// 			j = ft_usize(i.x * scale.x, i.y * scale.y);
// 			set_texture_pixel(self, bmp, i, j);
// 			i.x++;
// 		}
// 		i.y++;
// 	}
// 	return (self);
// }

// t_texture		*create_texture_with_bmp_name(t_list_head *list, t_texture_args args)
// {
// 	t_bitmap_texture	*bmp;
// 	t_texture			*ret;
	
// 	if (!(bmp = get_image_by_name(list, args.name)))
// 		return (throw_null("create_texture_bmp_name", "get_image failed"));
// 	if (!(ret = create_texture_with_bmp(args, *bmp)))
// 		return (throw_null("create_texture_bmp_name", "creation failed"));
// 	return (ret);
// }

// t_result	add_texture(t_list_head *resources, t_texture **texture_list,
// 	t_texture_args args)
// {
// 	t_texture	*new;

// 	if (!(new = create_texture_with_bmp_name(resources, args)))
// 		return (throw_error("build texture", "create_texture failed"));
// 	if (*texture_list == NULL)
// 		*texture_list = new;
// 	else
// 		list_add_entry(&new->node, (t_list_head*)*texture_list);
// 	return (OK);
// }
