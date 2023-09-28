/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-jesu <gde-jesu@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 20:02:33 by gde-jesu          #+#    #+#             */
/*   Updated: 2023/09/28 10:17:42 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_char_to_bit(unsigned char octet, pid_t pid)
{
	int	counter;

	counter = 8;
	while (counter-- > 0)
	{
		if (!(octet & 0x80))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		octet = octet << 1;
		pause();
		usleep(150);
	}
}

void	handler_sigusr(int signum)
{
	if (signum == SIGUSR1)
		return ;
	else if (signum == SIGUSR2)
		ft_printf("%s\n", "ℹ️  Signal received");
}

int	main(int argc, char *argv[])
{	
	int		counter;
	pid_t	pid;

	counter = 0;
	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	while (argv[2][counter])
	{
		convert_char_to_bit(argv[2][counter], pid);
		counter++;
	}
	convert_char_to_bit(argv[2][counter], pid);
	return (0);
}