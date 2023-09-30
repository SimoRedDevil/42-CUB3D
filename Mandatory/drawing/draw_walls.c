/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:30:23 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/18 10:15:14 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	colorize_window(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		j = 0;
		while (j < SCREEN_WIDTH)
		{
			if (i < data->half_screen)
				my_mlx_pixel_put(data, j, i, data->celling_color);
			else
				my_mlx_pixel_put(data, j, i, data->floor_color);
			j++;
		}
		i++;
	}
}

static void	get_color_texture_helper(t_data *data, float wall_height,
	float y_top, int *color)
{
	t_texture	*value;

	value = NULL;
	if (data->ray->ray_angle > M_PI)
	{
		value = get_value(data->textures, "NO");
		get_texture_offset(data, value, wall_height, y_top);
		my_pixel_put(value, value->x_offset, value->y_offset, color);
	}
	else
	{
		value = get_value(data->textures, "SO");
		get_texture_offset(data, value, wall_height, y_top);
		my_pixel_put(value, value->x_offset, value->y_offset, color);
	}
}

static void	get_color_texture(t_data *data, int *color,
	float wall_height, float y_top)
{
	t_texture	*value;

	value = NULL;
	if (!data->ray->hit_vert_horz)
		get_color_texture_helper(data, wall_height, y_top, color);
	else
	{
		if (data->ray->ray_angle < 0.5 * M_PI
			|| data->ray->ray_angle > 1.5 * M_PI)
		{
			value = get_value(data->textures, "WE");
			get_texture_offset(data, value, wall_height, y_top);
			my_pixel_put(value, value->x_offset, value->y_offset, color);
		}
		else
		{
			value = get_value(data->textures, "EA");
			get_texture_offset(data, value, wall_height, y_top);
			my_pixel_put(value, value->x_offset, value->y_offset, color);
		}
	}
}

void	wall_drawing(int x, float height, t_data *data)
{
	float	y_top;
	int		color;
	float	y_bottom;

	y_top = data->half_screen - (height / 2);
	color = 0x1e272e;
	y_bottom = y_top + height;
	if (y_top < 0)
		y_top = 0;
	if (y_bottom > SCREEN_HEIGHT)
		y_bottom = SCREEN_HEIGHT;
	while (y_top < y_bottom && y_top < SCREEN_HEIGHT)
	{
		get_color_texture(data, &color, height, y_top);
		my_mlx_pixel_put(data, x, y_top, color);
		y_top++;
	}
}

void	clear_window_draw(t_data *data)
{
	mlx_clear_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
	colorize_window(data);
	cast_all_rays(data);
}
