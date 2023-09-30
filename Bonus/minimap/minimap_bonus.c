/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:49:49 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/29 12:28:37 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	draw_player(t_data *data, unsigned int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			my_mlx_pixel_put(data, j + 100, i
				+ (SCREEN_HEIGHT - 210) + 100, color);
			j++;
		}
		i++;
	}
}

void	mini_map_helper(t_data *data, t_vars vars)
{
	if (vars.distance <= vars.radius * vars.radius)
	{
		if ((int)vars.py / SCALE_SIZE >= 0 && (int)vars.py
			/ SCALE_SIZE < tab_size(data->map)
			&& data->map[(int)vars.py / SCALE_SIZE]
			&& ((int)vars.px / SCALE_SIZE >= 0)
			&& ((int)vars.px / SCALE_SIZE < (int)ft_strlen(data->map[0]))
			&& data->map[(int)vars.py / SCALE_SIZE]
			&& data->map[(int)vars.py / SCALE_SIZE][(int)vars.px
			/ SCALE_SIZE] == '1')
			my_mlx_pixel_put(data, vars.j, vars.i, 0x40513B);
		else if ((int)vars.py / SCALE_SIZE >= 0
			&& (int)vars.py / SCALE_SIZE < tab_size(data->map)
			&& data->map[(int)vars.py / SCALE_SIZE]
			&& ((int)vars.px / SCALE_SIZE >= 0)
			&& ((int)vars.px / SCALE_SIZE < (int)ft_strlen(data->map[0]))
			&& data->map[(int)vars.py / SCALE_SIZE][(int)vars.px
			/ SCALE_SIZE] == 'D')
			my_mlx_pixel_put(data, vars.j, vars.i, 0xE5D283);
		else
			my_mlx_pixel_put(data, vars.j, vars.i, 0xB99B6B);
	}
	else
		my_mlx_pixel_put(data, vars.j, vars.i, 0xffffff);
}

void	draw_minimap(t_data *data)
{
	t_vars	vars;

	vars.radius = 100;
	vars.border_width = 3;
	vars.i = SCREEN_HEIGHT - 210;
	vars.py = (int)data->player->y - vars.radius - vars.border_width;
	while (vars.py < (int)data->player->y + vars.radius + vars.border_width)
	{
		vars.px = (int)data->player->x - vars.radius - vars.border_width;
		vars.j = 0;
		while (vars.px < data->player->x + vars.radius + vars.border_width)
		{
			vars.distance = (vars.px - (int)data->player->x) * (vars.px
					- (int)data->player->x) + (vars.py - (int)data->player->y)
				* (vars.py - (int)data->player->y);
			if (vars.distance <= (vars.radius + vars.border_width)
				* (vars.radius + vars.border_width))
				mini_map_helper(data, vars);
			vars.px++;
			vars.j++;
		}
		vars.py++;
		vars.i++;
	}
	draw_player(data, 0xAA5656);
}
