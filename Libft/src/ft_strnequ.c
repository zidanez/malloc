/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:47:34 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/03 16:02:58 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
	{
		if (ft_strncmp(s1, s2, n) == 0)
			return (1);
		else
			return (0);
	}
	return ((int) NULL);
}
