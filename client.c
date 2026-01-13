/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanuel- <cmanuel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 18:41:57 by cmanuel-          #+#    #+#             */
/*   Updated: 2025/08/13 16:42:03 by cmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

sig_atomic_t	g_signo_received = 0;

void	handler(int signo)
{
	if (signo == SIGUSR1)
		g_signo_received = 1;
	else if (signo == SIGUSR2)
		write(1, "Message received!\n", 18);
}

int	ft_atoi(const char *str)
{
	int	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res);
}

int	send_bit(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_signo_received = 0;
		if (c & (0x80 >> bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_signo_received)
			usleep(100);
		bit++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(1, "error!\n", 7);
		write(1, "use: ./client [PID] [MESSAGE]\n", 30);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 1)
		return (write(1, "error!\n", 7), 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (*argv[2])
	{
		send_bit(pid, *argv[2]);
		argv[2]++;
	}
	send_bit(pid, '\0');
	return (0);
}
