/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shirama <shirama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:22:14 by shirama           #+#    #+#             */
/*   Updated: 2021/05/31 22:28:18 by shirama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	recieve_sucess(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
	ft_putstr_fd("Message has been sent\n", 1);
}

void	send_message(pid_t pid, char c)
{
	int		i;

	i = 1 << 6;
	while (i > 0)
	{
		if (c & i)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr_fd("Invalid pid\n", 2);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr_fd("Invalid pid\n", 2);
				exit(1);
			}
		}
		i >>= 1;
		usleep(600);
	}
}

int	main(int argc, char **argv)
{
	int					i;
	pid_t				pid;
	struct sigaction	sa_sigusr1;

	sa_sigusr1.sa_sigaction = recieve_sucess;
	sa_sigusr1.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa_sigusr1, NULL);
	if (argc != 3)
	{
		ft_putstr_fd("Invalid args\n", 2);
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		send_message(pid, argv[2][i]);
		i++;
	}
	send_message(pid, '\0');
	return (0);
}
