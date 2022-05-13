# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 22:18:59 by tompedra          #+#    #+#              #
#    Updated: 2022/05/13 21:51:00 by tompedra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

E_SRCS = ft_llonglen_base_extra.c ft_ullonglen_base_extra.c

M_SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c\
		 ft_isascii.c ft_isprint.c ft_strlen.c\
		 ft_memset.c ft_bzero.c ft_memcpy.c\
		 ft_memmove.c ft_strlcpy.c ft_strlcat.c\
		 ft_toupper.c ft_tolower.c ft_strchr.c\
		 ft_strrchr.c ft_strncmp.c ft_memchr.c\
		 ft_memcmp.c ft_strnstr.c ft_atoi.c\
		 ft_calloc.c ft_strdup.c\
		 ft_substr.c ft_strjoin.c ft_strtrim.c\
		 ft_split.c ft_itoa.c ft_strmapi.c\
		 ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
		 ft_putendl_fd.c ft_putnbr_fd.c

B_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
		 ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
		 ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

E_OBJS = $(E_SRCS:.c=.o)

M_OBJS = $(E_OBJS) $(M_SRCS:.c=.o)

B_OBJS = $(M_OBJS) $(B_SRCS:.c=.o)

NAME = libft

LIBNAME = libft.a

M_NAME = .mandatory

B_NAME = .bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

TOUCH = touch

$(NAME):	$(M_NAME)

$(M_NAME):	$(M_OBJS)
		$(AR) $(LIBNAME) $(M_OBJS)
		$(RM) $(B_NAME)
		$(TOUCH) $(M_NAME)

$(B_NAME):	$(B_OBJS)
		$(AR) $(LIBNAME) $(B_OBJS)
		$(RM) $(M_NAME)
		$(TOUCH) $(B_NAME)

all:		$(M_NAME)

clean:
		$(RM) $(B_OBJS)

fclean:		clean
		$(RM) $(LIBNAME) $(M_NAME) $(B_NAME)

re:			fclean all

bonus:		$(B_NAME)

.PHONY:		all clean fclean re bonus
