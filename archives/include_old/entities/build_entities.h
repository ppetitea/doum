/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_entities.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:13:23 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 23:51:53 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_ENTITIES_H
# define BUILD_ENTITIES_H

# include "libft.h"
# include "engine/entities/init_entity.h"
# include "engine/scenes/init_scene.h"
# include "utils/parser.h"

t_result	build_entities(t_scene *scene, t_list_head *entities);
t_result	build_entity_by_type(t_scene *scene, t_dnon_object *entity_obj,
				char *entity_type);

#endif