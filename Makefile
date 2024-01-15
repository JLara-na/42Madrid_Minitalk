# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 18:15:15 by jlara-na          #+#    #+#              #
#    Updated: 2024/01/15 17:25:43 by jlara-na         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------EXE NAMES------------

NAME_S			:=		server
NAME_C			:=		client

#-----------DIR PATHS------------
SRC_DIR			:=		src/
SRC_S_DIR		:=		src/src_s/
SRC_C_DIR		:=		src/src_c/
OBJ_DIR			:=		obj/
OBJ_S_DIR		:=		obj/obj_s/
OBJ_C_DIR		:=		obj/obj_c/
INC_DIR			:=		inc/
LFT_DIR			:=		lib/libft/

#-----------CMP PARAM------------

CC				:=		gcc
CFLAGS			:=		-g -O3 -Wall -Wextra -Werror #-fsanitize=address
HEADER			:=		-I$(INC_DIR) -I$(LFT_DIR)

#-----------ARCHIVE LIB----------

LIBFT			:=		$(LFT_DIR)libft.a

#-----------SRC FILES------------

SRC_FILES_S		=		main			\
						server_msg		\

SRC_FILES_C		=		main			\
						msg_sender		\
						client_msg		\

#---------SRC OBJ DEP INC---------

SRC_S 			= 		$(addprefix $(SRC_S_DIR), $(addsuffix .c, $(SRC_FILES_S)))
OBJ_S			= 		$(addprefix $(OBJ_S_DIR), $(addsuffix .o, $(SRC_FILES_S)))
DEPS_S 			= 		$(addprefix $(OBJ_S_DIR), $(addsuffix .d, $(SRC_FILES_S)))
SRC_C 			= 		$(addprefix $(SRC_C_DIR), $(addsuffix .c, $(SRC_FILES_C)))
OBJ_C 			= 		$(addprefix $(OBJ_C_DIR), $(addsuffix .o, $(SRC_FILES_C)))
DEPS_C 			= 		$(addprefix $(OBJ_C_DIR), $(addsuffix .d, $(SRC_FILES_C)))
INCS			= 		$(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))

#-----------SHORT CUTS-----------

RM				:=		rm -f

#------------ANSI DEF------------

CLEAR			=		\033[2J\033[1;1H
DEF_COLOR		=		\033[0;39m
GRAY			=		\033[0;90m
RED				=		\033[0;91m
RED_B			=		\033[0;91;5m
GREEN			=		\033[0;92m
YELLOW			=		\033[0;93m
YELLOW_B		=		\033[0;93;5m
BLUE			=		\033[0;94m
MAGENTA			=		\033[0;95m
CYAN			=		\033[0;96m
WHITE			=		\033[0;97m

#-------------CACHE--------------

OBJF_S			=		.cache_exists_s
OBJF_C			=		.cache_exists_c

#--------------------------------

all:	makelibs
				@$(MAKE) $(NAME_S)
				@$(MAKE) $(NAME_C)

makelibs:
			@echo "$(CLEAR)\n			$(YELLOW_B)⚙$(YELLOW)COMPILING LIBFT...$(CYAN)			\n"
			@$(MAKE) -C $(LFT_DIR)
			@echo "$(DEF_COLOR)"

-include	${DEPS_S}
$(NAME_S):	$(OBJ_S)
			@echo "\n$(BLUE)$(CC) $(CFLAGS) $(OBJ_S) $(LIBFT) -o $(NAME_S)$(DEF_COLOR)\n"
			@$(CC) $(CFLAGS) $(OBJ_S) $(LIBFT) -o $(NAME_S)
			@echo "$(GREEN)			✔SERVER COMPILED CORRECTLY\n$(DEF_COLOR)"

-include	${DEPS_C}
$(NAME_C):	$(OBJ_C)
			@echo "\n$(BLUE)$(CC) $(CFLAGS) $(OBJ_C) $(LIBFT) -o $(NAME_C)$(DEF_COLOR)\n"
			@$(CC) $(CFLAGS) $(OBJ_C) $(LIBFT) -o $(NAME_C)
			@echo "$(GREEN)			✔CLIENT COMPILED CORRECTLY\n$(DEF_COLOR)"

bonus:
			@$(MAKE) all

$(OBJ_S_DIR)%.o: $(SRC_S_DIR)%.c $(INCS) | $(OBJF_S)
			@echo "$(YELLOW_B)			⚙$(YELLOW)COMPILING: $< ...$(DEF_COLOR)"
			@$(CC) $(CFLAGS) -MMD -c $< -o $@

$(OBJ_C_DIR)%.o: $(SRC_C_DIR)%.c $(INCS) | $(OBJF_C)
			@echo "$(YELLOW_B)			⚙$(YELLOW)COMPILING: $< ...$(DEF_COLOR)"
			@$(CC) $(CFLAGS) -MMD -c $< -o $@

$(OBJF_S):
			@mkdir -p $(OBJ_S_DIR)
		
$(OBJF_C):
			@mkdir -p $(OBJ_C_DIR)

$(LIBFT):
			@make -C $(LFT_DIR)
			@echo "$(GREEN)LIBFT	COMPILED$(DEF_COLOR)"

clean:
			@echo "$(CLEAR)\n			🧹SWEEPING THE FLOOR🧹\n"
			@make clean -sC $(LFT_DIR)
			@echo "$(CYAN)LIBFT				$(GREEN)CLEANED$(DEF_COLOR)"
			@$(RM) -rf $(OBJ_DIR)
			@echo "$(CYAN)OBJ FILES			$(GREEN)CLEANED$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME_S)
			@echo "$(CYAN)SERVER				$(GREEN)CLEANED$(DEF_COLOR)"
			@$(RM) -f $(NAME_C)
			@echo "$(CYAN)CLIENT				$(GREEN)CLEANED$(DEF_COLOR)"
			@$(RM) -f $(LIBFT)
			@echo "$(CYAN)LIBFT.a				$(GREEN)CLEANED$(DEF_COLOR)"

re:			fclean
			@$(MAKE)
			@echo "$(GREEN)			✔MINITALK CLEANED, REBUILT & READY TO USE\n$(DEF_COLOR)"

norminette:
			@echo "$(CLEAR)"
			@echo "\n$(YELLOW)SERVER FILES	$(YELLOW_B)NORMINETTED\n$(DEF_COLOR)"
			@norminette $(SRC_S) $(INCLUDE) | grep -v Norme -B1 || true
			@echo "\n$(YELLOW)CLIENT FILES	$(YELLOW_B)NORMINETTED\n$(DEF_COLOR)"
			@norminette $(SRC_C) $(INCLUDE) | grep -v Norme -B1 || true
			@echo "\n$(YELLOW)INCLUDE FILES	$(YELLOW_B)NORMINETTED\n$(DEF_COLOR)"
			@norminette $(INC_DIR) | grep -v Norme -B1 || true

PHONY: all makelibs bonus clean fclean re norminette
