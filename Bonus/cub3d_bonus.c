/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:30:07 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/29 10:53:28 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	check_extension(char *path)
{
	char	*str;

	str = ft_strchr(path, '.');
	if (!str)
		throw_error(EXTENSION_ERROR, NULL);
	if (ft_strcmp(str, ".cub"))
		throw_error(EXTENSION_ERROR, NULL);
}

int	close_game(t_data *data)
{
	my_mlx_destroyer(data);
	empty_trash(g_heap());
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		throw_error(ARGS_ERROR, NULL);
	check_extension(argv[1]);
	init_data(&data, argv[1]);
	clear_window_draw(&data);
	knife_animation(&data);
	mlx_mouse_hook(data.mlx->win_ptr, mouse_hook, &data);
	mlx_hook(data.mlx->win_ptr, 17, 0, close_game, &data);
	mlx_hook(data.mlx->win_ptr, 2, 0, key_press, &data);
	mlx_hook(data.mlx->win_ptr, 3, 0, key_release, &data);
	mlx_hook(data.mlx->win_ptr, 6, 0, mouse_rotation, &data);
	mlx_loop_hook(data.mlx->mlx_ptr, move_player, &data);
	mlx_loop(data.mlx->mlx_ptr);
	empty_trash(g_heap());
	return (0);
}
