/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-jesu <gde-jesu@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:42:40 by gde-jesu          #+#    #+#             */
/*   Updated: 2023/09/02 10:54:30 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	int		len;

	len = ft_strlen(s1) + 1;
	tmp = malloc(len);
	if (tmp)
		ft_memcpy(tmp, s1, len);
	return (tmp);
}
