/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_delta.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:09:38 by lbenard           #+#    #+#             */
/*   Updated: 2020/02/08 19:20:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/time.h"

void	set_delta(const float delta)
{
	*get_delta_ptr() = delta;
}
