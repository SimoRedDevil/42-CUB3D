/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:59:43 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/18 10:06:49 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_left(t_data *data)
{
	float	x;
	float	y;

	x = data->player->x - cos(data->player->angle + (M_PI / 2)) * SPEED;
	y = data->player->y - sin(data->player->angle + (M_PI / 2)) * SPEED;
	if (check_wall(data, x, y))
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
	if (check_wall(data, x, y))
	{
		data->player->y = y;
		data->player->x = x;
	}
	data->flags->redraw_scene = true;
}
