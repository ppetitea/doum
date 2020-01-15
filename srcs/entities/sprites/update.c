/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 03:28:38 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 03:38:17 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "entities/sprites/sprites.h"
#include "utils/error.h"

t_result	update_sprite_anchor(t_entity *component, t_vec2i anchor)
{
	t_sprite	*sprite;

	if (component->type != SPRITE)
		return (throw_error("update_sprite_anchor",
			"component provided is not a sprite"));
	sprite = (t_sprite*)component;
	sprite->super.texture.anchor = anchor;
	return (OK);
}

t_result	update_sprite_offset(t_entity *component, t_vec2i offset)
{
	t_sprite	*sprite;

	if (component->type != SPRITE)
		return (throw_error("update_sprite_offset",
			"component provided is not a sprite"));
	sprite = (t_sprite*)component;
	sprite->super.texture.t->offset = offset;
	return (OK);
}

t_result	update_sprite_texture_with_status(t_entity *component)
{
	// t_sprite	*sprite;
	// t_vec2i		curr_offset;

	if (component->type != SPRITE)
		return (throw_error("update_sprite_offset",
			"component provided is not a sprite"));
	// curr_offset = component->texture->offset;
	// sprite = (t_sprite*)component;
	// component->texture->offset = curr_offset;
	return (OK);
}
