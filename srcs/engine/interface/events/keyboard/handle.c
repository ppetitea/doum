/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:17:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 00:58:43 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/interface/events/keyboard.h"
#include "engine/scenes/init_scene.h"
#include "utils/error.h"

void	trigger_keys_bindings(t_scene *scene)
{
	t_list_head			*pos;
	t_list_head			*next;
	t_event_key_binding	*bind;

	pos = &scene->interface.keys_binds;
	next = pos->next;
	while ((pos = next) != &scene->interface.keys_binds)
	{
		next = next->next;
		bind = (t_event_key_binding*)pos;
		if (bind->is_down == TRUE)
			bind->trigger(bind->entity_ref);
	}
}

void	active_key_binding(t_scene *scene, SDL_Keycode key)
{
	t_list_head			*pos;
	t_list_head			*next;
	t_event_key_binding	*bind;

	pos = &scene->interface.keys_binds;
	next = pos->next;
	while ((pos = next) != &scene->interface.keys_binds)
	{
		next = next->next;
		bind = (t_event_key_binding*)pos;
		if (bind->key == key)
			bind->is_down = TRUE;
	}
}
void	disable_key_binding(t_scene *scene, SDL_Keycode key)
{
	t_list_head			*pos;
	t_list_head			*next;
	t_event_key_binding	*bind;

	pos = &scene->interface.keys_binds;
	next = pos->next;
	while ((pos = next) != &scene->interface.keys_binds)
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
	active_key_binding(scene, key);
	(void)scene;
}

void	handle_keyboard_up(t_scene *scene, SDL_Keycode key)
{
	disable_key_binding(scene, key);
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
