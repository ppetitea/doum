/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_ennemy.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 08:35:32 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 02:20:37 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	UPDATE_ENNEMY_H
# define UPDATE_ENNEMY_H

# include "engine/entities/sprites/build_ennemy.h"

t_result	update_ennemy_texture_by_direction(t_ennemy *ennemy);
t_result	update_ennemy_texture(t_entity *entity);
t_result	ennemy_move_forward(t_entity *entity);
t_result	ennemy_move_backward(t_entity *entity);
t_result	ennemy_turn_right(t_entity *entity);
t_result	ennemy_turn_left(t_entity *entity);
t_result	ennemy_attack(t_entity *entity);
t_result	ennemy_die(t_entity *entity);

#endif
