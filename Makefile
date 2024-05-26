# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 10:34:25 by laprieur          #+#    #+#              #
#    Updated: 2024/05/26 18:17:24 by laprieur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	libftprintf.a

# **************************************************************************** #
#                                 INGREDIENTS                                  #
# **************************************************************************** #

MANDATORY		:=	src/ft_printf.c			\
					src/ft_printf_utils.c	\

M_OBJS			:=	$(MANDATORY:%.c=.build/%.o)
DEPS			:=	$(M_OBJS:%.o=%.d)

CC				:=	clang
CFLAGS			:=	-Wall -Wextra -Werror -Ofast
CPPFLAGS		:=	-MP -MMD -Iinclude -Iinclude/ft_printf.h
LDFLAGS			:=

# **************************************************************************** #
#                                    TOOLS                                     #
# **************************************************************************** #

MAKEFLAGS		+= --silent --no-print-directory

# **************************************************************************** #
#                                   RECIPES                                    #
# **************************************************************************** #

all: header $(NAME)

$(NAME): $(M_OBJS)
	ar -rc $(NAME) $(M_OBJS)
	@printf "%b" "$(BLUE)CREATED $(CYAN)$(NAME)\n"

.build/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@
	@printf "%b" "$(BLUE)CREATED $(CYAN)$@\n"

-include $(DEPS)

clean:
	rm -rf .build

fclean: clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

# **************************************************************************** #
#                                    STYLE                                     #
# **************************************************************************** #

GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
CYAN			:= \033[0;36m
OFF				:= \033[m

header:
	@printf "%b" "$(GREEN)"
	@echo "		  __ _                   _       _    __	"
	@echo "		 / _| |_      _ __  _ __(_)_ __ | |_ / _|	"
	@echo "		| |_| __|    |  _ \|  __| |  _ \| __| |_	"
	@echo "		|  _| |_     | |_) | |  | | | | | |_|  _|	"
	@echo "		|_|  \__|____|  __/|_|  |_|_| |_|\__|_|		"
	@echo "		       |_____|_|by laprieur					"
	@echo
	@printf "%b" "$(CYAN)CC:	$(YELLOW)$(CC)\n"
	@printf "%b" "$(CYAN)CFlags:	$(YELLOW)$(CFLAGS)\n"
	@printf "%b" "$(OFF)"
	@echo

# **************************************************************************** #
#                                   SPECIAL                                    #
# **************************************************************************** #

.PHONY: all clean fclean re
.DELETE_ON_ERROR:
