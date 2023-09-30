/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_getter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:50:46 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/17 15:25:33 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*get_player_coord(char **map)
{
	static int	coord[2];
	int			i;
	int			j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player(map[i][j]))
				return (coord[0] = j, coord[1] = i, coord);
			j++;
		}
		i++;
	}
	return (NULL);
}

int	get_map_width(char **map)
{
	static int	width;
	int			len;

	if (!*map)
		return (width);
	len = ft_strlen(*map);
	if (len > width)
		width = len;
	return (get_map_width(map + 1));
}

int	get_map_height(char **map)
{
	static int	height;

	if (!*map)
		return (height);
	height++;
	return (get_map_height(map + 1));
}
