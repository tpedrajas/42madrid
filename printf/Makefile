# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 19:48:35 by tompedra          #+#    #+#              #
#    Updated: 2022/05/13 23:14:29 by tompedra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

M_SRCS = ft_printf.c ft_printf_param_type.c

B_SRCS = ft_printf_bonus.c ft_printf_param_bonus_bonus.c

M_OBJS = $(M_SRCS:.c=.o)

B_OBJS = $(B_SRCS:.c=.o)

LIBFT_ROUTE = libft/

LIBFT_LIBNAME = libft.a

NAME = libftprintf

LIBNAME = libftprintf.a

M_NAME = .mandatory

B_NAME = .bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

TOUCH = touch

$(NAME):	$(M_NAME)

$(M_NAME):	$(OBJS)
		make -C $(LIBFT_ROUTE)
		$(AR) $(LIBNAME) $(OBJS)
		$(RM) $(B_NAME)
		$(TOUCH) $(M_NAME)

$(B_NAME):	$(B_OBJS)
		make bonus -C $(LIBFT_ROUTE)
		$(AR) $(LIBNAME) $(B_OBJS)
		$(RM) $(M_NAME)
		$(TOUCH) $(B_NAME)

all:		$(M_NAME)

clean:
		make clean -C $(LIBFT_ROUTE)
		$(RM) $(M_OBJS) $(B_OBJS)

fclean:		clean
		$(RM) $(LIBFT_ROUTE)$(LIBFT_LIBNAME) $(LIBFT_ROUTE)$(M_NAME) $(LIBFT_ROUTE)$(B_NAME)
		$(RM) $(LIBNAME) $(M_NAME) $(B_NAME)

re:			fclean all

bonus:		$(B_NAME)

.PHONY:		all clean fclean re bonus
