# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:43:54 by fkernbac          #+#    #+#              #
#    Updated: 2022/03/30 14:36:04 by fkernbac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF
#SRC = example.c
SRC = main.c cleanup.c parser.c map_setup.c map_operations.c vertex.c \
	hooks.c lines.c zoom.c rotate.c perspective.c extra.c testing.c
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))
OBJ_PATH = objs/
LIB = libft/libft.a MLX42/libglfw3.a MLX42/libmlx42.a
INC = -Iinclude/
FLAGS = -Wall -Wextra -Werror
LINKER = -framework Cocoa -framework OpenGL -framework IOKit -lm

all: libft mlx $(NAME)

$(NAME): $(OBJ)
	gcc $(LIB) $(LINKER) $(INC) $(OBJ) -o $@

$(OBJ_PATH)%.o: %.c
	mkdir -p $(OBJ_PATH)
	gcc -c $(FLAGS) $(INC) $< -o $@

libft:
	make -C libft/ all

mlx:
	make -C MLX42/ all

clean:
	/bin/rm -f $(OBJ_PATH)*.o
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY:  all clean fclean re libft linux mlx
