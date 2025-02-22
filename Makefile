# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/21 01:07:58 by tripham           #+#    #+#              #
#    Updated: 2025/02/22 00:15:13 by tripham          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

DIR_LIBFT = ./library/libft
DIR_FT_PRINTF = ./library/ft_printf
DIR_SRC = ./sources
DIR_MLX = ./library/MLX42
DIR_OBJ = $(DIR_SRC)/objects

SOURCES = main.c guide.c utils.c fractol_hook.c generate_color.c \
          initialization.c rendering.c fractol_sets.c

OBJECTS = $(patsubst %.c,$(DIR_OBJ)/%.o,$(SOURCES))

HEADERS = -I ./include -I $(DIR_MLX)/include -I $(DIR_LIBFT) -I $(DIR_FT_PRINTF)

MLXLIB = $(DIR_MLX)/build/libmlx42.a
LIBFT = $(DIR_LIBFT)/libft.a
FT_PRINTF = $(DIR_FT_PRINTF)/libftprintf.a

# MLX42 dependencies
MLXLIB_FLAGS = -L$(DIR_MLX)/build -lmlx42 -ldl -lglfw -lm
LIBFT_FLAGS = -L $(DIR_LIBFT) -lft
FT_PRINTF_FLAGS = -L $(DIR_FT_PRINTF) -ftp

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(LIBFT) $(FT_PRINTF) $(MLXLIB) $(NAME)

$(MLXLIB):
	@if [ ! -d "$(DIR_MLX)" ]; then \
		cd library && git clone https://github.com/codam-coding-college/MLX42.git; \
	fi
	@cmake -B $(DIR_MLX)/build -S $(DIR_MLX) && make -C $(DIR_MLX)/build -j

$(LIBFT):
	@make -C $(DIR_LIBFT) -j

$(FT_PRINTF):
	@make -C $(DIR_FT_PRINTF) -j

$(NAME): $(OBJECTS) $(LIBFT) $(FT_PRINTF) $(MLXLIB)
	@$(CC) $(OBJECTS) $(LIBFT) $(FT_PRINTF) $(MLXLIB_FLAGS) $(HEADERS) -o $@

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

clean:
	@$(RM) $(DIR_OBJ)
	@$(RM) $(DIR_MLX)/build
	@make -C $(DIR_LIBFT) clean
	@make -C $(DIR_FT_PRINTF) clean

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(DIR_MLX)
	@make -C $(DIR_LIBFT) fclean
	@make -C $(DIR_FT_PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re
