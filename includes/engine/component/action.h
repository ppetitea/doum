/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 23:06:52 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/06 22:41:58 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_H
# define ACTION_H

# include <SDL_keycode.h>
# include "utils/parser.h"
# include "containers/list.h"

typedef enum	e_resource_type
{
	R_GAME,
	R_SCENE,
	R_MAP,
	R_CHARACTER,
	R_ENTITY,
	R_ENTITY_LIST,
	R_UNKNOW,
}				t_resource_type;

typedef enum	e_trigger_type
{
	BASIC_TRIGGER,
	KEY_BINDING,
}				t_trigger_type;

typedef struct	s_action_node
{
	t_list_head		node;
	t_trigger_type	trigger_type;
	t_resource_type	resource_type;
	void			*resource;
	t_dnon_object	*args;
	t_result		(*action)(void*, t_resource_type, t_dnon_object*);
}				t_action_node;

typedef struct	s_key_binding
{
	t_action_node	action;
	SDL_Keycode		key;
	t_bool			is_down;
}				t_key_binding;

t_result		trigger_actions(t_list_head *actions);
void			trigger_key_hold_bindings(t_list_head *bind_list);
void			trigger_key_bindings(t_list_head *bind_list, SDL_Keycode key);
void			active_key_hold_binding(t_list_head *bind_list,
					SDL_Keycode key);
void			disable_key_hold_binding(t_list_head *bind_list,
					SDL_Keycode key);

t_result		swap_scene(void *game, t_resource_type resource_type,
					t_dnon_object *args);
t_result		swap_map(void *game_resource, t_resource_type resource_type,
					t_dnon_object *args);
t_result		stop_game(void *game_resource, t_resource_type resource_type,
					t_dnon_object *args);
t_result		translate_camera(void *game_resource,
					t_resource_type resource_type, t_dnon_object *args);
t_result		translate_camera_horizon(void *game_resource,
					t_resource_type resource_type, t_dnon_object *args);
t_result		rotate_camera(void *game_resource,
					t_resource_type resource_type, t_dnon_object *args);
t_result		update_entity_texture(void *entity_resource,
					t_resource_type resource_type, t_dnon_object *args);
t_result		spawn_character(void *game_resource,
					t_resource_type resource_type, t_dnon_object *args);
t_result		entities_display_next(void *game_resource,
					t_resource_type resource_type, t_dnon_object *args);
t_result		orientate_characters_texture(void *game_resource,
					t_resource_type resource_type, t_dnon_object *args);


t_action_node	*init_new_action();
t_result		build_action_by_key(t_action_node *action,
					t_dnon_object *action_obj);
t_result		init_action_resource_type_by_key(t_action_node *action,
					t_dnon_object *action_obj);
t_key_binding	*init_new_key_binding();

#endif
