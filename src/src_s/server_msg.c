/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:45:36 by jlara-na          #+#    #+#             */
/*   Updated: 2024/01/15 18:24:38 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

static void	server_msg(void)
{
	ft_putendl_fd(CLEAR, 1);
	ft_putendl_fd(MAGENTA, 1);
	ft_putstr_fd(BORDER, 1);
	ft_putstr_fd(BORDER, 1);
	ft_putendl_fd(DEF_COLOR, 1);
	ft_putendl_fd(BLUE, 1);
	ft_putendl_fd(JLARA_NA, 1);
	ft_putendl_fd(GREEN, 1);
	ft_putstr_fd(SERVER_UP_MSG, 1);
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
	ft_putendl_fd(MAGENTA, 1);
	ft_putstr_fd(BORDER, 1);
	ft_putstr_fd(BORDER, 1);
	ft_putendl_fd(DEF_COLOR, 1);
}

static void	arrow_msg(char *pid)
{
	ft_putendl_fd(YELLOW, 1);
	ft_putstr_fd(CLIENT_NAME, 1);
	ft_putstr_fd(pid, 1);
	ft_putstr_fd(MAGENTA_B, 1);
	ft_putstr_fd(ARROW_MSG, 1);
	ft_putstr_fd(WHITE, 1);
}

int	msg(int code, char *pid)
{
	if (code == 0)
		server_msg();
	if (code == 1)
		pid_msg(pid);
	if (code == 2)
		arrow_msg(pid);
	return (1);
}
