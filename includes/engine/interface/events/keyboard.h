/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:15:15 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/27 13:59:52 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H

# include "engine/game/game_init.h"
# include "engine/scene/scene_init.h"
# include "engine/entity/entity_init.h"
# include <sys/time.h>

typedef	enum		s_key_bind_type
{
	BASIC,
	ENTITY,
	SCENE,
}					t_key_bind_type;

typedef struct		s_event_key_binding
{
	t_list_head		node;
	t_key_bind_type	type;
	SDL_Keycode		key;
	t_bool			is_down;
	// struct timespec	last;
	struct timeval	last;
	unsigned int	delay;
	t_result		(*trigger)();
}					t_event_key_binding;

typedef struct		s_entity_key_binding
{
	t_event_key_binding	bind;
	t_entity			*entity_ref;
	t_result			(*trigger)(t_entity*);
}					t_entity_key_binding;

typedef struct		s_scene_key_binding
{
	t_event_key_binding	bind;
	t_scene				*scene_ref;
	t_result			(*trigger)(t_scene*);
}					t_scene_key_binding;


void		trigger_key_hold_bindings(t_list_head *bind_list);
void		trigger_key_bindings(t_list_head *bind_list, SDL_Keycode key);
void		active_key_hold_binding(t_list_head *bind_list, SDL_Keycode key);
void		disable_key_hold_binding(t_list_head *bind_list, SDL_Keycode key);


t_result	init_bind_key(t_event_key_binding *bind, SDL_Keycode key,
				t_result (*trigger)(), t_key_bind_type type);
t_result	new_bind_key(t_list_head *bind_list, SDL_Keycode key,
				t_result (*trigger)());
t_result	new_entity_bind_key(t_list_head *bind_list, SDL_Keycode key,
				t_entity *entity_ref, t_result (*trigger)(t_entity*));
t_result	unbind_key(t_event_key_binding *bind);
t_result	unbind_entity_key(t_entity_key_binding *bind);

void		handle_keyboard_down(t_scene *scene, SDL_Keycode key);
void		handle_keyboard_up(t_scene *scene, SDL_Keycode key);

#endif