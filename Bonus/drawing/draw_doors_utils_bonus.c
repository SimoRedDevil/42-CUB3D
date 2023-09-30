/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_doors_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:30:49 by aben-nei          #+#    #+#             */
/*   Updated: 2023/09/29 10:53:28 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	get_pos_door(t_data *data, t_door *doors, int *k)
{
	static int	i;
	int			j;

	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == 'D')
			{
				doors[(*k)].x = j;
				doors[(*k)].y = i;
				(*k)++;
			}
			j++;
		}
		i++;
	}
}

void	filed_door(t_data *data, t_door *doors)
{
	int	i;

	i = 0;
	while (i < data->num_door)
	{
		doors[i].open_door = 1;
		get_pos_door(data, doors, &i);
	}
}

int	num_of_door(t_data *data)
{
	int	i;
	int	num_door;

	i = 0;
	num_door = 0;
	while (i < data->map_height)
		ft_strchr1(data->map[i++], 'D', &num_door);
	return (num_door);
}

int	match_door(int num_door, t_door *door, int x1, int y1)
{
	int	i;

	i = 0;
	while (i < num_door)
	{
		if (door[i].x == x1 && door[i].y == y1)
			return (i);
		i++;
	}
	return (0);
}

void	init_door(t_data *data)
{
	t_door	*doors;

	data->num_door = num_of_door(data);
	doors = malloc(sizeof(t_door) * data->num_door);
	if (!doors)
		throw_error(MALLOC_ERROR, g_heap());
	add_to_garbage(g_heap(), doors);
	filed_door(data, doors);
	data->doors = doors;
}
