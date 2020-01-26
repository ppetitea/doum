/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_button.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:12:43 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 22:39:26 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_BUTTON_H
# define UPDATE_BUTTON_H

# include "engine/entities/ui/init_button.h"
# include "engine/entities/init_entity.h"

t_result	update_button_texture(t_entity *entity);
t_result	trigger_button_action(t_entity *button);


#endif