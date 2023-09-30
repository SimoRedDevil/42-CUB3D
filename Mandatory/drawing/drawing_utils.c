/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:28:54 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/29 09:44:46 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_pixel_put(t_texture *data, int x, int y, int *color)
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
