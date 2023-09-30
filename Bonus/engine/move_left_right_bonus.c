/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left_right_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:59:43 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/29 10:53:28 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	move_left(t_data *data)
{
	float	x;
	float	y;

	x = data->player->x - cos(data->player->angle + (M_PI / 2)) * SPEED;
	y = data->player->y - sin(data->player->angle + (M_PI / 2)) * SPEED;
	if (check_wall(data, x, y, data->doors[data->index_door].open_door))
	{
		data->player->y = y;
		data->player->x = x;
	}
	data->flags->redraw_scene = true;
}

void	move_right(t_data *data)
{
	float	x;
	float	y;

	x = data->player->x + (cos(data->player->angle + (M_PI / 2)) * SPEED);
	y = data->player->y + sin(data->player->angle + (M_PI / 2)) * SPEED;
	if (check_wall(data, x, y, data->doors[data->index_door].open_door))
	{
		data->player->y = y;
		data->player->x = x;
	}
	data->flags->redraw_scene = true;
}
