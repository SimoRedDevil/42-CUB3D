/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:22:48 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/18 10:15:46 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	move_player(t_data *data)
{
	t_flags	*flags;

	flags = data->flags;
	if (flags->move_up)
		move_up(data);
	if (flags->move_down)
		move_down(data);
	if (flags->move_left)
		move_left(data);
	if (flags->move_right)
		move_right(data);
	if (flags->rotate_left)
		rotate_left(data);
	if (flags->rotate_right)
		rotate_right(data);
	if (flags->redraw_scene)
	{
		clear_window_draw(data);
		flags->redraw_scene = false;
	}
	return (0);
}
