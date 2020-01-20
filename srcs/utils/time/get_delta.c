/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_delta.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 01:39:07 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 02:00:45 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

unsigned int	get_delta(struct timespec last)
{
	unsigned int delta_ms;
	struct timespec	time;

	timespec_get(&time, TIME_UTC);
	delta_ms = (time.tv_sec - last.tv_sec) * 1000;
	delta_ms += ((time.tv_nsec / 10e5) - (last.tv_nsec / 10e5));
	return (delta_ms);
}