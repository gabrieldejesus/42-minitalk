/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-jesu <gde-jesu@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:24:36 by gde-jesu          #+#    #+#             */
/*   Updated: 2023/09/02 10:56:42 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	start = 0;
	if (!s1)
		return (NULL);
	end = ft_strlen(s1);
	while ((s1[start] && ft_strchr(set, s1[start])))
		start++;
	while ((end > start && ft_strrchr(set, s1[end - 1])))
		end--;
	return (ft_substr(s1, start, (end - start)));
}
