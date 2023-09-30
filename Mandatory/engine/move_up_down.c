/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:59:40 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/18 10:06:42 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_up(t_data *data)
{
	float	x;
	float	y;

	x = data->player->x + cos(data->player->angle) * SPEED;
	y = data->player->y + sin(data->player->angle) * SPEED;
	if (check_wall(data, x, y))
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
	if (check_wall(data, x, y))
	{
		data->player->y = y;
		data->player->x = x;
	}
	data->flags->redraw_scene = true;
}
