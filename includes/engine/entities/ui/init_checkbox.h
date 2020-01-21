/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_checkbox.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:12:43 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 22:47:06 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_CHECKBOX
# define INIT_CHECKBOX

# include "engine/resources/textures/texture.h"
# include "engine/entities/init_entity.h"

/*
**	Entite de type checkbox
**	Toggle une action lorsqu'on clique dessus
*/

typedef struct		s_checkbox
{
	t_entity		super;
	t_texture		normal;
	t_texture		hover;
	t_texture		checked;
}					t_checkbox;

t_checkbox			*init_new_checkbox();
t_result			init_checkbox_textures(
						t_checkbox *self,
						t_bitmap_texture hover,
						t_bitmap_texture checked,
						t_usize size);
t_result			overwrite_checkbox_textures_offset(t_checkbox *self,
						t_vec2i offset);
t_result			overwrite_checkbox_entity_texture(t_entity_texture *self,
						t_texture *texture, t_vec2i	anchor);
t_result			overwrite_checkbox_entity_listener(
						t_entity *self,
						t_list_head *render,
						t_list_head *storage,
						t_bool display);
t_result			overwrite_checkbox_entity_actions(t_entity_actions *self,
						t_result (*toggle_action)(t_entity*));

#endif