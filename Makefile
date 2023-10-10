# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/01 15:48:02 by ghwa              #+#    #+#              #
#    Updated: 2023/09/27 17:19:28 by ghwa             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES  = map.c so_long.c mapcheck.c move.c keyhandling.c
SOURCES = $(addprefix Utilities/, $(CFILES))
OBJECTS = ${SOURCES:.c=.o}
CFLAGS = -Wall -Werror -Wextra -g3 -ggdb -fsanitize=address
LFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = so_long
CC = cc

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJECTS) ./libft/libft.a -o $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)
	rm -f a.out

re: fclean all

.PHONY = all clean fclean re