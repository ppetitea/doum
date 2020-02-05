/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_delta.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 01:39:07 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/24 00:26:27 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdlib.h>

// unsigned int	get_delta(struct timespec last)
unsigned int	get_delta(struct timeval last)
{
	unsigned int delta_ms;
	// struct timespec	time;
	struct timeval	time;

	gettimeofday(&time, NULL);
	// timespec_get(&time, TIME_UTC);
	delta_ms = (time.tv_sec - last.tv_sec) * 1000;
	delta_ms += (time.tv_usec - last.tv_usec) / 1.0e3;
	// delta_ms += ((time.tv_nsec / 10e5) - (last.tv_nsec / 10e5));
	return (delta_ms);
}