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

SRC = main.c struct_utils.c line.c

LIB = libft/libft.a MLX42/libglfw3.a MLX42/libmlx42.a

INC = include/

FLAGS =  -Wall -Wextra -Werror -framework Cocoa -framework OpenGL -framework IOKit -fsanitize=address -lm

all: $(NAME)

$(NAME):
	gcc $(SRC) $(LIB) -I$(INC) $(FLAGS) -o $@

test:
	gcc example.c $(LIB) -I$(INC) $(FLAGS) -o $@

libft:
	make -C libft/ re

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY:  all clean fclean re libft visualizer bonus
