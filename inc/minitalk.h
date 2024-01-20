/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:29:09 by jlara-na          #+#    #+#             */
/*   Updated: 2024/01/20 20:50:33 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include "../lib/libft/libft.h"

//----------------DEFINES----------------//

# ifndef FALSE
#  define FALSE		0
# endif

# ifndef TRUE
#  define TRUE		1
# endif

//----------------COLORS-----------------//

# define CLEAR		"\033[2J\033[1;1H"
# define DEF_COLOR	"\033[0;39m"
# define GRAY		"\033[0;90m"
# define RED		"\033[0;91m"
# define RED_B		"\033[0;91;5m"
# define GREEN		"\033[0;92m"
# define GREEN_B	"\033[0;92;5m"
# define YELLOW		"\033[0;93m"
# define YELLOW_B	"\033[0;93;5m"
# define BLUE		"\033[0;94m"
# define MAGENTA	"\033[0;95m"
# define MAGENTA_B	"\033[0;95;5m"
# define CYAN		"\033[0;96m"
# define WHITE		"\033[0;97m"

//-----------------MSG-------------------//

# define SERVER_UP_MSG	"\u2705 Server up and runing"
# define SERVER_BUSY	"\u274C\033[93m The server is busy right now \033[0;93m"
# define DOTS			"..."
# define PID_MSG		"This process PID:	"
# define BORDER			"------------------------------------------"
# define ARG_HELP		"Input format: ./client (int PID) (char *MSG)"
# define ARG_HELP_1		"PID should never be 0 or less, the MSG cant be empty"
# define MSG_RECIVED	"\033[0;92m✔✔ MSG recibed at:	\033[0;39m"
# define ARROW_MSG		">"
# define CLIENT_SEND	"MSG sended to server"
# define CLIENT_NAME	"Client:"
# define JLARA_NA		"				Minitalk by JLara-Na"

//----------------ERRORS-----------------//

# define ERROR_ARG_NUM		"\u274C\033[91m Invalid argument numbers\033[0;93m"
# define ERROR_ARG_PID		"\u274C\033[91m Invalid PID\033[0;93m"
# define ERROR_EMPTY_MSG	"\u274C\033[91m Empty MSG \033[0;93m"
# define ERROR_SIG			"\u274C\033[91m KILL() ERROR ENCOUNTERED \033[0;93m"
# define SERVER_CLOSED		"\033[1;1H\u2705\033[0;92m Server closed, bye!"

//----------DEFINING STRUCTURES----------//

//---------------FUNCTIONS---------------//

void	terminate(char *error_msg);
int		msg_c(int code, char *pid);
int		msg_s(int code, char *pid);
void	msg_sender(int pid, char *msg);

#endif
