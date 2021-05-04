/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:39:46 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/04 17:43:28 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			*malloc(size_t size)
{
	t_blk				*blk;
	const t_heap_type	type_heap = get_heap_type(size);

	if (size == 0)
		return (NULL);
	blk = find_free_block(type_heap, size);
	return (allocation_block(blk, size));
}

int 			main()
{
	char *ch = (char*)malloc(1);
	char *str = malloc(100);
		char *str2 = malloc(128);
			char *str3 = malloc(1000000);
					char *str4 = malloc(128);
	print_alloc_mem(g_heap);
	free(str4);
	*str4 = malloc(3300);
		print_alloc_mem(g_heap);
	return (0);
}

