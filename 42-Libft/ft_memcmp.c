/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-jesu <gde-jesu@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:43:52 by gde-jesu          #+#    #+#             */
/*   Updated: 2023/09/02 11:13:20 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*var1;
	unsigned char	*var2;

	var1 = (unsigned char *)(s1);
	var2 = (unsigned char *)(s2);
	if (n == 0)
		return (0);
	while (n != 0)
	{
		if (*var1 != *var2)
			return (*var1 - *var2);
		var1++;
		var2++;
		n--;
	}
	return (0);
}
