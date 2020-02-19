/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_action.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:09:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/19 13:52:46 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_ACTION_H
# define CHARACTER_ACTION_H

# include "engine/entity/character_init.h"

void	character_die(t_character *self);
void	character_attack(t_character *self);
void	character_run(t_character *self);
void	character_jump(t_character *self);
void	character_crawl(t_character *self);

void	character_catch_weapon(t_character *self, char *name);
void	character_drop_weapon(t_character *self);
void	orientate_texture(t_character *c);
t_result	active_monster(t_character *monster, t_character *target);

#endif
