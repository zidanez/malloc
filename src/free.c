/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:40:05 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/04 16:35:51 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		free(void *addr)
{
	t_blk	*blk;
	t_blk	*blk_pre;

	if (addr == NULL || !(is_our_blok(addr)))
		return ;
	blk = GET_BLOCK(addr);
	blk->is_free = TRUE;
	blk_pre = blk->prev;
	if (blk_pre != NULL && blk_pre->is_free)
	{
		blk_pre->size += blk->size + BLK_SIZE;
		blk_pre->next = blk->next;
		blk_pre->next->prev = blk_pre;
		blk = blk_pre;
	}
	if (blk->next != NULL && blk->next->is_free)
	{
		blk->size += blk->next->size + BLK_SIZE;
		blk->next = blk->next->next;
		if (blk->next != NULL)
			blk->next->prev = blk;
	}
	free_heap(blk);
}
