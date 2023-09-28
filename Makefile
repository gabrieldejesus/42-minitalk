# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-jesu <gde-jesu@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 05:55:15 by gde-jesu          #+#    #+#              #
#    Updated: 2023/09/28 10:17:08 by gde-jesu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library Name #
CLIENT			=	client
SERVER			=	server
CLIENT_BONUS	=	client_bonus
SERVER_BONUS	=	server_bonus

# Compiling Variables #
CC	=	cc
CFLAG	=	-Wall -Wextra -Werror
RM		=	rm -f

# Libft Variables #
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft
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

# Functions #
all: $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

$(NAME): all

$(SERVER): $(LIBFT)
	@$(CC) $(CFLAG) $(SRC_S) $(LIBFT) $(INC) -o $(SERVER)
	@printf "$(_SUCCESS) server mandatory is ready.\n"

$(CLIENT): $(LIBFT)
	@$(CC) $(CFLAG) $(SRC_C) $(LIBFT) $(INC) -o $(CLIENT)
	@printf "$(_SUCCESS) client mandatory is ready.\n"

$(SERVER_BONUS): $(LIBFT)
	@$(CC) $(CFLAG) $(SRC_S) $(LIBFT) $(INC) -o $(SERVER_BONUS)
	@printf "$(_SUCCESS) server bonus is ready.\n"

$(CLIENT_BONUS): $(LIBFT)
	@$(CC) $(CFLAG) $(SRC_C) $(LIBFT) $(INC) -o $(CLIENT_BONUS)
	@printf "$(_SUCCESS) client bonus is ready.\n"

$(LIBFT):
	@$(MAKE) -C ./libft

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

clean:
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(RM) $(CLIENT) $(SERVER)
	@printf "$(_INFO) client mandatory removed.\n"
	@printf "$(_INFO) server mandatory removed.\n"
	@$(RM) $(CLIENT_BONUS) $(SERVER_BONUS)
	@printf "$(_INFO) client bonus removed.\n"
	@printf "$(_INFO) server bonus removed.\n"

fclean: clean
	@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY: all fclean clean re