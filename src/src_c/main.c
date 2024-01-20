/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:26:33 by jlara-na          #+#    #+#             */
/*   Updated: 2024/01/20 20:49:33 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

/*
static void	leak(void)
{
	system("leaks -q client");
}
atexit(leak);
*/

void	terminate(char *error_msg)
{
	ft_putendl_fd(error_msg, 2);
	ft_putstr_fd(DEF_COLOR, 2);
	exit(EXIT_SUCCESS);
}

int	check_input(int argc, char **args)
{
	int	pid;

	if (argc != 3)
	{
		msg_c(3, NULL);
		terminate(ERROR_ARG_NUM);
	}
	pid = ft_atoi(args[1]);
	if (pid <= 0)
	{
		msg_c(3, NULL);
		terminate(ERROR_ARG_PID);
	}
	return (pid);
}

static void	signal_handler(int signum, siginfo_t	*info, void *x)
{
	char	*pid;

	(void)x;
	(void)info;
	if (signum == SIGUSR1)
	{
		pid = ft_itoa(info->si_pid);
		msg_c(2, pid);
		free(pid);
	}
	else if (signum == SIGUSR2)
		terminate(SERVER_BUSY);
	exit (0);
}

int	main(int argc, char **args)
{
	int					pid;
	struct sigaction	sigact;
	char				*cpid;

	sigact.sa_sigaction = signal_handler;
	sigact.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	pid = check_input(argc, args);
	cpid = ft_itoa(getpid());
	msg_c(1, cpid);
	free(cpid);
	msg_sender(pid, args[2]);
	msg_c(0, NULL);
	return (0);
}
