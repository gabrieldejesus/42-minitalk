/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-jesu <gde-jesu@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:03:14 by gde-jesu          #+#    #+#             */
/*   Updated: 2023/09/27 11:27:40 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_flag_x(unsigned long number, char select)
{
	unsigned long	lenght;
	int				cap;

	cap = 0;
	lenght = 0;
	if (select == 'x')
		cap = 32;
	if (number >= 16)
		lenght += ft_flag_x(number / 16, select);
	if (number % 16 >= 10)
		lenght = lenght + ft_putchar(((number % 16) - 10) + ('A' + cap));
	else
		lenght += ft_putchar((number % 16) + '0');
	return (lenght);
}
