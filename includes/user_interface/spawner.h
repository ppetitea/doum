/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawner.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:12:43 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/14 02:52:22 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAWNER_H
# define SPAWNER_H

# include "user_interface/ui.h"
# include "textures/texture.h"

typedef struct		s_ui_spawner
{
	t_ui_component		parent;
	t_texture			*normal;
	t_texture			*hover;
	t_texture			*dragged;
	t_texture			*texture_save;
	struct s_ui_spawner*	(*create_ui_spawner)(t_texture*);
}					t_ui_spawner;

t_ui_spawner			*create_ui_spawner(t_texture *texture);

#endif