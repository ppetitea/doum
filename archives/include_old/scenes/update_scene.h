/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_scene.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:27:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 18:56:43 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_SCENES_H
# define UPDATE_SCENES_H

# include "engine/scenes/init_scene.h"
# include "engine/init_game.h"

t_result	render(t_scene *scene);
t_result	swap_scene(char *name);
t_result	swap_to_menu_scene();
t_result	swap_to_game_scene();
t_result	swap_to_map_editor_scene();

#endif
