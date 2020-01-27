/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:01:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/25 02:11:52 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/parser.h"
#include "utils/error.h"
#include <stdlib.h>

t_bool		strcmp_obj(char *key, char *value, t_dnon_object *obj)
{
	t_bool	ret;
	char	*object_value;
	
	ret = FALSE;
	if (key == NULL || value == NULL || obj == NULL)
		return (throw_warning_false("strcmp_obj", "NULL pointer provided", 3));
	else
	{
		if (!(object_value = get_string_value_by_key(obj, key, NULL)))
			return (throw_warning_false("strcmp_obj", "string key not found", 3));
		if (!ft_strcmp(value, object_value))
			ret = TRUE;
		free(object_value);
	}
	return (ret);
}