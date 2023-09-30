/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:37:12 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/29 10:53:28 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

bool	check_if_not_wall_door(char **map, float x, float y)
{
	if (map[(int)(y) / SCALE_SIZE][(int)(x + 2) / SCALE_SIZE] != '1' &&
		map[(int)(y) / SCALE_SIZE][(int)(x - 2) / SCALE_SIZE] != '1' &&
		map[(int)(y + 2) / SCALE_SIZE][(int)(x) / SCALE_SIZE] != '1' &&
		map[(int)(y - 2) / SCALE_SIZE][(int)(x) / SCALE_SIZE] != '1' &&
		map[(int)(y + 2) / SCALE_SIZE][(int)(x + 2) / SCALE_SIZE] != '1'
		&& map[(int)(y) / SCALE_SIZE][(int)(x) / SCALE_SIZE] != '1' &&
		map[(int)(y) / SCALE_SIZE][(int)(x + 2) / SCALE_SIZE] != 'D' &&
		map[(int)(y) / SCALE_SIZE][(int)(x - 2) / SCALE_SIZE] != 'D' &&
		map[(int)(y + 2) / SCALE_SIZE][(int)(x) / SCALE_SIZE] != 'D' &&
		map[(int)(y - 2) / SCALE_SIZE][(int)(x) / SCALE_SIZE] != 'D' &&
		map[(int)(y + 2) / SCALE_SIZE][(int)(x + 2) / SCALE_SIZE] != 'D'
		&& map[(int)(y - 2) / SCALE_SIZE][(int)(x - 2) / SCALE_SIZE] != 'D'
		&& map[(int)(y) / SCALE_SIZE][(int)(x) / SCALE_SIZE] != 'D')
		return (true);
	return (false);
}

bool	check_wall(t_data *data, float x, float y, int flag)
{
	char	**map;

	if (x + 2 >= data->map_width * SCALE_SIZE || x - 2 < 0
		|| y + 2 >= data->map_height * SCALE_SIZE || y - 2 < 0)
		return (false);
	map = data->map;
	if (check_if_not_wall_door(map, x, y))
		return (data->player->hit_wall = false,
			data->player->already_hit = false, true);
	if (data->door->door_distance > 40 && (map[(int)(y) / SCALE_SIZE]
		[(int)(x) / SCALE_SIZE] == 'D' ||
		map[(int)(y) / SCALE_SIZE][(int)(x - 2) / SCALE_SIZE] == 'D'))
		flag = 0;
	if (!flag)
		if (map[(int)(y) / SCALE_SIZE][(int)(x + 2) / SCALE_SIZE] == 'D' ||
			map[(int)(y) / SCALE_SIZE][(int)(x - 2) / SCALE_SIZE] == 'D' ||
			map[(int)(y + 2) / SCALE_SIZE][(int)(x) / SCALE_SIZE] == 'D' ||
			map[(int)(y - 2) / SCALE_SIZE][(int)(x) / SCALE_SIZE] == 'D' ||
			map[(int)(y + 2) / SCALE_SIZE][(int)(x + 2) / SCALE_SIZE] == 'D'
			|| map[(int)(y - 2) / SCALE_SIZE][(int)(x - 2) / SCALE_SIZE] == 'D'
			|| map[(int)(y) / SCALE_SIZE][(int)(x) / SCALE_SIZE] == 'D'
			|| map[(int)(y - 2) / SCALE_SIZE][(int)(x - 2) / SCALE_SIZE] == '0')
			return (flag = 1, true);
	return (data->player->hit_wall = true, false);
}
