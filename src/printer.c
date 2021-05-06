/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:33:51 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/06 15:21:38 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	print_heap_info(const t_heap *heap)
{
	ft_putstr("\n");
	ft_putstr(get_heap_name(heap->type));
	ft_putstr(": ");
	ft_put_addr((void *)heap);
	ft_putstr("\n");
}

static void	print_block_more_info(t_blk *blk)
{
	char	*str0;
	char	*str1;

	str0 = "|||||||||||||||";
	str1 = "...............";
	ft_put_addr((void *)blk);
	ft_putstr("\t\t");
	ft_put_addr((void *)blk->data);
	if (blk->is_free)
		ft_putstr(str1);
	else
		ft_putstr(str0);
	ft_put_addr((void *)(blk->data + blk->size));
	ft_putstr("\t\t");
	ft_putnbr(blk->size);
	ft_putstr("\n");
}

void	show_alloc_mem_ex(const t_heap *heap)
{
	t_blk	*blk;

	while (heap)
	{
		print_heap_info(heap);
		blk = heap->start;
		while (blk)
		{
			print_block_more_info(blk);
			blk = blk->next;
		}
		heap = heap->next;
	}
}

void	show_alloc_mem(const t_heap *heap)
{
	t_blk	*blk;
	size_t	total;
	char	*bytes;

	total = 0;
	while (heap)
	{
		print_heap_info(heap);
		blk = heap->start;
		while (blk)
		{
			if (blk->is_free == FALSE)
			{
				print_block_info(blk);
				total = total + blk->size;
			}
			blk = blk->next;
		}
		heap = heap->next;
	}
	ft_putstr("\nTotal: ");
	ft_putnbr(total);
	ft_putstr(" bytes\n");
}
