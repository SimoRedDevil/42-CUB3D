/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:27:18 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/29 10:53:28 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	load_put_image(t_data *data, char *dir, char *frame)
{
	void	*image;
	int		width;
	int		height;
	char	path[60];
	t_mlx	*mlx;

	mlx = data->mlx;
	ft_strlcpy(path, dir, 60);
	ft_strlcat(path, frame, 60);
	image = my_mlx_xpm_file_to_img(data, path, &width, &height);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, image, 30, 0);
	mlx_destroy_image(mlx->mlx_ptr, image);
}

void	play_sound(char *sound_path)
{
	int		fd;
	pid_t	pid;
	char	*cmd;

	fd = open(sound_path, O_RDONLY);
	if (fd == -1)
		return ;
	close(fd);
	cmd = "afplay ";
	pid = fork();
	if (pid == 0)
	{
		cmd = ft_strjoin(cmd, sound_path);
		system(cmd);
		free(cmd);
		exit(0);
	}
}
