/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:00:16 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/18 10:07:02 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
