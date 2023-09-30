/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_door_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:05:59 by aben-nei          #+#    #+#             */
/*   Updated: 2023/09/29 10:53:28 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	hit_door_horz(t_data *data, t_ray *ray,
	bool *flag_door, int k)
{
	if (data->map[(int)(ray->y_horz_int - k)
		/ SCALE_SIZE][(int)(ray->x_horz_int) / SCALE_SIZE] == 'D')
	{
		data->door->door_distance = sqrt(pow(data->player->x
					- ray->x_horz_int, 2) + pow(data->player->y
					- ray->y_horz_int, 2));
		data->index_door = match_door(data->num_door, data->doors,
				(int)(ray->x_horz_int) / SCALE_SIZE,
				(int)(ray->y_horz_int - k) / SCALE_SIZE);
		if (data->doors[data->index_door].open_door)
		{
			*flag_door = 1;
			return (2);
		}
	}
	return (0);
}

int	hit_door_vert(t_data *data, t_ray *ray,
	bool *flag_door, int k)
{
	if (data->map[(int)ray->y_vert_int / SCALE_SIZE][(int)(ray->x_vert_int
		- k) / SCALE_SIZE] == 'D')
	{
		data->door->door_distance = sqrt(pow(data->player->x
					- ray->x_vert_int, 2) + pow(data->player->y
					- ray->y_vert_int, 2));
		data->index_door = match_door(data->num_door, data->doors,
				(int)(ray->x_vert_int - k) / SCALE_SIZE,
				(int)(ray->y_vert_int) / SCALE_SIZE);
		if (data->doors[data->index_door].open_door)
		{
			*flag_door = 1;
			return (2);
		}
	}
	return (0);
}
