/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:44:18 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/29 10:53:28 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	parse_texture_rgb(char *line, t_data *data)
{
	char	*key;
	char	*value;
	int		i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	key = ft_substr(line, 0, i);
	add_to_garbage(g_heap(), key);
	if (key && (ft_strcmp(key, "NO") && ft_strcmp(key, "SO")
			&& ft_strcmp(key, "EA") && ft_strcmp(key, "WE")
			&& ft_strcmp(key, "C") && ft_strcmp(key, "F")))
		throw_error("error\n", g_heap());
	while (line[i] && line[i] == ' ')
		i++;
	value = ft_substr(line, i, ft_strlen(line) - i - 1);
	if (!key || !value)
		throw_error(MALLOC_ERROR, g_heap());
	add_to_garbage(g_heap(), value);
	fill_tetxures_list(data, key, value);
	fill_color(data, key, value);
}

static void	parse_line(char *line, int index, t_data *data, char **joined)
{
	static bool	flag;

	if (index < 6)
		parse_texture_rgb(line, data);
	else
	{
		if (line[0] != '\n')
			flag = true;
		if (flag && line[0] == '\n')
		{
			free(*joined);
			throw_error(MAP_EMPTY_LINE, g_heap());
		}
		*joined = free_s1_join(*joined, line);
	}
}

static void	read_map_helper(t_data *data, int fd, char *joined)
{
	int	i;

	i = 0;
	close(fd);
	data->map = ft_split(joined, '\n', NULL);
	free(joined);
	if (!data->map || !data->map[0])
		throw_error("Error: map is empty", g_heap());
	while (data->map[i])
		add_to_garbage(g_heap(), data->map[i++]);
	add_to_garbage(g_heap(), data->map);
}

void	read_map(char *path, t_data *data)
{
	int		fd;
	int		i;
	char	*line;
	char	*joined;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		throw_error(FILE_ERROR, NULL);
	i = 0;
	joined = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (i < 6 && *line == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		parse_line(line, i, data, &joined);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	read_map_helper(data, fd, joined);
}
