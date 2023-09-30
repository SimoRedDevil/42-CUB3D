/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:28:27 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/28 12:19:01 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	add_to_textures(t_texture **t, char *key, char *value)
{
	t_texture	*new;

	new = malloc(sizeof(t_texture));
	if (!new)
		throw_error("Error: malloc failed", g_heap());
	add_to_garbage(g_heap(), new);
	new->key = key;
	new->value = value;
	new->next = NULL;
	new->last = NULL;
	if (!*t)
	{
		*t = new;
		(*t)->last = new;
		(*t)->next = NULL;
	}
	else
	{
		(*t)->last->next = new;
		new->last = (*t)->last;
		(*t)->last = new;
	}
}

void	fill_tetxures_list(t_data *data, char *key, char *value)
{
	if (key && (!ft_strcmp(key, "NO") || !ft_strcmp(key, "SO")
			|| !ft_strcmp(key, "WE") || !ft_strcmp(key, "EA")))
		add_to_textures(&data->textures, key, value);
}

void	textures_checker(t_data	*data)
{
	static int	state[4] = {0, 0, 0, 0};
	t_texture	*tmp;
	int			fd;

	tmp = data->textures;
	while (tmp)
	{
		fd = open(tmp->value, O_RDONLY);
		if (!ft_strcmp(tmp->key, "NO") && fd != -1)
			state[0] = 1;
		else if (!ft_strcmp(tmp->key, "SO") && fd != -1)
			state[1] = 1;
		else if (!ft_strcmp(tmp->key, "WE") && fd != -1)
			state[2] = 1;
		else if (!ft_strcmp(tmp->key, "EA") && fd != -1)
			state[3] = 1;
		close(fd);
		tmp = tmp->next;
	}
	if (!state[0] || !state[1] || !state[2] || !state[3])
		throw_error(TEXTURE_ERROR, g_heap());
}
