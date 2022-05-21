# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 19:48:35 by tompedra          #+#    #+#              #
#    Updated: 2022/05/21 21:15:31 by tompedra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES --------------------------------------------------------------------

NAME = libftprintf

M_NAME = .mandatory

B_NAME = .bonus





# ROUTES -----------------------------------------------------------------------

INCL_DIR = includes

LIBFT_DIR = libft





# TARGETS ----------------------------------------------------------------------

LIBFT_LIBNAME = libft.a

LIBNAME = libftprintf.a





# SOURCES ----------------------------------------------------------------------

M_SRCS_FILES = ft_printf

M_SRCS = $(addsuffix .c, $(M_SRCS_FILES))

B_SRCS_FILES = ft_printf_bonus ft_printf_param_bonus

B_SRCS = $(addsuffix .c, $(B_SRCS_FILES))





# OBJECTS ----------------------------------------------------------------------

M_OBJS = $(M_SRCS:.c=.o)

B_OBJS = $(B_SRCS:.c=.o)





# COMMANDS ---------------------------------------------------------------------

CC = gcc

TOUCH = touch

CD = cd

RM = rm





# FLAGS ------------------------------------------------------------------------

CFLAGS = -Wall -Wextra -Werror $(CFLAGS_INCL)

CFLAGS_INCL = -I $(LIBFT_DIR)/$(INCL_DIR)

ARFLAGS = -rcs

RMFLAGS_FILE = -f





# RULES ------------------------------------------------------------------------

.PHONY:		all clean fclean re bonus norm

$(NAME):	$(M_NAME)

$(M_NAME):	$(M_OBJS)
		$(CD) $(LIBFT_DIR) && $(MAKE)
		$(AR) $(ARFLAGS) $(LIBNAME) $(M_OBJS)
		@$(RM) $(RMFLAGS_FILE) $(B_NAME)
		@$(TOUCH) $(M_NAME)

$(B_NAME):	$(B_OBJS)
		$(CD) $(LIBFT_DIR) && $(MAKE) bonus
		$(AR) $(ARFLAGS) $(LIBNAME) $(B_OBJS)
		@$(RM) $(RMFLAGS_FILE) $(M_NAME)
		@$(TOUCH) $(B_NAME)

all:		$(M_NAME)

clean:
		$(CD) $(LIBFT_DIR) && $(MAKE) clean
		@$(RM) $(RMFLAGS_FILE) $(B_OBJS) $(M_OBJS)

fclean:		clean
		$(RM) $(RMFLAGS_FILE) $(addprefix $(LIBFT_DIR)/, $(LIBFT_LIBNAME))
		@$(RM) $(RMFLAGS_FILE) $(addprefix $(LIBFT_DIR)/, $(M_NAME) $(B_NAME))
		$(RM) $(RMFLAGS_FILE) $(LIBNAME)
		@$(RM) $(RMFLAGS_FILE) $(M_NAME) $(B_NAME)

re:			fclean all

bonus:		$(B_NAME)

norm:
	$(CD) $(LIBFT_DIR) && $(MAKE) norm
	@norminette $(M_SRCS) $(B_SRCS) $(NAME).h | grep -v Norme -B1 || true
