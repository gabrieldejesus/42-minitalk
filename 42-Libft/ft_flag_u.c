/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-jesu <gde-jesu@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:31:43 by gde-jesu          #+#    #+#             */
/*   Updated: 2023/09/27 11:27:38 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_flag_u(unsigned int number)
{
	size_t	lenght;

	lenght = 0;
	if (number >= 10)
		lenght += ft_flag_u(number / 10);
	lenght += ft_putchar((number % 10) + '0');
	return (lenght);
}
