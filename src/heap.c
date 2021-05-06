/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:03:38 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/06 15:20:32 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_heap	*init_heap(t_heap *pre_heap, void *addr, size_t size_heap, size_t size)
{
	t_heap	*new_heap;

	new_heap = (t_heap *)addr;
	new_heap->start = (t_blk *)(addr + HEAP_SIZE);
	new_heap->type = get_heap_type(size);
	new_heap->next = NULL;
	new_heap->size = size_heap;
	if (pre_heap != NULL)
	{
		new_heap->prev = pre_heap;
		pre_heap->next = new_heap;
	}
	new_heap->start->data = addr + HEAP_SIZE + BLK_SIZE;
	new_heap->start->is_free = TRUE;
	new_heap->start->size = size_heap - HEAP_SIZE - BLK_SIZE;
	new_heap->start->next = NULL;
	new_heap->start->prev = NULL;
	return (new_heap);
}

t_blk	*create_heap(t_heap *pre_hip, size_t size)
{
	void			*addr;
	t_heap			*heap;
	const size_t	heap_size = get_heap_size(size);

	addr = mmap(
			0, heap_size, \
			PROT_READ | PROT_WRITE, \
			MAP_ANON | MAP_PRIVATE, \
			-1, 0);
	if (addr == MAP_FAILED)
		return (NULL);
	heap = init_heap(pre_hip, addr, heap_size, size);
	return (heap->start);
}

void	free_heap(t_blk *blk)
{
	t_heap	*heap;
	t_heap	*pre_heap;

	if (blk->prev == NULL && blk->next == NULL)
	{
		heap = (void *)blk - HEAP_SIZE;
		if (heap->prev)
		{
			pre_heap = heap->prev;
			pre_heap->next = heap->next;
			if (heap->next)
				heap->next->prev = pre_heap;
		}
		else
			g_heap = NULL;
		munmap(heap, heap->size);
	}
}
