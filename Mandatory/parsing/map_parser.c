/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:19:25 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/28 12:21:57 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static bool	top_bottom_closed(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

static bool	is_closed(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (i == 0 && str[i] != '1' && str[i] != ' ')
			return (false);
		else if (i == len - 1 && str[i] != '1' && str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

static void	space_checker(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (j > 0 && j < (int)ft_strlen(map[i]) - 1
				&& (map[i][j] == '0' || is_player(map[i][j])))
				if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
					throw_error(MAP_NOT_CLOSED, g_heap());
			if (i > 0 && i < tab_size(map) - 1
				&& (map[i][j] == '0' || is_player(map[i][j])))
				if ((j >= (int)ft_strlen(map[i - 1]) || map[i - 1][j] == ' ')
				|| (j >= (int)ft_strlen(map[i + 1]) || map[i + 1][j] == ' '))
					throw_error(MAP_NOT_CLOSED, g_heap());
			j++;
		}
		i++;
	}
}

void	map_checker(char **map)
{
	int	i;
	int	p;
	int	map_size;

	i = 0;
	p = 0;
	map_size = tab_size(map);
	while (map[i])
	{
		if ((i == 0 || i == map_size - 1) && !top_bottom_closed(map[i]))
			throw_error(MAP_NOT_CLOSED, g_heap());
		else if (i != 0 && i != map_size - 1 && !is_closed(map[i]))
			throw_error(MAP_NOT_CLOSED, g_heap());
		if (contains_bad_char(map[i]))
			throw_error(BAD_CHAR_ERROR, g_heap());
		contains_player(map[i], &p);
		i++;
	}
	if (p != 1)
		throw_error(PLAYER_ERROR, g_heap());
	space_checker(map);
}
