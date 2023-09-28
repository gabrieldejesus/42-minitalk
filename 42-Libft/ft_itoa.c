/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-jesu <gde-jesu@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 07:04:07 by gde-jesu          #+#    #+#             */
/*   Updated: 2023/09/02 10:57:27 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenght(long int number)
{
	int	lenght;

	lenght = 0;
	if (number <= 0)
	{
		number = number * -1;
		lenght++;
	}
	while (number > 0)
	{
		number = number / 10;
		lenght++;
	}
	return (lenght);
}

static	char	*if_zero(char *string)
{
	string[0] = '0';
	return (string);
}

char	*ft_itoa(int n)
{
	char		*string;
	long int	counter;
	long int	number;

	number = n;
	counter = lenght(number);
	string = (char *) malloc(sizeof(char) * (counter + 1));
	if (string == NULL)
		return (NULL);
	string[counter--] = '\0';
	if (number == 0)
		if_zero(string);
	if (number < 0)
	{
		string[0] = '-';
		number = number * -1;
	}
	while (number > 0)
	{
		string[counter--] = 48 + (number % 10);
		number = number / 10;
	}
	return (string);
}
