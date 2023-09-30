/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_down_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:59:40 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/29 10:53:28 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	move_up(t_data *data)
{
	float	x;
	float	y;

	x = data->player->x + cos(data->player->angle) * SPEED;
	y = data->player->y + sin(data->player->angle) * SPEED;
	if (check_wall(data, x, y, data->doors[data->index_door].open_door))
	{
		data->player->y = y;
		data->player->x = x;
	}
	data->flags->redraw_scene = true;
}

void	move_down(t_data *data)
{
	float	x;
	float	y;

	x = data->player->x - cos(data->player->angle) * SPEED;
	y = data->player->y - sin(data->player->angle) * SPEED;
	if (check_wall(data, x, y, data->doors[data->index_door].open_door))
	{
		data->player->y = y;
		data->player->x = x;
	}
	data->flags->redraw_scene = true;
}
