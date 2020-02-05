/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 02:39:58 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 20:38:18 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "engine/entities/ui/init_image.h"

// t_result	update_image_texture(t_entity *entity)
// {
// 	t_image	*image;
// 	t_vec2i		curr_offset;
	
// 	if (entity->type != image)
// 		return (throw_error("update_image_offset",
// 			"entity provided is not a image"));
// 	curr_offset = entity->texture.curr->offset;
// 	image = (t_image*)entity;
// 	if (image->super.status.is_selected)
// 		image->super.texture.curr = &image->selected;
// 	else if (image->super.status.is_hover)
// 		image->super.texture.curr = &image->hover;
// 	else
// 		image->super.texture.curr = &image->normal;
// 	entity->texture.curr->offset = curr_offset;
// 	return (OK);
// }
