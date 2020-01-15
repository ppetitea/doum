/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:12:43 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 07:54:18 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTON_H
# define BUTTON_H

# include "game.h"
# include "entities/entities.h"
# include "resources/textures/texture.h"

/*
**	Entite de type button
**	Effectue une action lorsqu'on clique dessus
**	Change de texture lorsqu'on le survole ou le selectionne
*/

typedef struct		s_button
{
	t_entity		super;
	t_texture		*normal;
	t_texture		*hover;
	t_texture		*selected;
}					t_button;

t_button			*create_button(t_game *game, t_texture *hover,
						t_texture *selected, t_bool display);
t_result			update_button_anchor(t_entity *entity, t_vec2i anchor);
t_result			update_button_offset(t_entity *entity, t_vec2i offset);
t_result			update_button_texture_with_status(t_entity *entity);


#endif