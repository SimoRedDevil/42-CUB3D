/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:30:07 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/29 09:43:25 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_extension(char *path)
{
	char	*str;

	str = ft_strchr(path, '.');
	if (!str)
		throw_error(EXTENSION_ERROR, NULL);
	if (ft_strcmp(str, ".cub"))
		throw_error(EXTENSION_ERROR, NULL);
}

static int	close_game(t_data *data)
{
	my_mlx_destroyer(data);
	empty_trash(g_heap());
	exit(0);
}

static int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_game(data);
	else if (keycode == KEY_W)
		data->flags->move_up = true;
	else if (keycode == KEY_S)
		data->flags->move_down = true;
	else if (keycode == KEY_A)
		data->flags->move_left = true;
	else if (keycode == KEY_D)
		data->flags->move_right = true;
	else if (keycode == KEY_LEFT)
		data->flags->rotate_left = true;
	else if (keycode == KEY_RIGHT)
		data->flags->rotate_right = true;
	return (0);
}

static int	key_release(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_game(data);
	if (keycode == KEY_W)
		data->flags->move_up = false;
	if (keycode == KEY_S)
		data->flags->move_down = false;
	if (keycode == KEY_A)
		data->flags->move_left = false;
	if (keycode == KEY_D)
		data->flags->move_right = false;
	if (keycode == KEY_LEFT)
		data->flags->rotate_left = false;
	if (keycode == KEY_RIGHT)
		data->flags->rotate_right = false;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		throw_error(ARGS_ERROR, NULL);
	check_extension(argv[1]);
	init_data(&data, argv[1]);
	clear_window_draw(&data);
	mlx_hook(data.mlx->win_ptr, 17, 0, close_game, &data);
	mlx_hook(data.mlx->win_ptr, 2, 0, key_press, &data);
	mlx_hook(data.mlx->win_ptr, 3, 0, key_release, &data);
	mlx_loop_hook(data.mlx->mlx_ptr, move_player, &data);
	mlx_loop(data.mlx->mlx_ptr);
	empty_trash(g_heap());
	return (0);
}
