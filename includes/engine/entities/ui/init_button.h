/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_button.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:12:43 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/22 16:52:55 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_BUTTON_H
# define INIT_BUTTON_H

# include "engine/resources/textures/texture.h"
# include "engine/entities/init_entity.h"

/*
**	Entite de type button
**	Effectue une action lorsqu'on clique dessus
**	Change de texture lorsqu'on le survole ou le selectionne
*/

typedef struct		s_button
{
	t_entity		super;
	t_texture		normal;
	t_texture		hover;
	t_texture		selected;
	t_result		(*action)(t_entity*);
}					t_button;

typedef struct		s_button_display
{
	t_entity		super;
	t_texture		normal;
	t_texture		hover;
	t_texture		selected;
	t_result		(*action)(t_entity*);
}					t_button_display;

typedef struct		s_button_list_next
{
	t_entity		super;
	t_list_head		texture;
	size_t			offset;
	size_t			amount;
	t_bool			to_next;
	t_result		(*action)(t_entity*);
}					t_button_list_next;

typedef struct		s_button_specific
{
	t_entity		super;
	t_list_head		texture;
	t_result		(*action)();
}					t_button_specific;

t_button			*init_new_button();
t_result			init_button_textures(
						t_button *self,
						t_bitmap_texture hover,
						t_bitmap_texture select,
						t_usize size);
t_result			overwrite_button_entity_texture(t_entity_texture *self,
						t_texture *texture, t_vec2i	anchor);
t_result			overwrite_button_entity_listener(
						t_entity *self,
						t_list_head *render,
						t_list_head *storage,
						t_bool display);
t_result			overwrite_button_entity_actions(t_entity_actions *self);

#endif