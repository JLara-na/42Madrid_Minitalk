/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:26:33 by jlara-na          #+#    #+#             */
/*   Updated: 2024/01/15 18:57:22 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

void	terminate(char *error_msg)
{
	ft_putendl_fd(error_msg, 2);
	ft_putstr_fd(DEF_COLOR, 2);
	exit(EXIT_SUCCESS);
}

static int	check_pid(int pid, int incoming_pid)
{
	if (incoming_pid != pid)
	{
		if (kill(incoming_pid, SIGUSR2))
			terminate(ERROR_SIG);
		return (1);
	}
	return (0);
}

int	check_and_write(int pid, char ch)
{
	if (ch == '\0')
	{
		kill(pid, SIGUSR1);
		pid = 0;
	}
	else
		write(1, &ch, 1);
	return (pid);
}

static void	signal_handler(int signum, siginfo_t *info, void *x)
{
	static int	pid;
	static int	bit_count;
	static char	ch;

	(void)x;
	if (signum == SIGINT)
		terminate(SERVER_CLOSED);
	if (pid == 0)
	{
		pid = info->si_pid;
		msg(2, ft_itoa(pid));
	}
	if (check_pid(pid, info->si_pid) == 1)
		return ;
	if (signum == SIGUSR1)
		ch = ch | 128 >> bit_count;
	bit_count++;
	if (bit_count == 8)
	{
		pid = check_and_write(pid, ch);
		bit_count = 0;
		ch = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	char				*pid;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGINT, &sa, NULL);
	pid = ft_itoa(getpid());
	msg(0, pid);
	msg(1, pid);
	while (1)
		;
	return (0);
}
