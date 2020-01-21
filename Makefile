# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 23:49:34 by kait-mar          #+#    #+#              #
#    Updated: 2020/01/11 15:12:04 by kait-mar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

t_flagS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCO = file1.c file13.c file14.c  file15.c file16.c file17.c print_flag.c file12.c file2.c file11.c ft_atoi.c ft_itoa.c file10.c ft_printf_utils.c ft_printf.c my_flags.c print.c to_base.c file3.c file4.c file5.c file6.c file7.c file8.c file9.c function.c

all : $(NAME)
	@echo "Building Library."

$(NAME) :
	gcc $(t_flagS) -c $(SRCO)
	ar rc $(NAME) *.o

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all

