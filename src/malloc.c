/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:39:46 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/06 15:21:13 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*malloc(size_t size)
{
	t_blk				*blk;
	const t_heap_type	type_heap = get_heap_type(size);

	if (size == 0)
		return (NULL);
	blk = find_free_block(type_heap, size);
	return (allocation_block(blk, size));
}

int main()
{
	char *ch = malloc(2);
	ch[0] = 'H';
	char *str = malloc(100);
	char *str2 = malloc(128);
	str2[127] = 'a';
	int *str4 = malloc(sizeof(int) * 4);
	str4[0] = 1258;

	str[98] = 'h';
	show_alloc_mem_ex(g_heap);
	// str = realloc(str,50);
	free(str);
	// str = malloc(50);
	printf("%s\n", str);
	show_alloc_mem_ex(g_heap);
	return (0);
}
