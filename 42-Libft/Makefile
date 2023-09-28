# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-jesu <gde-jesu@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 14:50:00 by gde-jesu          #+#    #+#              #
#    Updated: 2023/09/27 11:31:03 by gde-jesu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library Name #
NAME = libft.a

# Compiling Variables #
CC = cc
RM = rm -rf
ARC = ar -rcs
CFLAGS = -Wall -Wextra -Werror -c

# Sources Variables #
MANDATORY_SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_printf.c ft_putchar.c ft_putstr.c ft_flag_s.c \
ft_flag_u.c ft_flags_di.c ft_flag_x.c ft_flag_p.c

BONUS_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
ft_lstmap_bonus.c

# Objects Variables #
MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Colors #
GREEN = \e[32m
YELLOW = \e[33m
RESET = \e[0m
_SUCCESS = ✨ $(GREEN)Compiled successfully$(RESET)
_INFO = 🚀 $(YELLOW)Info$(RESET)

# Functions #
$(NAME):
	@$(CC) $(CFLAGS) -I. $(MANDATORY_SRCS)
	@$(ARC) $(NAME) $(MANDATORY_OBJS)
	@printf "$(_SUCCESS) libft.\n"

all: $(NAME)

bonus:
	@$(CC) $(CFLAGS) -I. $(BONUS_SRCS)
	@$(ARC) $(NAME) $(BONUS_OBJS)
	@printf "$(_SUCCESS) libft.\n"

clean:
	@$(RM) $(MANDATORY_OBJS) $(BONUS_OBJS)
	@printf "$(_INFO) libft cleaning done.\n"

fclean:
	@$(RM) $(NAME)
	@$(RM) $(MANDATORY_OBJS) $(BONUS_OBJS)
	@printf "$(_INFO) libft cleaning done.\n"

re: fclean all

.PHONY:	all clean fclean re 
