/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-jesu <gde-jesu@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:44:33 by gde-jesu          #+#    #+#             */
/*   Updated: 2023/09/02 10:55:17 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*temp;

	temp = (char *) s;
	i = ft_strlen(temp);
	while (i >= 0)
	{
		if (temp[i] == (char)c)
			return (&temp[i]);
		i--;
	}
	return (NULL);
}
