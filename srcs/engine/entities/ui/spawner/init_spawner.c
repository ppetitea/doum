/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_spawner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 04:57:16 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 05:29:12 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/init_entity.h"
#include "engine/entities/ui/init_spawner.h"
#include "engine/entities/ui/update_spawner.h"
#include "utils/error.h"
#include "libft.h"

t_result	create_spawner_with_another(t_spawner *src)
{
	t_spawner	*new;

	if (!(new = (t_spawner*)malloc(sizeof(t_spawner))))
		return (throw_error("create_spawner_with_another", "malloc failed"));
	init_entity(&new->super, SPAWNER);
	new->create_spawner_with_another = create_spawner_with_another;
	if (!(texture_filter(&new->save, src->save, FILTER_NONE)))
		return (throw_error("init_spawner_textures", "filter texture failed"));
	if (!(texture_filter(&new->normal, src->save, FILTER_HOVER)))
		return (throw_error("init_spawner_textures", "filter texture failed"));
	if (!(texture_filter(&new->hover, src->save, FILTER_NONE)))
		return (throw_error("init_spawner_textures", "filter texture failed"));
	if (!(texture_filter(&new->dragged, src->save, FILTER_BLEND)))
		return (throw_error("init_spawner_textures", "filter texture failed"));
	overwrite_spawner_entity_texture(&new->super.texture, &new->save,
		ft_vec2i(0, 0));
	overwrite_spawner_entity_actions(&new->super.trigger);
	overwrite_spawner_entity_listener(&new->super,
		src->super.status.render_list, src->super.status.storage_list, TRUE);
	return (OK);
}

t_result	duplicate_spawner(t_entity *entity)
{
	t_spawner	*self;

	if (entity->type != SPAWNER)
		return (throw_error("duplicate_spawner", "type isn't SPAWNER"));
	self = (t_spawner*)entity;
	if (self->save.offset.x != self->normal.offset.x ||
		self->save.offset.y != self->normal.offset.y)
		return (OK);
	if (!self->create_spawner_with_another(self))
		return (throw_error("duplicate_spawner", "failed"));
	return (OK);
}

t_spawner	*init_new_spawner()
{
	t_spawner	*self;

	if (!(self = (t_spawner*)malloc(sizeof(t_spawner))))
		return (throw_null("create_spawner", "malloc failed"));
	if (!init_entity(&self->super, SPAWNER))
		return (throw_null("create_spawner", "init entity failed"));
	self->normal.pixels = NULL;
	self->hover.pixels = NULL;
	self->dragged.pixels = NULL;
	self->save.pixels = NULL;
	self->create_spawner_with_another = create_spawner_with_another;
	return (self);
}

t_result	init_spawner_textures(t_spawner *self, t_bitmap_texture bmp,
				t_usize size, t_vec2i offset)
{
	if (self == NULL)
		return (throw_error("init_spawner_textures", "NULL pointer provided"));
	if (!(init_texture(&self->save, "spawner_init", size)))
		return (throw_error("init_spawner_textures", "init texture failed"));
	if (!fill_texture_with_bmp(&self->save, &bmp))
		return (throw_error("init_spawner_textures", "fill texture failed"));
	self->save.offset = offset;
	if (!texture_filter(&self->normal, self->save, FILTER_HOVER))
		return (throw_error("init_spawner_textures", "filter texture failed"));
	if (!texture_filter(&self->hover, self->save, FILTER_NONE))
		return (throw_error("init_spawner_textures", "filter texture failed"));
	if (!texture_filter(&self->dragged, self->save, FILTER_BLEND))
		return (throw_error("init_spawner_textures", "filter texture failed"));
	return (OK);
}
