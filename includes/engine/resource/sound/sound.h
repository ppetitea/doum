/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:24:01 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/12 16:59:37 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOUND_H
# define SOUND_H

# include "containers/list.h"
# include "SDL_mixer.h"

typedef enum		e_repetition_mod
{
	PLAY_INFINITE =	-1,
	PLAY_ONCE =		0
}					t_repetition_mod;

typedef struct		s_sound_node
{
	t_list_head		node;
	Mix_Chunk		*sound;
	char			*name;
}					t_sound_node;




#endif