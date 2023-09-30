/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_collector_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:08:18 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/29 10:53:28 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	add_to_garbage(t_garbage **heap, void *address)
{
	t_garbage	*new;

	new = malloc(sizeof(t_garbage));
	if (!new)
		throw_error("Error: malloc failed", NULL);
	new->address = address;
	new->next = NULL;
	new->last = NULL;
	if (!*heap)
	{
		*heap = new;
		(*heap)->next = NULL;
		(*heap)->last = new;
		return ;
	}
	(*heap)->last->next = new;
	(*heap)->last = new;
}

void	empty_trash(t_garbage **heap)
{
	t_garbage	*tmp;
	t_garbage	*head;

	if (!heap || !*heap)
		return ;
	head = *heap;
	while (head)
	{
		tmp = head;
		free(head->address);
		head = head->next;
		free(tmp);
	}
}

t_garbage	**g_heap(void)
{
	static t_garbage	*heap;

	return (&heap);
}
