/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-jesu <gde-jesu@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:23:08 by gde-jesu          #+#    #+#             */
/*   Updated: 2023/09/27 11:27:45 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_flag(va_list args, char c)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter += ft_putchar(va_arg(args, int));
	if (c == 's')
		counter += ft_flag_s(args);
	if (c == 'p')
		counter += ft_flag_p(va_arg(args, unsigned long));
	if (c == 'd' || c == 'i')
		counter += ft_flags_di(va_arg(args, int));
	if (c == 'u')
		counter += ft_flag_u(va_arg(args, unsigned int));
	if (c == 'x')
		counter += ft_flag_x(va_arg(args, unsigned int), c);
	if (c == 'X')
		counter += ft_flag_x(va_arg(args, unsigned int), c);
	if (c == '%')
		counter += ft_putchar('%');
	return (counter);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
			print_length += check_flag(args, string[++i]);
		else
			print_length += ft_putchar(string[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
