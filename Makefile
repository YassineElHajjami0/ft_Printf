# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 11:20:50 by yel-hajj          #+#    #+#              #
#    Updated: 2022/11/09 14:44:53 by yel-hajj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCMAN = ft_printf.c \
	util.c \

OBJMAN = $(SRCMAN:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar cr
RM = rm -rf

NAME = libftprintf.a
HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJMAN)
	$(AR) $(NAME) $(OBJMAN)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJMAN)

fclean: clean
	$(RM) $(NAME)

re: fclean all
