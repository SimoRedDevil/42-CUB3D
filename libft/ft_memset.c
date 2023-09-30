/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:21:21 by mel-yous          #+#    #+#             */
/*   Updated: 2022/11/02 18:43:31 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptrb;
	size_t			i;

	ptrb = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptrb[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
