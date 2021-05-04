/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:03:51 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/04 17:36:31 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_blk	*scrolling_blocks(t_blk *blk, size_t size)
{
	while (!(blk->is_free) || blk->size < size + BLK_SIZE)
	{
		blk = blk->next;
		if (!blk)
			return (NULL);
	}
	return (blk);
}

void	*allocation_block(t_blk *blk, size_t size)
{
	t_blk	*new_blk;

	if (blk == NULL)
		return (NULL);
	if (blk->next != NULL)
	{
		blk->is_free = FALSE;
		return (blk->data);
	}
	new_blk = blk->data + size;
	new_blk->data = blk->data + size + BLK_SIZE;
	new_blk->is_free = TRUE;
	new_blk->size = blk->size - size - BLK_SIZE;
	new_blk->prev = blk;
	new_blk->next = NULL;
	blk->size = size;
	blk->next = new_blk;
	blk->is_free = FALSE;
	return (blk->data);
}

t_blk	*find_free_block(t_heap_type type, size_t size)
{
	t_heap	*heap;
	t_blk	*blk;

	if (g_heap == NULL)
	{
		blk = create_heap(NULL, size);
		g_heap = (void*)blk - BLK_SIZE;
		return (blk);
	}
	heap = g_heap;
	while (heap)
	{
		if (heap->type == type)
		{
			if ((blk = scrolling_blocks(heap->start, size)) == NULL \
					&& heap->next == NULL)
				return (create_heap(heap, size));
			if (blk != NULL)
				return (blk);
		}
		if (heap->next == NULL)
			return (create_heap(heap, size));
		heap = heap->next;
	}
	return (NULL);
}

t_bool		check_blk(t_heap *heap, t_blk *blk)
{
	t_blk	*actual_blk;

	actual_blk = heap->start;
	while (actual_blk)
	{
		if (actual_blk == blk)
			return (TRUE);
		actual_blk = actual_blk->next;
	}
	return (FALSE);
}

t_bool			is_our_blok(void *addr)
{
	t_heap	*heap;
	void	*first_addr;
	void	*last_addr;

	heap = g_heap;
	if (addr == NULL)
		return (FALSE);
	while (heap)
	{
		first_addr = (void *)heap;
		last_addr = (void *)heap + heap->size;
		if (addr > first_addr && addr < last_addr)
			return (check_blk(heap, GET_BLOCK(addr)));
		heap = heap->next;
	}
	return (FALSE);
}

