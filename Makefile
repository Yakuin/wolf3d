#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboualla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/26 15:11:11 by yboualla          #+#    #+#              #
#    Updated: 2016/06/18 19:02:32 by yboualla         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	wolf3d

SRC =	wolf3d.c \
		events.c \
		overlay.c \
		draw.c \
		raycast.c \
		mouse_events.c \
		color.c \
		checks.c

OBJ =	$(SRC:.c=.o)

LIB =	-Llibft/ -lft -lmlx -framework AppKit -framework OpenGL

FLG =	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\x1B[32mCompiling libft..."
	@make -C "libft/"
	@gcc -c -Ofast $(FLG) $(SRC)
	@echo "Compiling wolf3d..."
	@gcc -o $(NAME) $(OBJ) $(LIB)
	@echo "\x1B[37;1mDone !"
	@echo "\x1B[37m"

clean:
	@echo "\x1B[32;1mDeleting object files..."
	@make -C "libft/" clean
	@rm -f $(OBJ)
	@echo "\x1B[37;1mDone !"
	@echo "\x1B[37m"

fclean: clean
	@make -C "libft/" fclean
	@echo "\x1B[32;1mDeleting executable..."
	@rm -f $(NAME)
	@echo "\x1B[37;1mDone !"
	@echo "\x1B[37m"

re: fclean all

.PHONY: all clean fclean re