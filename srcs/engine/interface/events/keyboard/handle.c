/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:17:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/22 15:47:56 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/events/keyboard.h"
#include "engine/scenes/init_scene.h"
#include "utils/error.h"
#include <sys/time.h>

#include <stdio.h>

// unsigned int compute_delta_ms(struct timespec last, struct timespec time)
unsigned int compute_delta_ms(struct timeval last, struct timeval time)
{
	unsigned int	delta_ms;

	delta_ms = (time.tv_sec - last.tv_sec) * 1000;
	delta_ms += (time.tv_usec - last.tv_usec) / 1.0e3;
	// delta_ms += (time.tv_nsec - last.tv_nsec) / 1.0e6;
	// printf ("binding delta_ms %d\n", delta_ms);
	return (delta_ms);
}

void	trigger_key_hold_bindings(t_list_head *bind_list)
{
	t_list_head				*pos;
	t_list_head				*next;
	t_event_key_binding		*bind;
	t_entity_key_binding	*e_bind;
	
	pos = bind_list;
	next = pos->next;
	while ((pos = next) != bind_list)
	{
		next = next->next;
		bind = (t_event_key_binding*)pos;
		if (bind->is_down == TRUE)
		{
			if (bind->type == ENTITY)
			{
				e_bind = (t_entity_key_binding*)bind;
				e_bind->trigger(e_bind->entity_ref);
			}
			else if (bind->type == BASIC)
				bind->trigger();
		}
	}
}

void	trigger_key_bindings(t_list_head *bind_list, SDL_Keycode key)
{
	t_list_head				*pos;
	t_list_head				*next;
	t_event_key_binding		*bind;
	t_entity_key_binding	*e_bind;

	pos = bind_list;
	next = pos->next;
	while ((pos = next) != bind_list)
	{
		next = next->next;
		bind = (t_event_key_binding*)pos;
		if (bind->key == key)
		{
			if (bind->type == ENTITY)
			{
				e_bind = (t_entity_key_binding*)bind;
				e_bind->trigger(e_bind->entity_ref);
			}
			else if (bind->type == BASIC)
				bind->trigger();
		}
	}
}

void	active_key_hold_binding(t_list_head *bind_list, SDL_Keycode key)
{
	t_list_head				*pos;
	t_list_head				*next;
	t_event_key_binding		*bind;

	pos = bind_list;
	next = pos->next;
	while ((pos = next) != bind_list)
	{
		next = next->next;
		bind = (t_event_key_binding*)pos;
		if (bind->key == key)
			bind->is_down = TRUE;
	}
}
void	disable_key_hold_bindings(t_list_head *bind_list, SDL_Keycode key)
{
	t_list_head			*pos;
	t_list_head			*next;
	t_event_key_binding	*bind;

	pos = bind_list;
	next = pos->next;
	while ((pos = next) != bind_list)
	{
		next = next->next;
		bind = (t_event_key_binding*)pos;
		if (bind->key == key)
			bind->is_down = FALSE;
	}
}

void	handle_keyboard_down(t_scene *scene, SDL_Keycode key)
{
	// if (key == SDLK_ESCAPE)
	// 	scene->is_running = FALSE;
	trigger_key_bindings(&scene->interface.key_binds, key);
	active_key_hold_binding(&scene->interface.key_hold_binds, key);
	(void)scene;
}

void	handle_keyboard_up(t_scene *scene, SDL_Keycode key)
{
	disable_key_hold_bindings(&scene->interface.key_hold_binds, key);
	(void)scene;
	(void)key;
}

t_result	init_bind_key(t_event_key_binding *bind, SDL_Keycode key,
				t_result (*trigger)(), t_key_bind_type type)
{
	if (bind == NULL || (type == BASIC && trigger == NULL))
		return (throw_error("bind_key", "NULL pointer provided"));
	init_list_head(&bind->node);
	bind->type = type;
	bind->key = key;
	bind->trigger = trigger;
	bind->delay = 20;
	gettimeofday(&bind->last, NULL);
	// timespec_get(&bind->last, TIME_UTC);
	return (OK);
}

t_result	new_bind_key(t_list_head *bind_list, SDL_Keycode key,
				t_result (*trigger)())
{
	t_event_key_binding	*bind;

	if (bind_list == NULL || trigger == NULL)
		return (throw_error("bind_key", "NULL pointer provided"));
	if (!(bind = (t_event_key_binding*)malloc(sizeof(t_event_key_binding))))
		return (throw_error("bind_key", "malloc failed"));
	init_bind_key(bind, key, trigger, BASIC);
	list_add_entry(&bind->node, bind_list);
	return (OK);
}
t_result	new_entity_bind_key(t_list_head *bind_list, SDL_Keycode key,
				t_entity *entity_ref, t_result (*trigger)(t_entity*))
{
	t_entity_key_binding	*bind;

	if (bind_list == NULL || trigger == NULL)
		return (throw_error("bind_key", "NULL pointer provided"));
	if (!(bind = (t_entity_key_binding*)malloc(sizeof(t_entity_key_binding))))
		return (throw_error("bind_key", "malloc failed"));
	init_bind_key(&bind->bind, key, NULL, ENTITY);
	bind->entity_ref = entity_ref;
	bind->trigger = trigger;
	list_add_entry(&bind->bind.node, bind_list);
	return (OK);
}

t_result	unbind_key(t_event_key_binding *bind)
{
	if (bind == NULL)
		return (throw_error("bind_key", "NULL pointer provided"));
	list_del_entry(&bind->node);
	free(bind);
	return (OK);
}

t_result	unbind_entity_key(t_entity_key_binding *bind)
{
	if (bind == NULL)
		return (throw_error("bind_key", "NULL pointer provided"));
	list_del_entry(&bind->bind.node);
	free(bind);
	return (OK);
}