/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:52:07 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 19:01:16 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_GAME_H
# define UPDATE_GAME_H

# include "engine/init_game.h"
# include "libft.h"

void		loop(t_game *game);
t_result	destroy_game();

#endif
