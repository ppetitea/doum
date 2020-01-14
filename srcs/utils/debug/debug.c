/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 22:07:04 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/13 21:04:22 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"index.h"
#include	"libft.h"
#include	<stdio.h>
#include	<stdlib.h>

t_result	debug(t_game *game)
{
	static	t_bool			init = TRUE;
	static	t_bitmap_texture	*bmp;
	static	t_texture			*texture1;
	static	t_texture			*texture2;
	static	t_texture			*texture3;
	t_texture_args				args;
	
	if (init)
	{
		if (!(bmp = load_bmp("resources/textures/tmp/msi.bmp")))
			return (throw_error("debug", "failed to load bmp"));
		args = texture_args("foo", ft_vec2i(100, 100), ft_usize(200, 200));
		texture1 = create_texture_with_bmp(args, *bmp);
		args = texture_args("foo", ft_vec2i(150, 150), ft_usize(200, 200));
		texture2 = create_texture_with_bmp(args, *bmp);
		args = texture_args("foo", ft_vec2i(0, 0), ft_usize(200, 200));
		texture3 = create_texture_with_bmp(args, *bmp);
		init = FALSE;
	}

	render_bmp(ft_vec2i(0, 0), game->screen, *bmp);
	render_texture(game->screen, texture1, ft_vec2i(0, 0));
	render_texture(game->screen, texture2, ft_vec2i(0, 0));
	render_texture(game->screen, texture3, ft_vec2i(0, 0));
	return (OK);
}
