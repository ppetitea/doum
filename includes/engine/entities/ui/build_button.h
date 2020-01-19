/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_button.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:12:43 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 01:08:27 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_BUTTON_H
# define BUILD_BUTTON_H

# include "engine/resources/textures/texture.h"
# include "engine/entities/build_entity.h"

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

t_button			*build_button();
t_result			build_button_textures(
						t_button *self,
						t_bitmap_texture hover,
						t_bitmap_texture select,
						t_usize size);
t_result			build_button_entity_texture(t_entity_texture *self,
						t_texture *texture, t_vec2i	anchor);
t_result			build_button_entity_listener(
						t_entity *self,
						t_list_head *render,
						t_list_head *storage,
						t_bool display);

#endif