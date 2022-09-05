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

# gcc main.c MLX42/libmlx42.a MLX42/libglfw3.a -I MLX42/include -framework Cocoa -framework OpenGL -framework IOKit

NAME = FdF
#SRC = example.c
SRC = zoom.c hooks.c vertex.c lines.c main.c testing.c cleanup.c map_setup.c parser.c rotate.c perspective.c map_operations.c extra.c
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))
OBJ_PATH = objs/
LIB = libft/libft.a MLX42/libglfw3.a MLX42/libmlx42.a
INC = -Iinclude/
FLAGS = -Wall -Wextra -Werror
LINKER = -framework Cocoa -framework OpenGL -framework IOKit -lm

all: libft mlx $(NAME)

$(NAME): include/FdF.h $(OBJ)
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
	make -C libft/ fclean

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY:  all clean fclean re libft linux mlx
