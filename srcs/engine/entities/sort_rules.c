/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 07:46:02 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/22 09:29:21 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/init_entity.h"
#include "engine/entities/sprites/init_ennemy.h"
#include "utils/error.h"

t_bool	sprite_distance_rule(t_list_head *pos, t_list_head *next)
{
	t_ennemy	*e1;
	t_ennemy	*e2;
	t_vec2f		d1;
	t_vec2f		d2;

	e1 = (t_ennemy*)pos;
	e2 = (t_ennemy*)next;
	d1.x = e1->super.pos.x - e1->player_ref->super.pos.x;
	d1.y = e1->super.pos.y - e1->player_ref->super.pos.y;
	d2.x = e2->super.pos.x - e2->player_ref->super.pos.x;
	d2.y = e2->super.pos.y - e2->player_ref->super.pos.y;
	return (d1.x * d1.x + d1.y * d1.y < d2.x * d2.x + d2.y * d2.y);
}
