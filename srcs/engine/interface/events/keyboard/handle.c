/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:17:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 02:38:17 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/events/keyboard.h"
#include "engine/scenes/init_scene.h"
#include "utils/error.h"
#include <time.h>

#include <stdio.h>

unsigned int compute_delta_ms(struct timespec last, struct timespec time)
{
	unsigned int	delta_ms;

	delta_ms = (time.tv_sec - last.tv_sec) * 1000;
	delta_ms += (time.tv_nsec - last.tv_nsec) / 1.0e6;
	// printf ("binding delta_ms %d\n", delta_ms);
	return (delta_ms);
}

void	trigger_key_hold_bindings(t_list_head *bind_list)
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
		if (bind->is_down == TRUE)
			bind->trigger(bind->entity_ref);
	}
}

void	trigger_key_bindings(t_list_head *bind_list, SDL_Keycode key)
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
			bind->trigger(bind->entity_ref);
	}
}

void	active_key_hold_binding(t_list_head *bind_list, SDL_Keycode key)
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

t_result	bind_key(t_list_head *bind_list, SDL_Keycode key,
				t_entity *entity_ref, t_result (*trigger)(t_entity*))
{
	t_event_key_binding	*bind;

	if (bind_list == NULL || entity_ref == NULL || trigger == NULL)
		return (throw_error("bind_key", "NULL pointer provided"));
	if (!(bind = (t_event_key_binding*)malloc(sizeof(t_event_key_binding))))
		return (throw_error("bind_key", "malloc failed"));
	init_list_head(&bind->node);
	bind->key = key;
	bind->entity_ref = entity_ref;
	bind->trigger = trigger;
	bind->delay = 20;
	timespec_get(&bind->last, TIME_UTC);
	list_add_entry(&bind->node, bind_list);
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
