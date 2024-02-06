# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 10:23:52 by cdomet-d          #+#    #+#              #
#    Updated: 2024/02/06 13:26:17 by cdomet-d         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME := so_long
LIB := libft.a
BUILD_DIR := .dir_build
LIBFT_DIR := ../build/libft
MLX_DIR := ../build/mlx
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

CC := cc
CFLAGS := -Werror -Wextra -Wall -g3 
CPPFLAGS = -MMD -MP
MAKEFLAGS += --no-print-directory

INCLUDES = -I/usr/include -I$(MLX_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_LIB) -lX11 -lm -lz -lXext $(MLX_LIB)

SRCS := window_handling.c \
		init_display.c \
		map_handling.c \
		parsing_utils.c \
		parsing.c \
		main.c \
		utils.c \
		error_handling.c \

OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:%.o=%.d)
RM := rm -rf

all: $(NAME)

$(NAME): $(LIBFT_DIR)/$(LIB) $(MLX_LIB) $(OBJS)
	@echo
	@echo "$(PURPLE)|========== \t\t Making SO_LONG \t\t ===========|$(BLACK)"
	@echo
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) $(MLX_FLAGS) -o $(NAME) -lft
	@echo
	@echo "$(GREEN)|=========== \t\t SO_LONG done ! \t\t ===========|$(BLACK)"
	@echo

$(BUILD_DIR)/%.o:%.c so_long.h $(LIBFT_DIR)/libft.h Makefile
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $< $(INCLUDES)

$(LIBFT_DIR)/$(LIB): FORCE
	@echo "$(FAINT)"
	$(MAKE) -C $(LIBFT_DIR)
	@echo "$(RESET)"

$(MLX_LIB): FORCE
	@echo "$(FAINT)"
	$(MAKE) -C $(MLX_DIR)
	@echo "$(RESET)"

 -include $(DEPS)

clean:
	@echo "$(FAINT)"
	@echo
	@echo "$(PURPLE)|========== \t\t Cleaning... \t\t ===========|$(BLACK)"
	@echo
	$(RM) $(BUILD_DIR)
	make -C $(LIBFT_DIR) $@
	make -C $(MLX_DIR) $@

fclean: clean
	@echo "$(FAINT)"
	$(RM) $(MLX_LIB)
	make -C $(LIBFT_DIR) $@
	$(RM) $(NAME)
	@echo
	@echo "$(PURPLE)|========== \t\t Bye <3 \t\t ===========|$(BLACK)"
	@echo

re: fclean all

run: all
	@./$(NAME)

help:
	@echo "make \t\t $(FAINT)makes push_swap.exe$(RESET)"
	@echo "make clean \t $(FAINT)deletes object files & dependencies$(RESET)"
	@echo "make fclean \t $(FAINT)deletes everything the makefile created$(RESET)"
	@echo "make kitty \t $(FAINT)prints a lil kitty on the terminal$(RESET)"
	@echo "make re \t $(FAINT)deletes all objects & dependencies and recompiles everything$(RESET)"

kitty:
	@echo "   |\__/,|   ( \  "
	@echo " _.|o o  |_   ) ) "
	@echo "-(((---(((--------"

# Colors
BLACK=\033[30m
GREEN=\033[32m
PURPLE=\033[35m

# Text
RESET=\033[0m
FAINT=\033[2m
UNDERLINE=\033[4m

FORCE : 
.PHONY : clean fclean all re run help kitty display force bonus