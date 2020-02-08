/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_delta_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:10:33 by lbenard           #+#    #+#             */
/*   Updated: 2020/02/08 19:15:10 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/time.h"

float	*get_delta_ptr(void)
{
	static float	delta = 0.0f;

	return (&delta);
}