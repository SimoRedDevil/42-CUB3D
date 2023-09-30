/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:28:04 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/15 18:18:03 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

bool	contains_bad_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1'
			&& str[i] != ' ' && !is_player(str[i]))
			return (true);
		i++;
	}
	return (false);
}

void	contains_player(char *str, int *p)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_player(str[i]))
			(*p)++;
		i++;
	}
}
