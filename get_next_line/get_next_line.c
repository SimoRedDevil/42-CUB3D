/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:03:34 by aben-nei          #+#    #+#             */
/*   Updated: 2022/11/13 20:36:41 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *string)
{
	char	*beffer;
	ssize_t	nbyte;

	beffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!beffer)
		return (NULL);
	while (!ft_strchr_gnl(string, '\n'))
	{
		nbyte = read(fd, beffer, BUFFER_SIZE);
		if (nbyte < 0)
			return (free(beffer), free(string), NULL);
		beffer[nbyte] = '\0';
		string = ft_strjoin_gnl(string, beffer);
		if (!string)
			return (free(beffer), NULL);
		else if (nbyte == 0 && string[0] == '\0')
			return (free(beffer), free(string), NULL);
		else if (nbyte == 0)
			return (free(beffer), string);
	}
	return (free(beffer), string);
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		*line;
	char		*tmp;
	size_t		i1;
	size_t		i2;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	string = read_line(fd, string);
	i1 = ft_strlen_gnl(string, '\0');
	i2 = ft_strlen_gnl(string, '\n');
	tmp = string;
	line = ft_substr_gnl(string, 0, i2 + 1);
	string = ft_substr_gnl(string, i2 + 1, (i1 - i2));
	free(tmp);
	return (line);
}
