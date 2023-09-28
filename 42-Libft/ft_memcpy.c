/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-jesu <gde-jesu@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:43:55 by gde-jesu          #+#    #+#             */
/*   Updated: 2023/09/02 10:53:58 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*csrc;
	char	*cdst;
	size_t	i;

	csrc = (char *)src;
	cdst = (char *)dst;
	if (!dst && !src && n > 0)
		return (0);
	i = 0;
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return ((void *)dst);
}
