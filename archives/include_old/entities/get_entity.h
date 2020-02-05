/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_entity.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:13:23 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/25 01:49:57 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_ENTITY_H
# define GET_ENTITY_H

# include "libft.h"
# include "engine/resource/image/texture_init.h"
# include "engine/entities/init_entity.h"
# include "engine/entities/update_entity.h"
# include "engine/scenes/init_scene.h"

t_entity	*get_entity(t_list_head *list, char *name);
t_entity	*get_entity_by_name(t_scene *scene, char *name);

#endif