/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:12:15 by mel-yous          #+#    #+#             */
/*   Updated: 2022/11/01 23:02:35 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;
	size_t	q;
	size_t	i;

	slen = ft_strlen(src);
	if (dst == NULL && dstsize == 0)
		return (slen);
	dlen = ft_strlen(dst);
	q = dlen;
	i = 0;
	if (dstsize <= dlen)
		return (slen + dstsize);
	if (dstsize > dlen)
	{
		while (src[i] != '\0' && i < (dstsize - dlen - 1))
		{
			dst[q] = src[i];
			q++;
			i++;
		}
		dst[q] = '\0';
	}
	return (dlen + slen);
}
