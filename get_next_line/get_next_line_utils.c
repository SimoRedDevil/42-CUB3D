/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:03:44 by aben-nei          #+#    #+#             */
/*   Updated: 2022/11/13 21:07:29 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_gnl(char *s)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = ft_strlen_gnl(s, '\0');
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen_gnl(char *str, char c)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

char	*ft_strchr_gnl(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	int		i;

	if (!s1)
		s1 = ft_strdup_gnl("");
	len_s1 = ft_strlen_gnl(s1, '\0');
	len_s2 = ft_strlen_gnl(s2, '\0');
	str = (char *)malloc((len_s1 + len_s2) + 1);
	if (!str)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	i = -1;
	while (s2[++i])
		str[len_s1 + i] = s2[i];
	str[len_s1 + i] = '\0';
	return (free(s1), str);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen_gnl(s, '\0'))
	{
		str = (char *)malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > ft_strlen_gnl(s, '\0'))
		len = ft_strlen_gnl(s, '\0');
	if (ft_strlen_gnl(s, '\0') - start < len)
		len = ft_strlen_gnl(s, '\0') - start;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && start <= ft_strlen_gnl(s, '\0'))
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
