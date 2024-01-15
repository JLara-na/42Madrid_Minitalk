/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_sender.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:23:03 by jlara-na          #+#    #+#             */
/*   Updated: 2024/01/15 17:46:29 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

static int	signal_sender(int pid, char ch)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if (ch >> j & 1)
		{
			if (kill(pid, SIGUSR1) != 0)
				terminate(ERROR_SIG);
		}
		else if (kill(pid, SIGUSR2) != 0)
			terminate(ERROR_SIG);
		j--;
		usleep(300);
	}
	return (1);
}

void	msg_sender(int pid, char *msg)
{
	size_t	x;
	size_t	len;

	x = 0;
	if (msg[0] == '\0')
	{
		ft_putendl_fd(ARG_HELP, 1);
		terminate(ERROR_EMPTY_MSG);
	}
	len = ft_strlen(msg);
	while (len != x)
	{
		signal_sender(pid, msg[x]);
		x++;
	}
	signal_sender(pid, '\n');
	signal_sender(pid, '\0');
}
