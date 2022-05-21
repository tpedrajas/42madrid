# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 22:18:59 by tompedra          #+#    #+#              #
#    Updated: 2022/05/21 07:16:04 by tompedra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES --------------------------------------------------------------------

NAME = libft

M_NAME = .mandatory

B_NAME = .bonus





# ROUTES -----------------------------------------------------------------------

INCL_DIR = includes

SRCS_DIR = sources

OBJS_DIR = objects

E_DIR = extra

M_DIR = mandatory

B_DIR = bonus

E_SRCS_DIR = $(SRCS_DIR)/$(E_DIR)

E_OBJS_DIR = $(OBJS_DIR)/$(E_DIR)

M_SRCS_DIR = $(SRCS_DIR)/$(M_DIR)

M_OBJS_DIR = $(OBJS_DIR)/$(M_DIR)

B_SRCS_DIR = $(SRCS_DIR)/$(B_DIR)

B_OBJS_DIR = $(OBJS_DIR)/$(B_DIR)





# TARGETS ----------------------------------------------------------------------

LIBNAME = libft.a





# SOURCES ----------------------------------------------------------------------

E_SRCS_FILES = ft_nbrlen_base ft_snbrlen_base ft_nbrsign

E_SRCS = $(addprefix $(E_SRCS_DIR)/, $(addsuffix .c, $(E_SRCS_FILES)))

M_SRCS_FILES = ft_isalpha ft_isdigit ft_isalnum\
			   ft_isascii ft_isprint ft_strlen\
			   ft_memset ft_bzero ft_memcpy\
			   ft_memmove ft_strlcpy ft_strlcat\
			   ft_toupper ft_tolower ft_strchr\
			   ft_strrchr ft_strncmp ft_memchr\
			   ft_memcmp ft_strnstr ft_atoi\
			   ft_calloc ft_strdup\
			   ft_substr ft_strjoin ft_strtrim\
			   ft_split ft_itoa ft_strmapi\
			   ft_striteri ft_putchar_fd ft_putstr_fd\
			   ft_putendl_fd ft_putnbr_fd

M_SRCS = $(addprefix $(M_SRCS_DIR)/, $(addsuffix .c, $(M_SRCS_FILES)))

B_SRCS_FILES = ft_lstnew ft_lstadd_front ft_lstsize\
			   ft_lstlast ft_lstadd_back ft_lstdelone\
			   ft_lstclear ft_lstiter ft_lstmap

B_SRCS = $(addprefix $(B_SRCS_DIR)/, $(addsuffix _bonus.c, $(B_SRCS_FILES)))





# OBJECTS ----------------------------------------------------------------------

E_OBJS_FILES = $(notdir $(E_SRCS:.c=.o))

E_OBJS = $(addprefix $(E_OBJS_DIR)/, $(E_OBJS_FILES))

M_OBJS_FILES = $(notdir $(M_SRCS:.c=.o))

M_OBJS = $(addprefix $(M_OBJS_DIR)/, $(M_OBJS_FILES)) $(E_OBJS)

B_OBJS_FILES = $(notdir $(B_SRCS:.c=.o))

B_OBJS = $(addprefix $(B_OBJS_DIR)/, $(B_OBJS_FILES)) $(M_OBJS)





# COMMANDS ---------------------------------------------------------------------

CC = gcc

TOUCH = touch

RM = rm

MKDIR = mkdir





# FLAGS ------------------------------------------------------------------------

CFLAGS = -Wall -Wextra -Werror

CFLAGS_INCL = -I $(INCL_DIR)

ARFLAGS = -rcs

RMFLAGS_FILE = -f

RMFLAGS_REC = -rf

MKDIRFLAGS = -p





# RULES ------------------------------------------------------------------------

.PHONY:		all clean fclean re bonus norm

$(NAME):	$(M_NAME)

$(M_NAME):	$(M_OBJS)
		$(AR) $(ARFLAGS) $(LIBNAME) $(M_OBJS)
		@$(RM) $(RMFLAGS_FILE) $(B_NAME)
		@$(TOUCH) $(M_NAME)

$(B_NAME):	$(B_OBJS)
		$(AR) $(ARFLAGS) $(LIBNAME) $(B_OBJS)
		@$(RM) $(RMFLAGS_FILE) $(M_NAME)
		@$(TOUCH) $(B_NAME)

$(E_OBJS_DIR)/%.o: $(E_SRCS_DIR)/%.c
		$(CC) $(CFLAGS) $(CFLAGS_INCL) -o $@ -c $<

$(M_OBJS_DIR)/%.o: $(M_SRCS_DIR)/%.c | $(M_OBJS_DIR) 
		$(CC) $(CFLAGS) $(CFLAGS_INCL) -o $@ -c $<

$(M_OBJS_DIR):
		@$(MKDIR) $(MKDIRFLAGS) $(E_OBJS_DIR)
		@$(MKDIR) $(MKDIRFLAGS) $(M_OBJS_DIR)
			
$(B_OBJS_DIR)/%.o: $(B_SRCS_DIR)/%.c | $(B_OBJS_DIR)
	$(CC) $(CFLAGS) $(CFLAGS_INCL) -o $@ -c $<

$(B_OBJS_DIR):
		@$(MKDIR) $(MKDIRFLAGS) $(E_OBJS_DIR)
		@$(MKDIR) $(MKDIRFLAGS) $(M_OBJS_DIR)
		@$(MKDIR) $(MKDIRFLAGS) $(B_OBJS_DIR)

all:		$(M_NAME)

clean:
		$(RM) $(RMFLAGS_REC) $(OBJS_DIR)

fclean:		clean
		$(RM) $(RMFLAGS_FILE) $(LIBNAME)
		@$(RM) $(RMFLAGS_FILE) $(M_NAME) $(B_NAME)

re:			fclean all

bonus:		$(B_NAME)

norm:
	@norminette $(SRCS_DIR) $(INCL_DIR) | grep -v Norme -B1 || true
