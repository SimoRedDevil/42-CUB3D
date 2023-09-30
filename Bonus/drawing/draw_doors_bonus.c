/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_doors_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:30:58 by aben-nei          #+#    #+#             */
/*   Updated: 2023/09/29 10:53:28 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	open_door(int keycode, t_data *data)
{
	if (keycode == KEY_SPACE)
	{
		if (data->door->door_distance < 40
			&& data->doors[data->index_door].open_door)
			data->doors[data->index_door].open_door = 0;
		data->flags->redraw_scene = true;
	}
}

void	door_drawing(int x, float height, t_data *data)
{
	float			y_top;
	unsigned int	color;
	float			y_bottom;

	y_top = data->half_screen - (height / 2);
	color = 0x1e272e;
	y_bottom = y_top + height;
	if (y_top < 0)
		y_top = 0;
	if (y_bottom > SCREEN_HEIGHT)
		y_bottom = SCREEN_HEIGHT;
	while (y_top < y_bottom && y_top < SCREEN_HEIGHT)
	{
		data->flags->flag_door = 1;
		get_color_texture(data, &color, height, y_top);
		shadow(data, &color);
		my_mlx_pixel_put(data, x, y_top, color);
		y_top++;
	}
}
