/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbox_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 23:23:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 04:23:36 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entities/ui/init_checkbox.h"
#include "engine/entities/ui/update_checkbox.h"
#include "engine/resources/resources.h"
#include "engine/scenes/init_scene.h"
#include "utils/error.h"
#include "libft.h"

static t_result	init_menu_checkbox_test_entity(t_checkbox *checkbox, t_scene *scene)
{
	if (!overwrite_checkbox_entity_listener(&checkbox->super,
		&scene->renderer.ui_components, &scene->entities.ui_components, TRUE))
		return (throw_error("init_checkbox_test", "overwrite listener failed"));
	if (!overwrite_checkbox_entity_texture(&checkbox->super.texture,
			&checkbox->normal, ft_vec2i(0, 0)))
		return (throw_error("init_checkbox_test", "overwrite e_texture failed"));
	if (!overwrite_checkbox_entity_actions(&checkbox->super.trigger,
		checkbox_toogle_display_linked_entities))
		return (throw_error("init_checkbox_test", "overwrite actions failed"));
	return (OK);
}

t_checkbox	*init_menu_checkbox_test(t_scene *scene)
{
	t_list_head			*images;
	t_bitmap_texture	*bmp_hover;
	t_bitmap_texture	*bmp_selected;
	t_checkbox			*checkbox;
	t_usize				size;

	if (scene == NULL)
		return (throw_null("init_checkbox_test", "NULL pointer provided"));
	images = &scene->resources.images;
	if (!(bmp_hover = get_image_by_name(images, "checkbox_test")))
		return (throw_null("init_checkbox_test", "checkbox_test failed"));
	if (!(bmp_selected = get_image_by_name(images, "checkbox_test")))
		return (throw_null("init_checkbox_test", "checkbox_test failed"));
	size = ft_usize(100, 100);
	if (!(checkbox = init_new_checkbox()))
		return (throw_null("init_checkbox_test", "init checkbox failed"));
	if (!init_menu_checkbox_test_entity(checkbox, scene))
		return (throw_null("init_checkbox_test", "init e_checkbox failed"));
	if (!init_checkbox_textures(checkbox, *bmp_hover, *bmp_selected, size))
		return (throw_null("init_checkbox_test", "init c_texture failed"));
	if (!overwrite_checkbox_textures_offset(checkbox, ft_vec2i(540, 0)))
		return (throw_null("init_checkbox_test", "overwrite c_offset fail"));
	return (checkbox);
}
