/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:28:54 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/29 10:53:28 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	my_pixel_put(t_texture *data, int x, int y, unsigned int *color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = data->texture_img->img_data + (y * data->texture_img->line_length + x
			* (data->texture_img->bpp / 8));
	*color = *(unsigned int *)dst;
}

t_texture	*get_value(t_texture *texture, char *key)
{
	t_texture	*tmp;

	tmp = texture;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

void	get_texture_offset(t_data *data, t_texture *texture,
	float wall_height, float y_top)
{
	float	start_y;

	start_y = data->half_screen - (wall_height / 2);
	if (!data->ray->hit_vert_horz)
		texture->x_offset = fmod(data->ray->wall_hit_x
				* texture->xpm_width / SCALE_SIZE, texture->xpm_width);
	else
		texture->x_offset = fmod(data->ray->wall_hit_y 
				* texture->xpm_width / SCALE_SIZE, texture->xpm_width);
	texture->y_offset = (y_top - start_y) * (texture->xpm_height / wall_height);
}

void	draw_square(t_data *data, int x, int y, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(data, x + i, y + j, 0x000000);
			j++;
		}
		i++;
	}
}

void	draw_ammo_bar(t_data *data)
{
	int	i;
	int	x;

	x = 35;
	i = 0;
	while (i < data->player->ammo)
	{
		draw_square(data, x, 8, 20);
		x += 20;
		i++;
	}
}
