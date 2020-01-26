/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_entity.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:11:43 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/22 04:19:43 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/init_entity.h"
#include "engine/entities/update_entity.h"
#include "engine/scenes/init_scene.h"
#include "utils/error.h"
#include "utils/parser.h"

t_entity	*get_entity(t_list_head *list, char *name)
{
	t_list_head	*pos;
	t_list_head	*next;
	t_entity	*entity;
	
	if (list == NULL || name == NULL)
		return (throw_null("get_entity", "NULL pointer provided"));
	pos = list;
	next = pos->next;
	while ((pos = next) != list)
	{
		next = next->next;
		entity = (t_entity*)pos;
		if (!ft_strcmp(entity->name, name))
			return (entity);
	}
	return (NULL);
}

t_entity	*get_entity_by_name(t_scene *scene, char *name)
{
	t_entity *ret;

	if (name == NULL || scene == NULL)
		return (throw_null("get_entity_by_name", "NULL pointer provided"));
	if ((ret = get_entity(&scene->entities.ui_components, name)) != NULL)
		return (ret);
	if ((ret = get_entity(&scene->renderer.ui_components, name)) != NULL)
		return (ret);
	if ((ret = get_entity(&scene->entities.sprites, name)) != NULL)
		return (ret);
	if ((ret = get_entity(&scene->renderer.sprites, name)) != NULL)
		return (ret);
	return (throw_null("name", "entity not found"));
}
