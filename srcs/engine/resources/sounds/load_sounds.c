/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sounds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:17:42 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/17 19:08:09 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/error.h"
#include "utils/parser.h"
#include "libft.h"
#include "engine/resource/sound/sound.h"

static t_result	load_sound(char *path, char *name, t_list_head *sounds)
{
	t_sound_node	*sound;

	if (sounds == NULL || path == NULL || name == NULL)
		return (throw_error("load_sound", "null pointer provided"));
	if (!(sound = malloc(sizeof(t_sound_node))))
		return (throw_error("load_sound", "malloc failed"));
	sound->name = name;
	if ((sound->sound = Mix_LoadWAV(path)) == NULL)
		return (throw_error("load_sound", "Mix_Load failed"));
	init_list_head(&sound->node);
	list_add_entry(&sound->node, sounds);
	return (OK);
}

t_result	load_sounds(t_list_head *sounds)
{
	t_dnon_object	*sounds_obj;
	t_dnon_object	*sound_path_obj;
	t_list_head		*sound_paths;
	t_list_head		*pos;
	char			*path;

	if (sounds == NULL)
		return (throw_error("load_sounds", "null pointer provided"));
	if (!(sounds_obj = parse_dnon_file("resources/sound/sounds.doom")))
		return (throw_error("load_sounds", "fail to parse file"));
	// prinf("%d\n", sounds_obj->type);
	if (sounds_obj->type != LIST)
		return (throw_error("load_sounds", "obj must be a LIST"));
	sound_paths = (t_list_head*)sounds_obj->value;
	pos = sound_paths;
	while ((pos = pos->next) != sound_paths)
	{
		sound_path_obj = (t_dnon_object*)pos;
		if (sound_path_obj->type == STRING)
		{
			path = (char*)sound_path_obj->value;
			load_sound(path, sound_path_obj->key, sounds);
		}
	}
	return (OK);
}