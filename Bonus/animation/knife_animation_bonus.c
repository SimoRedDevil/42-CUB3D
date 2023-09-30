/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knife_animation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:40:57 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/29 10:53:28 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	render_0to10_frames(t_data *data, int i)
{
	if (i >= 0 && i < 3)
		load_put_image(data, KNIFE_DIR, "0.xpm");
	else if (i >= 3 && i < 6)
		load_put_image(data, KNIFE_DIR, "1.xpm");
	else if (i >= 6 && i < 9)
		load_put_image(data, KNIFE_DIR, "2.xpm");
	else if (i >= 9 && i < 12)
		load_put_image(data, KNIFE_DIR, "3.xpm");
	else if (i >= 12 && i < 15)
		load_put_image(data, KNIFE_DIR, "4.xpm");
	else if (i >= 15 && i < 18)
		load_put_image(data, KNIFE_DIR, "5.xpm");
	else if (i >= 18 && i < 21)
		load_put_image(data, KNIFE_DIR, "6.xpm");
	else if (i >= 21 && i < 24)
		load_put_image(data, KNIFE_DIR, "7.xpm");
	else if (i >= 24 && i < 27)
		load_put_image(data, KNIFE_DIR, "8.xpm");
	else if (i >= 27 && i < 30)
		load_put_image(data, KNIFE_DIR, "9.xpm");
	else if (i >= 30 && i < 33)
		load_put_image(data, KNIFE_DIR, "10.xpm");
}

static void	render_11to14_frames(t_data *data, int i)
{
	if (i >= 33 && i < 36)
		load_put_image(data, KNIFE_DIR, "11.xpm");
	else if (i >= 36 && i < 39)
		load_put_image(data, KNIFE_DIR, "12.xpm");
	else if (i >= 39 && i < 42)
		load_put_image(data, KNIFE_DIR, "13.xpm");
	else if (i >= 42 && i < 45)
		load_put_image(data, KNIFE_DIR, "14.xpm");
}

void	knife_animation(t_data *data)
{
	static int	i;

	if (data->flags->knife_shoot == false)
	{
		load_put_image(data, KNIFE_DIR, "0.xpm");
		return ;
	}
	if (i >= 45)
	{
		i = 0;
		data->flags->knife_shoot = false;
	}
	render_0to10_frames(data, i);
	render_11to14_frames(data, i);
	i++;
}
