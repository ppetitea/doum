/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:47:49 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/15 00:14:45 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "index.h"

/*
**	Zone de debug
**
**	permet de tester le code sans modifier directement les sources
**
*/

t_result	debug(t_game *game);

void	debug_bmp_header(t_bitmap_header head);



#endif