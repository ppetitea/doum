/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:16:02 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/22 17:22:06 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_MAP_H
# define INIT_MAP_H

# include "libft.h"
# include "engine/resources/resources.h"
# include "engine/resources/textures/bitmap.h"
# include "engine/resources/textures/texture.h"

typedef struct  s_map
{
    t_texture    map;
    t_texture    height_map;
}               t_map;

t_map           *init_new_map();
t_result        *build_map(t_scene *scene, )

#endif