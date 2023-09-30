/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:25:40 by mel-yous          #+#    #+#             */
/*   Updated: 2022/10/29 11:33:53 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*ptrj;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ptrj = (char *)malloc(s1len + s2len + 1);
	if (ptrj == NULL)
		return (NULL);
	ft_memcpy(ptrj, s1, s1len);
	ft_memcpy(ptrj + s1len, s2, s2len + 1);
	return (ptrj);
}
