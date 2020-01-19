/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_spawner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:57:16 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/18 21:32:40 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/init_entity.h"
#include "engine/entities/ui/build_spawner.h"
#include "engine/entities/ui/update_spawner.h"
#include "utils/error.h"
#include "libft.h"

static t_result	create_spawner_with_another(t_spawner *src)
{
	t_spawner	*new;

	if (!(new = (t_spawner*)malloc(sizeof(t_spawner))))
		return (throw_error("create_spawner_with_another", "malloc failed"));
	build_entity(&new->super, SPAWNER);
	new->create_spawner_with_another = create_spawner_with_another;
	new->initial_texture = src->initial_texture;
	if (!(new->normal = texture_filter(*src->initial_texture, FILTER_NONE)))
		return (throw_error("build_spawner_textures", "filter texture failed"));
	if (!(new->hover = texture_filter(*src->initial_texture, FILTER_NONE)))
		return (throw_error("build_spawner_textures", "filter texture failed"));
	if (!(new->dragged = texture_filter(*src->initial_texture, FILTER_NONE)))
		return (throw_error("build_spawner_textures", "filter texture failed"));
	build_spawner_entity_texture(&new->super.texture, new->initial_texture,
		ft_vec2i(0, 0));
	build_spawner_entity_listener(&new->super, src->super.status.render_list,
		src->super.status.storage_list, TRUE);
	return (OK);
}

t_result	duplicate_spawner(t_entity *entity)
{
	t_spawner	*self;

	if (entity->type != SPAWNER)
		return (throw_error("duplicate_spawner", "type isn't SPAWNER"));
	self = (t_spawner*)entity;
	if (self->initial_texture->offset.x != self->normal->offset.x ||
		self->initial_texture->offset.y != self->normal->offset.y)
		return (OK);
	if (!self->create_spawner_with_another(self))
		return (throw_error("duplicate_spawner", "failed"));
	return (OK);
}

t_spawner	*build_spawner()
{
	t_spawner	*self;

	if (!(self = (t_spawner*)malloc(sizeof(t_spawner))))
		return (throw_null("create_spawner", "malloc failed"));
	if (!build_entity(&self->super, SPAWNER));
		return (throw_null("create_spawner", "build entity failed"));
	self->normal = NULL;
	self->hover = NULL;
	self->dragged = NULL;
	self->initial_texture = NULL;
	self->create_spawner_with_another = create_spawner_with_another;
	return (self);
}

t_result	build_spawner_textures(t_spawner *self, t_bitmap_texture bmp,
				t_usize size)
{
	if (self == NULL)
		return (throw_error("build_spawner_textures", "NULL pointer provided"));
	if (!(self->initial_texture = build_texture("spawner_init", size)))
		return (throw_error("build_spawner_textures", "init texture failed"));
	if (!fill_texture_with_bmp(self->initial_texture, &bmp))
		return (throw_error("build_spawner_textures", "fill texture failed"));
	if (!(self->normal = texture_filter(*self->initial_texture, FILTER_HOVER)))
		return (throw_error("build_spawner_textures", "filter texture failed"));
	if (!(self->hover = texture_filter(*self->initial_texture, FILTER_NONE)))
		return (throw_error("build_spawner_textures", "filter texture failed"));
	if (!(self->dragged = texture_filter(*self->initial_texture, FILTER_BLEND)))
		return (throw_error("build_spawner_textures", "filter texture failed"));
	return (OK);
}
