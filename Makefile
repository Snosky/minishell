# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpayen <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/03 11:25:21 by tpayen            #+#    #+#              #
#    Updated: 2016/03/09 18:04:50 by tpayen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = minishell
CC = clang
CFLAGS = -Wall -Werror -Wextra 

SRCDIR = src/
LIBFTDIR = libft/
OBJDIR = obj/

INCLUDES = -I$(LIBFTDIR)/includes -Iincludes
LIBS = $(LIBFTDIR)/libft.a

SRC_FILES =	main.c			\
			sh_execute.c	\
			ft_cd.c			\
			ft_pwd.c		\
			extract_env.c	\
			find_env.c		\
			ft_env.c		\

DIRS = $(OBJDIR)

SRC_OBJ = $(SRC_FILES:%.c=$(OBJDIR)%.o)

all: directories $(EXEC)

$(EXEC): $(SRC_OBJ)
	@($(MAKE) -C $(LIBFTDIR))
	$(CC) -o $@ $^ $(LIBS) 

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES)

.PHONY: directories re clean fclean

re: fclean all

clean:
	rm -rf $(OBJDIR)
	@($(MAKE) -C $(LIBFTDIR) $@)

fclean: clean
	rm -rf $(EXE)
	@($(MAKE) -C $(LIBFTDIR) $@)

directories: $(DIRS)

$(DIRS):
	mkdir $@
