/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helper_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:50:14 by aben-nei          #+#    #+#             */
/*   Updated: 2023/09/29 10:53:28 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	get_color_texture_helper(t_data *data, float wall_height,
	float y_top, unsigned int *color)
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

void	get_color_door_texture(t_data *data,
	unsigned int *color, float wall_height, float y_top)
{
	get_offset_door(data, data->door, wall_height, y_top);
	my_pixel_put_door(data->door, data->door->x_offset,
		data->door->y_offset, color);
}

void	get_color_wall_texture(t_data *data, unsigned int *color,
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

void	get_color_texture(t_data *data, unsigned int *color,
	float wall_height, float y_top)
{
	if (!data->flags->flag_door)
		get_color_wall_texture(data, color, wall_height, y_top);
	else
		get_color_door_texture(data, color, wall_height, y_top);
}
