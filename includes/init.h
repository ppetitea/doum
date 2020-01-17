/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:27:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/17 16:34:27 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "game.h"
# include "resources/textures/texture.h"
# include "resources/resources.h"
# include "resources/resources.h"
# include "entities/entities.h"
# include "entities/player.h"
# include "entities/sprites/ennemies.h"
# include "entities/sprites/sprites.h"
# include "entities/ui/button.h"
# include "entities/ui/spawner.h"

t_result	initialize_images_list(t_game *game);
t_result	initialize_entities(t_game *game);
t_result	initialize_buttons_entities(t_game *game);
t_result	initialize_spawners_entities(t_game *game);
t_player	*initialize_player(t_game *game);
t_result	initialize_sprites_entities(t_game *game);
t_result	initialize_ennemy(t_game *game, t_player *player);

#endif