# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/01 19:21:59 by jnovoa-a          #+#    #+#              #
#    Updated: 2025/08/01 19:32:54 by jnovoa-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Nombre del ejecutable
NAME = push_swap

# Archivos fuente con ruta relativa a esta carpeta
SRCS = \
	srcs/main.c \
	srcs/push_swap.c \
	srcs/sort_small.c \
	srcs/sort_five.c \
	srcs/fill_stack.c \
	srcs/parsing.c \
	srcs/operations.c \
	srcs/swap.c \
	srcs/push.c \
	srcs/rotate.c \
	srcs/reverse_rotate.c \
	srcs/utils.c

# Archivos objeto
OBJS = $(SRCS:.c=.o)

# Header(s)
HEADER = push_swap.h

# Regla principal
all: $(NAME)

# Linkear objeto(s) para crear ejecutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compilar .c a .o, depende del header para recompilar al cambiar header
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar objetos
clean:
	rm -f $(OBJS)

# Limpiar todo (objetos + ejecutable)
fclean: clean
	rm -f $(NAME)

# Recompilar todo
re: fclean all

.PHONY: all clean fclean re
