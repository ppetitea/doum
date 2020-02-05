/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 20:45:31 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/24 20:02:25 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/parser.h"
#include "utils/error.h"

char		*get_string_value_by_key(t_dnon_object *tree, char *key,
				char *by_default)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_dnon_object	*child;

	if (tree == NULL || key == NULL)
	{
		// throw_warning("get_float_value", "NULL pointer provided");
		return (by_default);
	}
	if (tree->type != LIST)
		return (by_default); /// malloc the default value here ?
	pos = (t_list_head*)tree->value;
	next = pos->next;
	while ((pos = next) != (t_list_head*)tree->value)
	{
		next = next->next;
		child = (t_dnon_object*)pos;
		if (!ft_strcmp(child->key, key) && child->type == STRING)
			return (ft_strdup((char*)child->value));
			// return a duplicata of value ? to avoid free issues
	}
	return (by_default);
}