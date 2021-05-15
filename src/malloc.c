/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:39:46 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/15 12:31:39 by fnancy           ###   ########.fr       */
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
