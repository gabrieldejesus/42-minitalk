/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-jesu <gde-jesu@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:19:24 by gde-jesu          #+#    #+#             */
/*   Updated: 2023/09/27 11:27:33 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_flag_p(unsigned long number)
{
	size_t	lenght;

	lenght = 0;
	lenght += ft_putchar('0');
	lenght += ft_putchar('x');
	lenght += ft_flag_x(number, 'x');
	return (lenght);
}
