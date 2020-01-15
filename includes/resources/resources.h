/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 23:03:16 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 04:15:42 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOURCES_H
# define RESOURCES_H

# include "resources/textures/texture.h"
# include "game.h"
# include "libft.h"

typedef struct			s_image_node
{
	t_list_head			node;
	char				*name;
	t_bitmap_texture	*image;
}						t_image_node;

t_result			initialize_images_list(t_game *game);
t_result			list_add_image(t_game *game, t_bitmap_texture *image, char *name);
t_bitmap_texture	*get_image_by_name(t_game *game, char *name);
t_result			load_button_textures(t_game *game);
t_result			load_pistol_textures(t_game *game);
t_result			load_shotgun_textures(t_game *game);

#endif