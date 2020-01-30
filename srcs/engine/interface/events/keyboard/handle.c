/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:17:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/30 12:33:07 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/events/keyboard.h"
#include "engine/scene/scene_init.h"
#include "engine/component/action.h"
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
	t_key_binding			*bind;
	
	pos = bind_list;
	while ((pos = pos->next) != bind_list)
	{
		bind = (t_key_binding*)pos;
		if (bind->is_down == TRUE)
		{
			if (bind->action.action == NULL)
				throw_void("trigger_key_hold", "fn pointer is NULL");
			else
				bind->action.action(bind->action.resource,
					bind->action.resource_type, bind->action.args);
		}
	}
}

void	trigger_key_bindings(t_list_head *bind_list, SDL_Keycode key)
{
	t_list_head				*pos;
	t_key_binding			*bind;
	
	pos = bind_list;
	while ((pos = pos->next) != bind_list)
	{
		bind = (t_key_binding*)pos;
		if (bind->key == key)
		{
			if (bind->action.action == NULL)
				throw_void("trigger_key_hold", "fn pointer is NULL");
			else
				bind->action.action(bind->action.resource,
					bind->action.resource_type, bind->action.args);
		}
	}
}

void	active_key_hold_binding(t_list_head *bind_list, SDL_Keycode key)
{
	t_list_head				*pos;
	t_key_binding			*bind;

	pos = bind_list;
	while ((pos = pos->next) != bind_list)
	{
		bind = (t_key_binding*)pos;
		// printf("bind key %d search key %d\n", bind->key, key);
		if (bind->key == key)
			bind->is_down = TRUE;
	}
}
void	disable_key_hold_bindings(t_list_head *bind_list, SDL_Keycode key)
{
	t_list_head				*pos;
	t_key_binding			*bind;

	pos = bind_list;
	while ((pos = pos->next) != bind_list)
	{
		bind = (t_key_binding*)pos;
		if (bind->key == key)
			bind->is_down = FALSE;
	}
}

void	handle_keyboard_down(t_scene *scene, SDL_Keycode key)
{
	if (scene == NULL)
		return (throw_void)("handle_keyboard_down", "NULL pointer provided");
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
