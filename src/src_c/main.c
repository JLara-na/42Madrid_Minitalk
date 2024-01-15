/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:26:33 by jlara-na          #+#    #+#             */
/*   Updated: 2024/01/15 18:46:37 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

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
		msg(3, NULL);
		terminate(ERROR_ARG_NUM);
	}
	pid = ft_atoi(args[1]);
	if (pid <= 0)
	{
		msg(3, NULL);
		terminate(ERROR_ARG_PID);
	}
	return (pid);
}

//static void	signal_handler(int signum)
static void	signal_handler(int signum, siginfo_t	*info, void *x)
{
	(void)x;
	(void)info;
	if (signum == SIGUSR1)
		msg(2, ft_itoa(info->si_pid));
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
	msg(1, cpid);
	msg_sender(pid, args[2]);
	msg(0, NULL);
	return (0);
}
