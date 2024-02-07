# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 15:30:58 by avaldin           #+#    #+#              #
#    Updated: 2024/02/07 14:55:08 by avaldin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		##		COMPILATION			##

CC			=	cc
FLAGS		=	-Wall -Wextra -Werror -g3 -I/usr/include -Imlx_linux -O3

		##		EXECUTABLE			##

NAME		=	FDF

		##		PATH				##

SRC_PATH	=	src
OBJ_PATH	=	obj

		##		SOURCES_FILES		##

SOURCES		=	src/FDF.c\
				src/security.c\
				src/gnl/get_next_line.c\
				src/gnl/get_next_line_utils.c\

HEADER		=	header/FDF.h\
				header/get_next_line.h

		##		OBJECTS				##

OBJS		=	$(SOURCES:.c=.o)

		##		RULES				##

all			:	$(NAME)
%.o			:	%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME)		:	$(OBJS) Makefile
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean		:
	rm -f $(OBJS)

fclean		:	clean
	rm -f $(NAME)

re        :    fclean all
.PHONY    :    all clean fclean re