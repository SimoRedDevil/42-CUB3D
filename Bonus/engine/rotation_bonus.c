/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:00:16 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/29 10:53:28 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	rotate_right(t_data *data)
{
	data->player->angle += (KEYBOARD_ROTSPEED * (M_PI / 180));
	data->flags->redraw_scene = true;
}

void	rotate_left(t_data *data)
{
	data->player->angle -= (KEYBOARD_ROTSPEED * (M_PI / 180));
	data->flags->redraw_scene = true;
}

static void	center_mouse(t_data *data, int x, int y)
{
	if (x > SCREEN_WIDTH || x < 0)
	{
		mlx_mouse_move(data->mlx->win_ptr, SCREEN_WIDTH / 2, y);
		data->mouse_x = SCREEN_WIDTH / 2;
		data->mouse_y = y;
		data->flags->adjust_mouse = true;
	}
	if (y > SCREEN_HEIGHT || y < 0)
	{
		mlx_mouse_move(data->mlx->win_ptr, x, SCREEN_HEIGHT / 2);
		data->mouse_x = x;
		data->mouse_y = SCREEN_HEIGHT / 2;
		data->flags->adjust_mouse = true;
	}
}

int	mouse_rotation(int x, int y, t_data *data)
{
	int	old_x;
	int	old_y;
	int	i;
	int	j;

	if (data->flags->hide_mouse == false)
		return (0);
	center_mouse(data, x, y);
	if (data->flags->adjust_mouse == false)
	{
		old_x = data->mouse_x;
		old_y = data->mouse_y;
		i = x - old_x;
		j = old_y - y;
		data->player->angle += (i * MOUSE_ROTSPEED);
		data->half_screen += j;
		if (data->half_screen < 0)
			data->half_screen = 0;
		else if (data->half_screen > SCREEN_HEIGHT)
			data->half_screen = SCREEN_HEIGHT;
		data->mouse_x = x;
		data->mouse_y = y;
		data->flags->redraw_scene = true;
	}
	return (data->flags->adjust_mouse = false, 0);
}
