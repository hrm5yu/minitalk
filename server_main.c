/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shirama <shirama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 22:27:52 by shirama           #+#    #+#             */
/*   Updated: 2021/05/30 22:19:20 by shirama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "minitalk.h"

#define	BUFFER_SIZE 1024

typedef struct s_info
{
	char	message[BUFFER_SIZE];
	int		bytes;
	int		bits;
	int		all_recieved;
	int		buf_overflow;
}				t_info;

t_info	g_info;

void	setbit(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
	if (!g_info.bits)
	{
		g_info.bits = 1 << 6;
		g_info.bytes++;
	}
	g_info.message[g_info.bytes] += g_info.bits;
	g_info.bits >>= 1;
	if (g_info.bytes == BUFFER_SIZE - 1 && !g_info.bits)
	{
		g_info.buf_overflow = 1;
		g_info.bytes = 0;
	}
}

void	setbit_null(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
	if (!g_info.bits)
	{
		g_info.bits = 1 << 6;
		g_info.bytes++;
	}
	g_info.bits >>= 1;
	if (g_info.message[g_info.bytes] == '\0' && g_info.bits == 0)
	{
		g_info.all_recieved = 1;
		kill(info->si_pid, SIGUSR1);
	}
	else if (g_info.bytes == BUFFER_SIZE - 1 && !g_info.bits)
	{
		g_info.buf_overflow = 1;
		g_info.bytes = 0;
	}
}

void	main_handler(void)
{
	while (1)
	{
		pause();
		if (g_info.all_recieved || g_info.buf_overflow)
		{
			g_info.bits = 1 << 6;
			g_info.bytes = 0;
			write(1, g_info.message, ft_strlen(g_info.message));
			if (g_info.all_recieved)
				write(1, "\n", 1);
			ft_bzero(g_info.message, BUFFER_SIZE);
			g_info.all_recieved = 0;
			g_info.buf_overflow = 0;
		}
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa_sigusr1;
	struct sigaction	sa_sigusr2;

	g_info.bits = 1 << 6;
	sa_sigusr1.sa_sigaction = setbit;
	sa_sigusr2.sa_sigaction = setbit_null;
	sa_sigusr1.sa_flags = SA_SIGINFO;
	sa_sigusr2.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	if (sigaction(SIGUSR1, &sa_sigusr1, NULL) != 0)
		ft_putstr_fd("Signal error\n", 2);
	if (sigaction(SIGUSR2, &sa_sigusr2, NULL) != 0)
		ft_putstr_fd("Signal error\n", 2);
	main_handler();
	return (0);
}
