/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:36:29 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/06 15:17:36 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/types.h>
# include <unistd.h>
# include <sys/mman.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"

# define PAGE_SIZE	((size_t)getpagesize())
# define BLK_SIZE	(sizeof(t_blk))
# define HEAP_SIZE	(sizeof(t_heap))

# define TINY_SIZE	(PAGE_SIZE * 4)
# define SMALL_SIZE	(PAGE_SIZE * 16)
# define LARGE_SIZE(size) ((size + HEAP_SIZE + (BLK_SIZE * 2)))

# define GET_BLOCK(addr) ((t_blk *)(addr - BLK_SIZE))
# define TYNY_MAX_ALLOC (TINY_SIZE / 128)
# define SMALL_MAX_ALLOC (SMALL_SIZE / 128)

typedef enum e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef enum e_heap_type
{
	TYNY,
	SMALL,
	LARGE
}				t_heap_type;

typedef struct s_blk
{
	struct s_blk	*next;
	struct s_blk	*prev;
	void			*data;
	size_t			size;
	t_bool			is_free;
}					t_blk;

typedef struct s_heap
{
	struct s_heap	*next;
	struct s_heap	*prev;
	t_blk			*start;
	size_t			size;
	t_heap_type		type;
}					t_heap;

t_heap				*g_heap;

void			free(void *ptr);
void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);

t_blk			*create_heap(t_heap *pre_hip, size_t size);
t_heap			*init_heap(t_heap *pre_heap, void *addr, size_t size_heap, \
					size_t size);
void			free_heap(t_blk *blk);
size_t			get_heap_size(size_t size);
t_heap_type		get_heap_type(size_t size);
char			*get_heap_name(int type);

void			*allocation_block(t_blk *blk, size_t size);
t_blk			*scrolling_blocks(t_blk *blk, size_t size);
t_blk			*find_free_block(t_heap_type type, size_t size);
t_bool			check_blk(t_heap *heap, t_blk *blk);
t_bool			is_our_blok(void *addr);

void			show_alloc_mem(const t_heap *heap);
void			show_alloc_mem_ex(const t_heap *heap);

void			print_block_info(t_blk	*blk);

#endif
