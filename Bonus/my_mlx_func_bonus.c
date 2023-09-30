/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_func_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:39:43 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/29 10:53:28 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = data->window_img->img_data
		+ (y * data->window_img->line_length + x * (data->window_img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	*my_mlx_new_img(t_data *data, int width, int height)
{
	void	*img;

	img = mlx_new_image(data->mlx->mlx_ptr, width, height);
	if (!img)
		throw_error(MLX_NEW_IMG_ERROR, g_heap());
	return (img);
}

void	*my_mlx_xpm_file_to_img(t_data *data, char *path,
	int *width, int *height)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, path, width, height);
	if (!img)
		throw_error(MLX_XPM_FILE_TO_IMG_ERROR, g_heap());
	return (img);
}

void	my_mlx_destroyer(t_data *data)
{
	mlx_clear_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
	mlx_destroy_image(data->mlx->mlx_ptr, data->window_img->img_ptr);
	mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
}
