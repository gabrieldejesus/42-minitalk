# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-jesu <gde-jesu@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 05:55:15 by gde-jesu          #+#    #+#              #
#    Updated: 2023/09/28 11:12:29 by gde-jesu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 #Library Name #
CLIENT			=	client
SERVER			=	server
CLIENT_BONUS	=	client_bonus
SERVER_BONUS	=	server_bonus

# Compiling Variables #
CC	=	cc
CFLAG	=	-Wall -Wextra -Werror
RM		=	rm -f

# Libft Variables #
LIBFT		=	./42-Libft/libft.a
LIBFT_DIR	=	./42-Libft
INC			=	-I. -I$(LIBFT_DIR)

# Sources Variables #
MANDATORY_SRCS_CLIENT = client.c
MANDATORY_SRCS_SERVER = server.c

BONUS_SRCS_CLIENT	=	client_bonus.c
BONUS_SRCS_SERVER	=	server_bonus.c

# Colors #
GREEN = \e[32m
YELLOW = \e[33m
RESET = \e[0m
_SUCCESS = ✨ $(GREEN)Compiled successfully$(RESET)
_INFO = 🚀 $(YELLOW)Info$(RESET)

all: $(LIBFT) $(SERVER) $(CLIENT)
	@printf "$(_SUCCESS) minitalk.\n"

$(NAME): all

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	
$(SERVER):
	@$(CC) $(CFLAG) $(MANDATORY_SRCS_SERVER) $(LIBFT) $(INC) -o $(SERVER)

$(CLIENT):
	@$(CC) $(CFLAG) $(MANDATORY_SRCS_CLIENT) $(LIBFT) $(INC) -o $(CLIENT)

$(SERVER_BONUS):
	@$(CC) $(CFLAG) $(BONUS_SRCS_SERVER) $(LIBFT) $(INC) -o $(SERVER_BONUS)

$(CLIENT_BONUS):
	@$(CC) $(CFLAG) $(BONUS_SRCS_CLIENT) $(LIBFT) $(INC) -o $(CLIENT_BONUS)

bonus: $(LIBFT) $(SERVER_BONUS) $(CLIENT_BONUS)
	@printf "$(_SUCCESS) minitalk bonus.\n"

clean:
	@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@printf "$(_INFO) minitalk cleaning done.\n"

fclean:
	@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@printf "$(_INFO) minitalk cleaning done.\n"

re: fclean all

.PHONY: all fclean clean re bonus