/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_blend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 02:30:17 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/14 23:04:52 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"utils/color.h"

u_int32_t	blend_add_average(t_rgba current, t_rgba old)
{
	t_rgba	new;

	new.rgba.r = (current.rgba.r + old.rgba.r) * 0.5f;
	new.rgba.g = (current.rgba.g + old.rgba.g) * 0.5f;
	new.rgba.b = (current.rgba.b + old.rgba.b) * 0.5f;
	new.rgba.a = (current.rgba.a + old.rgba.a) * 0.5f;
	return (new.px);
}

u_int32_t	blend_add(t_rgba curr, t_rgba old)
{
	t_rgba	new;
	float	curr_alpha;
	float	old_alpha;
	float	final_alpha;

	curr_alpha = (float)curr.rgba.a / 255.0f;
	old_alpha = (float)old.rgba.a / 255.0f;
	final_alpha = old_alpha + curr_alpha - old_alpha * curr_alpha;
	curr.rgba.r = curr.rgba.r * curr_alpha;
	curr.rgba.g = curr.rgba.g * curr_alpha;
	curr.rgba.b = curr.rgba.b * curr_alpha;
	old.rgba.r = old.rgba.r * old_alpha;
	old.rgba.g = old.rgba.g * old_alpha;
	old.rgba.b = old.rgba.b * old_alpha;
	new.rgba.r = (curr.rgba.r + old.rgba.r * (1 - curr_alpha)) / final_alpha;
	new.rgba.g = (curr.rgba.g + old.rgba.g * (1 - curr_alpha)) / final_alpha;
	new.rgba.b = (curr.rgba.b + old.rgba.b * (1 - curr_alpha)) / final_alpha;
	new.rgba.a = final_alpha * 255.0f;
	return (new.px);
}