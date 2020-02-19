/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_sound.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:08:42 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/19 15:54:46 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/error.h"
#include "utils/parser.h"
#include "libft.h"
#include "engine/component/action.h"
#include "engine/resource/sound/sound.h"
#include "engine/game/game_init.h"

void		play_sound(Mix_Chunk *sound, int volume, int rep)
{
	int	i;
	
	i = 1;
	while (i < NUM_CHAN)
	{
		if (Mix_GetChunk(i) == sound)
		{
			ft_putendl("c'est le meme son");
			return ;
		}
		if (Mix_Playing(i) == 0)
		{
			Mix_VolumeChunk(sound, MIX_MAX_VOLUME / volume);
			Mix_PlayChannel(i, sound, rep);
		}
		i++;
	}
}


t_result	trigger_sound(void *game, t_resource_type resource_type,
					t_dnon_object *args)
{
	t_list_head		*sounds;
	char			*key;
	t_list_head		*pos;
	t_sound_node	*node;

	if (game == NULL || args == NULL)
		return (throw_error("trigger_sound", "NULL pointer provided"));
	if (resource_type != R_GAME)
		return (throw_error("trigger_sound", "resource must be game instance"));
	sounds = &((t_game*)game)->resources.songs;
	if (!(key = get_string_value_by_key(args, "name", NULL)))
		return (throw_error("trigger_sound", "sound name not found"));
	pos = sounds;
	while((pos = pos->next) != sounds)
	{
		node = (t_sound_node*)pos;
		if (ft_strcmp(node->name, key) == 0)
		{
			play_sound(node->sound, 1, 0);
			return (OK);
		}
	}
	return (throw_error("trigger sound", "sound not found"));
}