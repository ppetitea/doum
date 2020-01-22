/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_child_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 20:45:31 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/22 03:07:41 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "utils/parser.h"
t_dnon_object	*get_child_list_object_by_key(t_dnon_object *tree, char *key)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_dnon_object	*child;

	if (tree == NULL || key == NULL)
		return (throw_null("get_child_list_object_by_key", "NULL pointer"));
	if (tree->type != LIST)
		return (throw_null("get_child_list_object_by_key",
			"must provide an object type list"));
	pos = (t_list_head*)tree->value;
	next = pos->next;
	while ((pos = next) != (t_list_head*)tree->value)
	{
		next = next->next;
		child = (t_dnon_object*)pos;
		if (!ft_strcmp(child->key, key) && child->type == LIST)
			return (child);
	}
	return (throw_null("get_child_lis_obj", key));
}

t_dnon_object	*get_child_object_by_key(t_dnon_object *tree, char *key)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_dnon_object	*child;

	if (tree->type != LIST)
		return (throw_null("get_child_object_by_key",
			"must provide an object type list"));
	pos = (t_list_head*)tree->value;
	next = pos->next;
	while ((pos = next) != (t_list_head*)tree->value)
	{
		next = next->next;
		child = (t_dnon_object*)pos;
		if (!ft_strcmp(child->key, key))
			return (child);
	}
	return (throw_null("get_child_object_by_key",
		"do not find the key"));
}