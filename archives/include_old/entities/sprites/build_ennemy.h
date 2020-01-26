/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ennemy.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 08:35:32 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/25 01:49:57 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUILD_ENNEMY_H
# define BUILD_ENNEMY_H

# include "libft.h"
# include "engine/resource/image/texture_init.h"
# include "engine/entities/init_entity.h"
# include "engine/entities/init_player.h"
# include "engine/entities/sprites/init_ennemy.h"
# include "engine/scenes/init_scene.h"
# include "utils/parser.h"

t_result	build_ennemy(t_scene *scene, t_dnon_object *ennemy_obj);


#endif
