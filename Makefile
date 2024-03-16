# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 21:38:41 by etlaw             #+#    #+#              #
#    Updated: 2024/03/16 19:19:11 by etlaw            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -I -g3 
LDFLAGS = -fsanitize=address -g3
MLX = -I /usr/X11/include -g -L /usr/local/lib -l mlx -framework OpenGL -framework AppKit

OBJS = obj/init.o \
	   obj/main.o \
	   obj/hooking.o \
	   obj/test.o \
	   obj/drawing.o \
	   obj/libft.o \
	   obj/raycast.o \

all: $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(MLX) $(LDFLAGS)

obj:
	mkdir obj

obj/%.o: ./%.c | obj
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

.PHONY: all re clean fclean