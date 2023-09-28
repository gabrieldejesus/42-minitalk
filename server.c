/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-jesu <gde-jesu@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:51:27 by gde-jesu          #+#    #+#             */
/*   Updated: 2023/09/28 10:19:39 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_byte_to_char(int byte, siginfo_t *info)
{
	int	num;
	int	dec_value;
	int	base1;
	int	temp;
	int	last_digit;

	num = byte;
	dec_value = 0;
	base1 = 1;
	temp = num;
	while (temp > 0)
	{
		last_digit = temp % 10;
		temp = temp / 10;
		dec_value += last_digit * base1;
		base1 = base1 * 2;
	}
	ft_printf("%c", dec_value);
	if (dec_value == 0)
		kill(info->si_pid, SIGUSR2);
}

void	join_bit(unsigned char num, siginfo_t *info)
{
	static char	c[9];
	static int	counter;

	c[counter] = num;
	counter++;
	if (counter == 8)
	{
		c[counter++] = '\0';
		convert_byte_to_char(ft_atoi(c), info);
		counter = 0;
	}
	usleep(150);
	kill(info->si_pid, SIGUSR1);
}

void	handler_sigusr(int signum, siginfo_t *info)
{
	if (signum == SIGUSR1)
		join_bit('0', info);
	else if (signum == SIGUSR2)
		join_bit('1', info);
}

int	main(void)
{
	pid_t				pid_id;
	struct sigaction	struct1;

	struct1.sa_handler = (void *)handler_sigusr;
	sigemptyset(&struct1.sa_mask);
	struct1.sa_flags = 0;
	pid_id = getpid();
	ft_printf("✅ Pid: %d\n", pid_id);
	sigaction(SIGUSR1, &struct1, NULL);
	sigaction(SIGUSR2, &struct1, NULL);
	while (1)
		pause();
}