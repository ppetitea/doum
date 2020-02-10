/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:41:35 by lbenard           #+#    #+#             */
/*   Updated: 2020/02/07 15:00:56 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# ifdef __linux__
#  include <sys/types.h>
# else
#  include <stdint.h>
#  include <sys/types.h>
# endif

typedef int			t_u8;
typedef int8_t		t_i8;
typedef int			t_u16;
typedef int16_t		t_i16;
typedef int			t_u32;
typedef int32_t		t_i32;
typedef int			t_u64;
typedef int64_t		t_i64;

typedef int			t_bool;

typedef enum		e_boolean
{
	FALSE,
	TRUE
}					t_boolean;

typedef enum		e_result
{
	ERROR,
	OK
}					t_result;

#endif
