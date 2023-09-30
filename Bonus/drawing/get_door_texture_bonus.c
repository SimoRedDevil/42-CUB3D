/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_door_texture_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:41:12 by aben-nei          #+#    #+#             */
/*   Updated: 2023/09/29 10:53:28 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	my_pixel_put_door(t_door *door, int x, int y, unsigned int *color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = door->door_img->img_data + (y * door->door_img->line_length + x
			* (door->door_img->bpp / 8));
	*color = *(unsigned int *)dst;
}

void	get_offset_door(t_data *data, t_door *door,
	float wall_height, float y_top)
{
	float	start_y;

	start_y = data->half_screen - (wall_height / 2);
	if (!data->ray->hit_vert_horz)
		door->x_offset = fmod(data->ray->wall_hit_x
				* door->door_width / SCALE_SIZE, door->door_width);
	else
		door->x_offset = fmod(data->ray->wall_hit_y 
				* door->door_width / SCALE_SIZE, door->door_width);
	door->y_offset = (y_top - start_y) * (door->door_height / wall_height);
}

void	ft_convert_to_rgb(unsigned int color, unsigned int rgb[3])
{
	rgb[0] = (color >> 16) & 0xFF;
	rgb[1] = (color >> 8) & 0xFF;
	rgb[2] = color & 0xFF;
}

void	decrementbrightness(unsigned int *r, unsigned int *g,
		unsigned int *b, float decrement)
{
	*r = *r * decrement;
	*g = *g * decrement;
	*b = *b * decrement;
}

int	rgb2int_converter(unsigned int *rgb)
{
	int		color;
	int		i;

	color = 0;
	i = 2;
	while (i >= 0)
	{
		ft_memset(((char *)&color) + abs(i - 2), rgb[i], sizeof(char));
		i--;
	}
	return (color);
}
