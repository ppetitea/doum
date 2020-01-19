/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 02:14:48 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/19 21:27:12 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/mem.h"
#include "types.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	t_u8	*s1_byte;
	t_u8	*s2_byte;
	int		diff;

	s1_byte = (t_u8*)s1;
	s2_byte = (t_u8*)s2;
	while (n--)
		if ((diff = *(s1_byte++) - *(s2_byte++)))
			return (diff);
	return (0);
}
