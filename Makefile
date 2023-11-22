# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daumis <daumis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 16:42:03 by dylan             #+#    #+#              #
#    Updated: 2023/07/19 14:44:11 by daumis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_MAIN		= src/main.c \
				  src/map_handler.c \
				  src/err_handler.c \
				  src/floodfill.c \
				  src/display.c \
				  src/game.c \
				  src/movement.c \
				  src/free.c

SRCS			= ${SRC_MAIN}
OBJ_DIR			= objs
OBJS 			= $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRCS))

LIBFT_DIR 		= Libft/
MLX_DIR			= mlx_linux/

CC			= cc
RM			= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= so_long

all: $(OBJ_DIR)	$(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "\033[1;35m\n                              ⌛️Compiling files...\033[0m"
	@make -s -C ${LIBFT_DIR}
	@make -s -C ${MLX_DIR}
	$(CC) $(OBJS) $(CFLAGS) Libft/libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "\033[32;1m\n                     Project has compiled successfully! ✅ \033[0m"
	@echo "\033[32;1m\n 💾 Executable './$(NAME)' has been created in: \n    └─ 📂 \033[4;36m ~ $(PWD)\033[0m"

%.o: %.c
	$(CC) -Wall -Wextra -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean:		
	@echo "\033[1;33m\n                        [Cleaning directories with \033[0;36mfclean\033[1;33m]\n\033[0m"
	@make clean
	@make -C ${LIBFT_DIR} fclean
	$(RM) $(NAME)

re:	
	@make fclean
	@echo "\033[1;33m\n                            [Calling \033[0;36mmake all\033[1;33m rule]\n\033[0m"
	@make all

.PHONY:	all clean fclean re
