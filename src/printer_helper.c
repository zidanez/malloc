/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:25:33 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/06 12:34:08 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	print_block_info(t_blk	*blk)
{
	ft_put_addr(blk->data);
	write(1, " - ", 3);
	ft_put_addr(blk->data + blk->size);
	write(1, " : ", 3);
	ft_putnbr(blk->size);
	ft_putstr(" bytes\n");
}
