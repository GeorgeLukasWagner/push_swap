# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 19:19:44 by gwagner           #+#    #+#              #
#    Updated: 2024/08/01 20:22:45 by gwagner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= push_swap.c args_utils.c distonce.c instructions01.c instructions02.c instructions03.c instructions04.c list_util01.c list_util02.c radixsort.c simple_sort.c 
INCL        = push_swap.h
OBJS        = $(SRCS:.c=.o)
CC          = cc
RM          = rm -f
CFLAGS      = -Wall -Werror -Wextra -I $(INCL)
NAME        = push_swap

BLUE		=	\033[0;94m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
CYAN		=	\033[0;96m
COLOR		=	\033[0m
CLEAR		=	\033c

SUCCESS		=	@echo "$(GREEN)success !! o(≧▽≦)o$(COLOR)"
S_OBJS		=	@echo "$(BLUE)cleaning of objects completed <(￣︶￣)>$(COLOR)"
S_NAME		=	@echo "$(CYAN)full clean completed ! ヽ(・∀・)ﾉ$(COLOR)"

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./printf
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./printf/libftprintf.a
	$(SUCCESS)

clean:
	$(MAKE) clean -C ./printf
	$(RM) $(OBJS)
	$(S_OBJS)
	
fclean: clean
	$(MAKE) fclean -C ./printf
	$(RM) $(NAME)
	$(S_NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re