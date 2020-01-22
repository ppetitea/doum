/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_image.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:12:43 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 23:36:57 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_IMAGE_H
# define BUILD_IMAGE_H

# include "engine/entities/ui/init_image.h"
# include "engine/scenes/init_scene.h"
# include "utils/parser.h"

t_result	build_image(t_scene *scene, t_dnon_object *image_obj);
t_result	build_image_texture(t_list_head *images, t_image *self,
				t_dnon_object *texture_obj);
#endif