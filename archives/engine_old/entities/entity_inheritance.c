/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_inheritance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:44:34 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/24 03:12:44 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/init_entity.h"
#include "engine/entities/update_entity.h"
#include "utils/error.h"
#include "libft.h"

t_result	entity_add_child(t_entity *parent, t_entity *child)
{
	t_entity_node	*entity_node;

	if (parent == NULL || child == NULL)
		return (throw_error("entity_add_child", "NULL pointer provided"));
	if (!(entity_node = (t_entity_node*)malloc(sizeof(t_entity_node))))
		return (throw_error("entity_add_child", "malloc failed"));
	init_list_head(&entity_node->node);
	child->parent = parent;
	entity_node->entity = child;
	list_add_entry(&entity_node->node, &parent->childs);
	return (OK);
}

t_entity_node	*entity_get_child_node(t_entity *parent, char *name)
{
	t_entity_node	*child;
	t_list_head		*pos;
	t_list_head		*next;
	
	child = NULL;
	pos = &parent->childs;
	next = pos->next;
	while ((pos = next) != &parent->childs)
	{
		next = next->next;
		child = (t_entity_node*)pos;
		if (!ft_strcmp(child->entity->name, name))
			return (child);
		if ((child = entity_get_child_node(child->entity, name)) != NULL)
			return (child);
	}
	return (throw_null("entity_get_child", "child not found"));
}

t_entity	*entity_get_child(t_entity *parent, char *name)
{
	t_entity_node *child_node;

	if (parent == NULL)
		return (throw_null("entity_get_child", "NULL pointer provided"));
	if (!(child_node = entity_get_child_node(parent, name)))
		return (throw_null("entity_get_child", "child not found"));
	return (child_node->entity);
}

t_entity	*entity_get_parent(t_entity *child, char *name)
{
	t_entity	*parent;
	
	if (child == NULL)
		return (throw_null("entity_get_parent", "NULL pointer provided"));
	parent = child;
	while ((parent = parent->parent) != NULL)
	{
		if (!ft_strcmp(parent->name, name))
			return (parent);
	}
	return (throw_null("entity_get_parent", "parent not found"));
}

t_result	remove_entity_node(t_entity_node *node)
{
	if (node == NULL)
		return (throw_error("remove_entity_node", "NULL pointer provided"));
	list_del_entry(&node->node);
	node->entity = NULL;
	free(node);
	return (OK);
}

t_result	entity_remove_child(t_entity *parent, char *name)
{
	t_entity_node	*child;

	if (parent == NULL)
		return (throw_error("entity_remove_child", "NULL pointer provided"));
	if (!(child = entity_get_child_node(parent, name)))
		return (throw_error("entity_remove_child", "child not found"));
	remove_entity_node(child);
	return (OK);
}

t_result	entity_remove_childs(t_entity *parent)
{
	t_entity_node	*child;
	t_list_head		*pos;
	t_list_head		*next;
	
	child = NULL;
	pos = &parent->childs;
	next = pos->next;
	while ((pos = next) != &parent->childs)
	{
		next = next->next;
		child = (t_entity_node*)pos;
		entity_remove_childs(child->entity);
		remove_entity_node(child);
	}
	return (throw_error("entity_get_child", "child not found"));
}
