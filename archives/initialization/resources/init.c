/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 22:26:15 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 20:52:53 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/resources/textures/texture.h"
#include "engine/resources/resources.h"
#include "utils/error.h"
#include "libft.h"


// t_result	initialize_images_list(t_game *game)
// {
// 	if (!load_pistol_textures(game))
// 		return (throw_error("initialize_images_list", "failed to load pistol"));
// 	if (!load_shotgun_textures(game))
// 		return (throw_error("initialize_images_list", "failed to load shotgun"));
// 	if (!load_button_textures(game))
// 		return (throw_error("initialize_images_list", "failed to load button"));
// 	if (!load_ennemy_textures(game))
// 		return (throw_error("initialize_images_list", "failed to load ennemy"));
// 	return (OK);
// }