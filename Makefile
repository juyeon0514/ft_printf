# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 16:12:01 by juykang           #+#    #+#              #
#    Updated: 2022/08/08 17:06:42 by juykang          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror 
AR = ar
ARFLAGS = crs
RM = rm
RMFLAGS = -f

FILES = ft_printf_char \
		ft_printf_num  \
		ft_printf_utils\
		ft_printf

SRCS = $(addsuffix .c, $(FILES))
OBJCS = $(addsuffix .o, $(FILES))

$(NAME) : $(OBJCS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJCS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re