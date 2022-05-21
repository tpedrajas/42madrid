# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 19:48:35 by tompedra          #+#    #+#              #
#    Updated: 2022/05/21 07:16:02 by tompedra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES --------------------------------------------------------------------

NAME = libftprintf

M_NAME = .mandatory

B_NAME = .bonus





# ROUTES -----------------------------------------------------------------------

LIBFT_DIR = libft

INCL_DIR = includes

SRCS_DIR = sources

OBJS_DIR = objects

M_DIR = mandatory

B_DIR = bonus

M_SRCS_DIR = $(SRCS_DIR)/$(M_DIR)

M_OBJS_DIR = $(OBJS_DIR)/$(M_DIR)

B_SRCS_DIR = $(SRCS_DIR)/$(B_DIR)

B_OBJS_DIR = $(OBJS_DIR)/$(B_DIR)





# TARGETS ----------------------------------------------------------------------

LIBFT_LIBNAME = libft.a

LIBNAME = libftprintf.a





# SOURCES ----------------------------------------------------------------------

M_SRCS_FILES = ft_printf

M_SRCS = $(addprefix $(M_SRCS_DIR)/, $(addsuffix .c, $(M_SRCS_FILES)))

B_SRCS_FILES = ft_printf_bonus ft_printf_param_bonus

B_SRCS = $(addprefix $(B_SRCS_DIR)/, $(addsuffix .c, $(B_SRCS_FILES)))





# OBJECTS ----------------------------------------------------------------------

M_OBJS_FILES = $(notdir $(M_SRCS:.c=.o))

M_OBJS = $(addprefix $(M_OBJS_DIR)/, $(M_OBJS_FILES))

B_OBJS_FILES = $(notdir $(B_SRCS:.c=.o))

B_OBJS = $(addprefix $(B_OBJS_DIR)/, $(B_OBJS_FILES))





# COMMANDS ---------------------------------------------------------------------

CC = gcc

TOUCH = touch

CD = cd

RM = rm

MKDIR = mkdir





# FLAGS ------------------------------------------------------------------------

CFLAGS = -Wall -Wextra -Werror

CFLAGS_INCL = -I $(INCL_DIR) -I $(LIBFT_DIR)/$(INCL_DIR)

MAKEFLAGS = -C

ARFLAGS = -rcs

RMFLAGS_FILE = -f

RMFLAGS_REC = -rf

MKDIRFLAGS = -p





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

$(M_OBJS_DIR)/%.o: $(M_SRCS_DIR)/%.c | $(M_OBJS_DIR) 
		$(CC) $(CFLAGS) $(CFLAGS_INCL) -o $@ -c $<

$(M_OBJS_DIR):
		@$(MKDIR) $(MKDIRFLAGS) $(M_OBJS_DIR)

$(B_OBJS_DIR)/%.o: $(B_SRCS_DIR)/%.c | $(B_OBJS_DIR)
	$(CC) $(CFLAGS) $(CFLAGS_INCL) -o $@ -c $<

$(B_OBJS_DIR):
		@$(MKDIR) $(MKDIRFLAGS) $(B_OBJS_DIR)

all:		$(M_NAME)

clean:
		$(CD) $(LIBFT_DIR) && $(MAKE) clean
		@$(RM) $(RMFLAGS_REC) $(OBJS_DIR)

fclean:		clean
		$(RM) $(RMFLAGS_FILE) $(addprefix $(LIBFT_DIR)/, $(LIBFT_LIBNAME))
		@$(RM) $(RMFLAGS_FILE) $(addprefix $(LIBFT_DIR)/, $(M_NAME) $(B_NAME))
		$(RM) $(RMFLAGS_FILE) $(LIBNAME)
		@$(RM) $(RMFLAGS_FILE) $(M_NAME) $(B_NAME)

re:			fclean all

bonus:		$(B_NAME)

norm:
	$(CD) $(LIBFT_DIR) && $(MAKE) norm
	@norminette $(SRCS_DIR) $(INCL_DIR) | grep -v Norme -B1 || true
