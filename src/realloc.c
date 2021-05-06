/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:41:00 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/06 13:44:03 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	*re_allocation_here(t_blk *blk, t_blk *next, size_t size)
{
	t_blk			*new_blk;

	if (next->next == NULL)
	{
		new_blk = blk->data + size;
		new_blk->prev = blk;
		new_blk->next = NULL;
		new_blk->size = next->size - (size - blk->size);
		new_blk->data = blk->data + size + BLK_SIZE;
		new_blk->is_free = TRUE;
		blk->next = new_blk;
		blk->size = size;
	}
	else
	{
		blk->next = next->next;
		next->next->prev = blk;
		blk->size += next->size + BLK_SIZE;
	}
	return (blk->data);
}

static void	*re_allocation_move(t_blk *blk, size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	free(blk->data);
	return (ft_memcpy(ptr, blk->data, blk->size));
}

void	*realloc(void *addr, size_t size)
{
	t_blk	*blk;
	t_blk	*next_blk;

	if (size == 0)
	{
		free(addr);
		return (NULL);
	}
	if (!(is_our_blok(addr)))
		return (malloc(size));
	blk = GET_BLOCK(addr);
	if (blk->size >= size)
		return (addr);
	next_blk = blk->next;
	if (next_blk->is_free && (next_blk->size) >= (size - blk->size))
		return (re_allocation_here(blk, next_blk, size));
	else
		return (re_allocation_move(blk, size));
}
