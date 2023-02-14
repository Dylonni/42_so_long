# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daumis <daumis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 16:42:03 by dylan             #+#    #+#              #
#    Updated: 2023/02/09 15:43:25 by daumis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_MAIN		= main.c map_handler.c err_handler.c floodfill.c display.c hook.c movement.c

SRCS			= ${SRC_MAIN}

LIBFT_DIR 		= ../Libft/

OBJ				= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -g3

NAME            = a.out

all:			$(NAME)

$(NAME): $(OBJ)
	@make -C ${LIBFT_DIR}
	$(CC) $(OBJ) $(CFLAGS) ../Libft/libft.a -L../mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -I/usr/include -Imlx_linux -O3 -c $< -o $@


clean:
	$(RM) $(OBJ)

fclean:			clean
	make -C ${LIBFT_DIR} fclean
	$(RM) $(NAME)

re:	fclean
	make all

.PHONY:	all clean fclean re