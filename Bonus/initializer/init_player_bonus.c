/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:46:50 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/29 10:53:28 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static float	get_player_angle(char c)
{
	if (c == 'N')
		return (3 * M_PI / 2);
	else if (c == 'S')
		return (M_PI / 2);
	else if (c == 'E')
		return (2 * M_PI);
	else if (c == 'W')
		return (M_PI);
	return (0);
}

t_player	*init_player(t_data *data)
{
	static t_player	player;
	int				*coord;

	coord = get_player_coord(data->map);
	player.x = coord[0] * SCALE_SIZE + SCALE_SIZE / 2;
	player.y = coord[1] * SCALE_SIZE + SCALE_SIZE / 2;
	player.angle = get_player_angle(data->map[coord[1]][coord[0]]);
	player.fov = 60 * (M_PI / 180);
	player.dis_proj_player = (SCREEN_WIDTH / 2) / tan(player.fov / 2);
	player.weapon = KNIFE;
	player.ammo = AMMO_MAX;
	player.hit_wall = false;
	player.already_hit = false;
	return (&player);
}
