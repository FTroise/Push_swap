# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 14:21:48 by ftroise           #+#    #+#              #
#    Updated: 2024/01/19 20:32:06 by ftroise          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CHECKER = checker_bonus

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

MAIN = main.c
SRC	= atoi_error.c
CK = checker/ck.c checker/gnl.c
MOVES =	moves/push.c moves/roteate.c moves/reverse.c moves/swap.c
ALGORITMO = algoritmo/quicksort.c algoritmo/utils_sort.c

OBJM = $(MAIN:.c=.o)
OBJ	=  $(SRC:.c=.o) $(MOVES:.c=.o) $(ALGORITMO:.c=.o)
OBJ_CHECKER = $(CK:.c=.o)

LIBFT	= libft/libft.a
FT_PRINTF	= ft_printf/ft_printf.a



all :
	$(CC) $(CFLAGS) $(MAIN) $(SRC) $(ALGORITMO) $(MOVES) $(LIBFT) $(FT_PRINTF) -o $(NAME)

bonus : all
	$(CC) $(CFLAGS) $(SRC) $(CK) $(ALGORITMO) $(MOVES) $(LIBFT) $(FT_PRINTF) -o $(CHECKER)

clean:
	rm -f $(OBJM)
	rm -f $(OBJ)
	rm -f $(OBJ_CHECKER)

fclean: clean
	rm -f $(NAME)
	rm -f $(CHECKER)

re: fclean all

.PHONY:			all bonus clean fclean re
