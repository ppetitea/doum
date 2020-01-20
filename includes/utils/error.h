/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 23:23:33 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/20 01:45:13 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libft.h"

/*
**	Gestion des erreurs
**
**	Quitte la fonction en retournant la valeur adaptee ERROR | NULL | void
**	print un message d'erreur de type :
**	"nom_de_la_fonction()", "description de l'erreur"
**
*/

// typedef enum			e_error_type
// {
// 	WARNING,
// 	FATAL
// }						t_error_type;

t_result	throw_error(char *location, char *message);
void		*throw_null(char *location, char *message);
void		throw_void(char *location, char *message);

#endif