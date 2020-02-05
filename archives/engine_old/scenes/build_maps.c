/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:18:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/23 17:36:24 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scenes/init_scene.h"
#include "engine/init_game.h"
#include "build.h"
#include "libft.h"
#include "utils/error.h"
#include "utils/parser.h"

t_result	build_maps(t_game *game, t_dnon_object *maps_obj)
{
	if (game == NULL || maps_obj == NULL)
		return (throw_error("build_maps", "NULL pointer provided"));

	return (OK);
}
