/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:15:15 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 06:59:10 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H

# include "game.h"
# include "entities/entities.h"

typedef struct		s_event_key_binding
{
	t_list_head		node;
	SDL_Keycode		key;
	t_entity		*entity_ref;
	t_result		(*trigger)(t_entity*);
}					t_event_key_binding;

t_result	bind_key(t_list_head *key_bindings, SDL_Keycode key,
				t_entity *entity_ref, t_result (*trigger)(t_entity*));
t_result	unbind_key(t_event_key_binding *bind);
void		handle_keyboard_down(t_game *game, SDL_Keycode key);
void		handle_keyboard_up(t_game *game, SDL_Keycode key);

#endif