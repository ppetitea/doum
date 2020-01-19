/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:15:15 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 00:34:56 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H

# include "engine/scenes/init_scene.h"
# include "engine/entities/init_entity.h"

typedef struct		s_event_key_binding
{
	t_list_head		node;
	SDL_Keycode		key;
	t_bool			is_down;
	t_entity		*entity_ref;
	t_result		(*trigger)(t_entity*);
}					t_event_key_binding;

void		trigger_keys_bindings(t_scene *scene);
void		active_key_binding(t_scene *scene, SDL_Keycode key);
void		disable_key_binding(t_scene *scene, SDL_Keycode key);

t_result	bind_key(t_list_head *key_bindings, SDL_Keycode key,
				t_entity *entity_ref, t_result (*trigger)(t_entity*));
t_result	unbind_key(t_event_key_binding *bind);
void		handle_keyboard_down(t_scene *scene, SDL_Keycode key);
void		handle_keyboard_up(t_scene *scene, SDL_Keycode key);

#endif