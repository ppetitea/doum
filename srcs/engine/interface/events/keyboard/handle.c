/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:17:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 16:36:22 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "events/keyboard.h"
#include "utils/error.h"

void	trigger_keys_bindings(t_game *game)
{
	t_list_head			*pos;
	t_list_head			*next;
	t_event_key_binding	*bind;

	pos = &game->interface.keys_bind;
	next = pos->next;
	while ((pos = next) != &game->interface.keys_bind)
	{
		next = next->next;
		bind = (t_event_key_binding*)pos;
		if (bind->is_down == TRUE)
			bind->trigger(bind->entity_ref);
	}
}

void	active_key_binding(t_game *game, SDL_Keycode key)
{
	t_list_head			*pos;
	t_list_head			*next;
	t_event_key_binding	*bind;

	pos = &game->interface.keys_bind;
	next = pos->next;
	while ((pos = next) != &game->interface.keys_bind)
	{
		next = next->next;
		bind = (t_event_key_binding*)pos;
		if (bind->key == key)
			bind->is_down = TRUE;
	}
}
void	disable_key_binding(t_game *game, SDL_Keycode key)
{
	t_list_head			*pos;
	t_list_head			*next;
	t_event_key_binding	*bind;

	pos = &game->interface.keys_bind;
	next = pos->next;
	while ((pos = next) != &game->interface.keys_bind)
	{
		next = next->next;
		bind = (t_event_key_binding*)pos;
		if (bind->key == key)
			bind->is_down = FALSE;
	}
}

void	handle_keyboard_down(t_game *game, SDL_Keycode key)
{
	if (key == SDLK_ESCAPE)
		game->is_running = FALSE;
	active_key_binding(game, key);
	(void)game;
}

void	handle_keyboard_up(t_game *game, SDL_Keycode key)
{
	disable_key_binding(game, key);
	(void)game;
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
