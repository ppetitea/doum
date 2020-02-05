/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugibone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:01:39 by lugibone          #+#    #+#             */
/*   Updated: 2020/02/05 17:13:47 by lugibone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	putpixel(t_screen *screen, int x, int y, uint32_t color)
{
	if (y < 0 || y > screen->size.y)
		return (0);
	if (x < 0 || x > screen->size.x)
		return (0);
	screen->pixels[y * WIDTH + x] = color;
}

void	brush_square(t_screen *screen, int x, int y, int size, uint32_t color)
{
	int i;
	int j;

	i = -1 - size / 2;
	j = -1 - size / 2;
	while (++i < size / 2)
		while(++j < size / 2)
			putpixel(screen, x + j, y + i, color);
}
