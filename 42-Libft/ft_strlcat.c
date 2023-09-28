/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-jesu <gde-jesu@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:44:13 by gde-jesu          #+#    #+#             */
/*   Updated: 2023/09/17 19:32:28 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	offset;
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	offset = dst_len;
	if (dst_len >= dstsize)
		return (src_len + dstsize);
	i = 0;
	if (dstsize > dst_len)
	{
		while (src[i] && i < (dstsize - dst_len) - 1)
		{
			dst[offset + i] = src[i];
			i++;
		}
	}
	dst[offset + i] = '\0';
	return (dst_len + src_len);
}
