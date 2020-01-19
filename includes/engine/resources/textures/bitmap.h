/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:31:09 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/19 18:45:11 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
# define BITMAP_H

# include "libft.h"
# include "engine/interface/init_screen.h"
# include "utils/color.h"

# define BMP_HEADER_SIZE 54
# define DIB_HEADER_SIZE 40
#pragma pack(push)  // save the original data alignment
#pragma pack(1)
typedef int int32;
typedef short int16;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;

typedef struct 		s_bitmap_header
{
	unsigned short int	type;           	// Magic identifier: 0x4d42
    uint32_t			size;              // File size in bytes
    uint16_t			reserved1;         // Not used
    uint16_t			reserved2;         // Not used
    uint32_t 			offset;            // Offset to image data in bytes from beginning of file
    uint32_t			header_size;   	// Header size in bytes
    int32_t				width;          // Width of the image
    int32_t				height;         // Height of image
    uint16_t			num_planes;        // Number of color planes
    uint16_t			bits_per_pixel;    // Bits per pixel
    uint32_t			compression;       // Compression type
    uint32_t			image_size_bytes;  // Image size in bytes
    int32_t				x_resolution_ppm;  // Pixels per meter
    int32_t				y_resolution_ppm;  // Pixels per meter
    uint32_t			num_colors;        // Number of colors
    uint32_t			important_colors;  // Important colors
} 					t_bitmap_header;

#pragma pack(pop)  // restore the previous pack setting

typedef struct		s_bitmap_texture
{
    t_bitmap_header head;
    uint32_t		*pixels;
}					t_bitmap_texture;

/*
**	UNIQUEMENT FORMAT BITMAP 24 bits per pixels [B,G,R]
*/

t_bitmap_texture	*load_bmp(char *path);
void				render_bmp(t_vec2i offset, t_screen screen,
						t_bitmap_texture bmp);

#endif