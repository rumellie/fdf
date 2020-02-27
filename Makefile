# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mellie <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 20:18:30 by mellie            #+#    #+#              #
#    Updated: 2020/02/24 06:34:18 by mellie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, libr

FLAGS = -Wall -Wextra -Werror

C_FILES =   ft_countword.c ft_draw.c ft_error.c gradient.c init_data.c \
			key_utils.c main.c menu.c read_file.c rotate.c utils.c

O_FILES = $(C_FILES:.c=.o)

H_DIR = -Ilibft -Iusr/L -Iinclude

LIBS = -Llibft -lft -lmlx -framework OpenGL -framework AppKit

S_DIR = sources

OBJ = $(addprefix $(S_DIR)/, $(O_FILES))

NAME = fdf

all: libr $(NAME)

libr:
	    make -C libft/ all

$(NAME): $(OBJ)
	    gcc $(FLAGS) -o $@ $^ $(H_DIR) $(LIBS)

$(S_DIR)/%.o: $(S_DIR)/%.c include/fdf.h
	    gcc $(FLAGS) -c $< -o $@ $(H_DIR)

clean:
	    make -C ./libft/ clean
		    rm -f $(OBJ)

fclean : clean
	    make -C libft/ fclean
		    rm -f $(NAME)

re: fclean all
