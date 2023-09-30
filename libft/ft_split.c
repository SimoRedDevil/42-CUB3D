/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:50:06 by mel-yous          #+#    #+#             */
/*   Updated: 2022/11/02 13:28:51 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wc(char const *str, char sep, int *sep_count)
{
	size_t	i;
	size_t	len;
	size_t	count;

	i = 0;
	count = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		while (str[i] == sep)
		{
			i++;
			if (sep_count)
				(*sep_count)++;
		}
		if (str[i] != sep && str[i] != '\0')
			count++;
		while (str[i] != sep && str[i] != '\0')
			i++;
	}
	return (count);
}

static char	**ft_free(char **ptr, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(ptr[j]);
		ptr[j] = NULL;
		j++;
	}
	free(ptr);
	ptr = NULL;
	return (NULL);
}

static char	**ft_fill(char const *s, char c, char **spl, size_t wc)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	while (i < wc)
	{
		while (s[start] == c && s[start] != '\0')
			start++;
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		spl[i] = ft_substr(s, start, end - start);
		if (spl[i] == NULL)
			return (ft_free(spl, i));
		start = end;
		i++;
	}
	spl[i] = NULL;
	return (spl);
}

char	**ft_split(char const *s, char c, int *sep_count)
{
	char	**spl;
	size_t	wc;

	if (s == NULL)
		return (NULL);
	wc = ft_wc(s, c, sep_count);
	spl = (char **)malloc((wc + 1) * sizeof(char *));
	if (spl == NULL)
		return (NULL);
	return (ft_fill(s, c, spl, wc));
}
