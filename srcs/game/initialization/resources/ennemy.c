/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:12:08 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/17 21:53:47 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "resources/textures/texture.h"
#include "resources/resources.h"
#include "utils/error.h"
#include "libft.h"

t_result	load_ennemy_front_textures(t_game *game)
{
	t_bitmap_texture	*bmp;
	
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/front/front1.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_front1"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/front/front2.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_front2"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/front/front3.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_front3"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/front/front4.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_front4"));
	return (OK);
}
t_result	load_ennemy_front_right_textures(t_game *game)
{
	t_bitmap_texture	*bmp;
	
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/front/front_r1.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_front_r1"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/front/front_r2.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_front_r2"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/front/front_r3.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_front_r3"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/front/front_r4.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_front_r4"));
	return (OK);
}
t_result	load_ennemy_front_left_textures(t_game *game)
{
	t_bitmap_texture	*bmp;
	
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/front/front_l1.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_front_l1"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/front/front_l2.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_front_l2"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/front/front_l3.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_front_l3"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/front/front_l4.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_front_l4"));
	return (OK);
}
t_result	load_ennemy_right_textures(t_game *game)
{
	t_bitmap_texture	*bmp;
	
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/right/right1.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_right1"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/right/right2.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_right2"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/right/right3.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_right3"));
	return (OK);
}
t_result	load_ennemy_back_textures(t_game *game)
{
	t_bitmap_texture	*bmp;
	
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/back/back1.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_back1"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/back/back2.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_back2"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/back/back3.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_back3"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/back/back4.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_back4"));
	return (OK);
}
t_result	load_ennemy_back_right_textures(t_game *game)
{
	t_bitmap_texture	*bmp;
	
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/back/back_r1.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_back_r1"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/back/back_r2.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_back_r2"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/back/back_r3.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_back_r3"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/back/back_r4.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_back_r4"));
	return (OK);
}
t_result	load_ennemy_back_left_textures(t_game *game)
{
	t_bitmap_texture	*bmp;
	
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/back/back_l1.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_back_l1"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/back/back_l2.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_back_l2"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/back/back_l3.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_back_l3"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/back/back_l4.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_back_l4"));
	return (OK);
}
t_result	load_ennemy_left_textures(t_game *game)
{
	t_bitmap_texture	*bmp;
	
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/left/left1.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_left1"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/left/left2.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_left2"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/left/left3.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_left3"));
	return (OK);
}
t_result	load_ennemy_attack_textures(t_game *game)
{
	t_bitmap_texture	*bmp;
	
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/attack/attack1.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_attack1"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/attack/attack2.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_attack2"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/attack/attack3.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_attack3"));
	return (OK);
}
t_result	load_ennemy_die_textures(t_game *game)
{
	t_bitmap_texture	*bmp;
	
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/die/die1.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_die1"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/die/die2.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_die2"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/die/die3.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_die3"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/die/die4.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_die4"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/die/die5.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_die5"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/die/die6.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_die6"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/die/die7.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_die7"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/die/die8.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_die8"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/die/die9.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_die9"));
	if (!(bmp = load_bmp("resources/textures/sprites/ennemies/test/die/die10.bmp")))
		return (throw_error("load_shotgun_textures", "failed to load bmp"));
	list_add_image(game, bmp, ft_strdup("ennemy_die10"));
	return (OK);
}

t_result	load_ennemy_textures(t_game *game)
{
	if (!load_ennemy_front_textures(game))
		return (throw_error("load_ennemy_textures", "failed to load front"));
	if (!load_ennemy_front_right_textures(game))
		return (throw_error("load_ennemy_textures", "failed to load front_r"));
	if (!load_ennemy_front_left_textures(game))
		return (throw_error("load_ennemy_textures", "failed to load front_l"));
	if (!load_ennemy_right_textures(game))
		return (throw_error("load_ennemy_textures", "failed to load right"));
	if (!load_ennemy_back_textures(game))
		return (throw_error("load_ennemy_textures", "failed to load back"));
	if (!load_ennemy_back_right_textures(game))
		return (throw_error("load_ennemy_textures", "failed to load back_r"));
	if (!load_ennemy_back_left_textures(game))
		return (throw_error("load_ennemy_textures", "failed to load back_l"));
	if (!load_ennemy_left_textures(game))
		return (throw_error("load_ennemy_textures", "failed to load left"));
	if (!load_ennemy_attack_textures(game))
		return (throw_error("load_ennemy_textures", "failed to load attack"));
	if (!load_ennemy_die_textures(game))
		return (throw_error("load_ennemy_textures", "failed to load die"));
	return (OK);
}
