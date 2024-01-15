/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:19:29 by jlara-na          #+#    #+#             */
/*   Updated: 2024/01/15 18:49:26 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

static void	client_msg(void)
{
	ft_putendl_fd(CLEAR, 1);
	ft_putstr_fd(GREEN, 1);
	ft_putstr_fd(CLIENT_SEND, 1);
	ft_putstr_fd(GREEN_B, 1);
	ft_putendl_fd(DOTS, 1);
	ft_putendl_fd(DEF_COLOR, 1);
}

static	void	pid_msg(char *pid)
{
	ft_putstr_fd(YELLOW, 1);
	ft_putstr_fd(PID_MSG, 1);
	ft_putstr_fd(DEF_COLOR, 1);
	ft_putendl_fd(pid, 1);
}

static void	check_msg(char *pid)
{
	ft_putstr_fd(GREEN, 1);
	ft_putstr_fd(MSG_RECIVED, 1);
	ft_putstr_fd(pid, 1);
	ft_putstr_fd(DEF_COLOR, 1);
}

static void	help_msg(void)
{
	ft_putendl_fd(CLEAR, 1);
	ft_putendl_fd(YELLOW, 1);
	ft_putendl_fd(ARG_HELP, 1);
	ft_putendl_fd(ARG_HELP_1, 1);
	ft_putendl_fd(DEF_COLOR, 1);
}

int	msg(int code, char *pid)
{
	if (code == 0)
		client_msg();
	if (code == 1)
		pid_msg(pid);
	if (code == 2)
		check_msg(pid);
	if (code == 3)
		help_msg();
	return (1);
}
