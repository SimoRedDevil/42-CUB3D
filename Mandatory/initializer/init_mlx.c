/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:57:38 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/16 11:33:55 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_mlx	*init_mlx(void)
{
	static t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		throw_error("Error: mlx_init failed", g_heap());
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, SCREEN_WIDTH,
			SCREEN_HEIGHT, "CUB3D");
	if (!mlx.win_ptr)
		throw_error("Error: mlx_new_window failed", g_heap());
	return (&mlx);
}

t_image	*init_win_image(t_data *data)
{
	static t_image	win_image;

	win_image.img_ptr = my_mlx_new_img(data, SCREEN_WIDTH, SCREEN_HEIGHT);
	win_image.img_data = mlx_get_data_addr(win_image.img_ptr,
			&win_image.bpp, &win_image.line_length, &win_image.endian);
	if (!win_image.img_data)
	{
		my_mlx_destroyer(data);
		throw_error("Error: mlx_get_data_addr failed", g_heap());
	}
	return (&win_image);
}
