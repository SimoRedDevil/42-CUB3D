/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:37:12 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/26 20:21:15 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_wall(t_data *data, float x, float y)
{
	if (data->map[(int)(y) / SCALE_SIZE][(int)(x + 2) / SCALE_SIZE] != '1' &&
		data->map[(int)(y) / SCALE_SIZE][(int)(x - 2) / SCALE_SIZE] != '1' &&
		data->map[(int)(y + 2) / SCALE_SIZE][(int)(x) / SCALE_SIZE] != '1' &&
		data->map[(int)(y - 2) / SCALE_SIZE][(int)(x) / SCALE_SIZE] != '1' &&
		data->map[(int)(y + 2) / SCALE_SIZE]
		[(int)(x + 2) / SCALE_SIZE] != '1' &&
		data->map[(int)(y) / SCALE_SIZE][(int)(x) / SCALE_SIZE] != '1')
		return (true);
	return (false);
}
