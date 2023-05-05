# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 13:58:44 by mpalkov           #+#    #+#              #
#    Updated: 2023/05/04 16:12:48 by mpalkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MODE	:=	normal

ifeq ($(MODE),debug)
	CFLAGS	+=	-g3
endif

NAME	:=	push_swap

#-------------------------------------------------------------------------------
#		FILES

SRCS	:=	main.c \
			initchecks.c \
			operations.c

#-------------------------------------------------------------------------------
#		COLORS

DEFCOLOR	:=	\033[0;39m
GRAY		:=	\033[0;90m
RED			:=	\033[0;91m
ORANGE		:=	\033[0;33m
GREEN		:=	\033[0;92m
YELLOW		:=	\033[0;93m
BLUE		:=	\033[0;94m
MAGENTA		:=	\033[0;95m
CYAN		:=	\033[0;96m
WHITE		:=	\033[0;97m

#-------------------------------------------------------------------------------
#		DIRECTORIES

LIBFT_DIR	:=	utils/libft/

OBJ_DIR		:=	.obj/

SRC_DIR		:=	src/

# UTILS_DIR	:=	utils/

#-------------------------------------------------------------------------------
#		COMMANDS

CC			:=	cc

CFLAGS		+=	-MMD -MP -MT $@

CFLAGS		+=	-Wall -Werror -Wextra

RM			:=	rm -f

CP			:=	cp -f

MAKEFLAGS	+=	--no-print-directory

#-------------------------------------------------------------------------------
#		RULES

LIBFT		:=	$(LIBFT_DIR)libft.a

OBJS		:=	$(addprefix $(OBJ_DIR),$(SRCS:.c=.o))

DEPS		:=	$(addsuffix .d,$(basename $(OBJS)))

INCLUDE		:=	-I./utils/libft/ -I./utils/libft/includes/ -I./includes/

all: make_libft $(NAME)
	@echo "all executed"

# bonus: make_libft $(NAME_C_BNS) $(NAME_S_BNS)

make_libft:
	@echo "$(GREEN)	Calling Libft make $(DEFCOLOR)"
	@$(MAKE) -C $(LIBFT_DIR)

objects:
	@echo "$(OBJS)"

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<
	@echo "$(GREEN)	Compiling: $< -> $@ $(DEFCOLOR)"

-include $(DEPS)

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(GREEN)	Creating binary: $@ $(DEFCOLOR)"
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -L$(LIBFT_DIR) -lft -o $@

clean:
	@echo "$(ORANGE)	Cleaning residual .o and .d files$(DEFCOLOR)"
	@$(MAKE) clean -sC $(LIBFT_DIR)
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@echo "$(ORANGE)	Cleaning main binary files$(DEFCOLOR)"
	@$(RM) $(NAME)
	@echo "$(ORANGE)	Libft fclean$(DEFCOLOR)"
	@$(MAKE) fclean -sC $(LIBFT_DIR)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all, clean, fclean, re