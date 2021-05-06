/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:06:34 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/06 13:48:52 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t	get_heap_size(size_t size)
{
	if (size < TYNY_MAX_ALLOC)
		return (TINY_SIZE);
	if (size < SMALL_MAX_ALLOC)
		return (SMALL_SIZE);
	return (PAGE_SIZE * ((LARGE_SIZE(size) / PAGE_SIZE) + 1));
}

t_heap_type	get_heap_type(size_t size)
{
	if (size < TYNY_MAX_ALLOC)
		return (TYNY);
	if (size < SMALL_MAX_ALLOC)
		return (SMALL);
	return (LARGE);
}

char	*get_heap_name(int type)
{
	if (type == TYNY)
		return ("TINY");
	else if (type == SMALL)
		return ("SMALL");
	return ("LARGE");
}
