# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmostafa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 18:48:34 by mmostafa          #+#    #+#              #
#    Updated: 2019/11/15 18:59:14 by mmostafa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBSRC = libft/libft.a
LIBPATH = libft/

OBJ = ./burninship.o ./julia.o ./main.o ./mandlbrot.o  ./tools.o
FLAG = -Wall -Werror -Wextra
MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(LIBSRC) $(OBJ) fract.h
	gcc $(FLAG) $(OBJ) $(LIBSRC) $(MLX) -o $(NAME)

%.o : %.c
	gcc  $(FLAG) -c $< -o $@
$(LIBSRC):
	make -C  $(LIBPATH)

clean:
	make clean -C $(LIBPATH)
	/bin/rm -f $(OBJ)
fclean: clean
	make fclean -C $(LIBPATH)
	/bin/rm -f $(NAME)
re: fclean all
