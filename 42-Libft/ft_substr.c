/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-jesu <gde-jesu@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:57:16 by gde-jesu          #+#    #+#             */
/*   Updated: 2023/09/17 19:30:18 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	max;

	if (!s)
		return (NULL);
	max = ft_strlen(s);
	i = 0;
	if (len > max)
		len = max;
	if (!s)
		return (NULL);
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	while ((start < max) && len)
	{
		sub[i++] = s[start++];
		len--;
	}
	sub[i] = '\0';
	return (sub);
}
