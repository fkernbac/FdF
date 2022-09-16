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

NAME = libft

SRC = ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c ft_strlcpy.c\
	ft_strtrim.c ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c ft_strlen.c\
	ft_substr.c ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_strdup.c\
	ft_strmapi.c ft_tolower.c ft_isalnum.c ft_memchr.c ft_putendl_fd.c\
	ft_striteri.c ft_strncmp.c ft_toupper.c ft_isalpha.c ft_memcmp.c \
	ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c ft_isascii.c ft_memcpy.c\
	ft_putstr_fd.c ft_strlcat.c ft_strrchr.c\
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\
	ft_printf.c ft_hextoa.c ft_ptoa.c ft_utoa.c\
	get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ = $(SRC:.c=.o)



all: $(NAME)

$(NAME): $(NAME).a

$(NAME).a: $(OBJ)
	ar -ru $@ $(OBJ)

%.o: %.c
	@gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME).a

re: fclean all
