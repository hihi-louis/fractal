# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/21 01:07:58 by tripham           #+#    #+#              #
#    Updated: 2025/02/21 05:09:56 by tripham          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

DIR_LIBFT = ./library/libft
DIR_FT_PRINTF = ./library/ft_printf
DIR_SRC = ./sources
DIR_MLX = ./library/MLX42
DIR_OBJ = $(DIR_SRC)/objects

SOURCES = $(DIR_SRC)/main.c \
	$(DIR_SRC)/guide.c \
	$(DIR_SRC)/utils.c	\
	$(DIR_SRC)/fractol_event.c	\
	$(DIR_SRC)/generate_color.c	\
	$(DIR_SRC)/initialization.c	\
	$(DIR_SRC)/rendering.c

SRC = $(addprefix $(DIR_SRC)/,$(SOURCES))

OBJECTS = $(patsubst %.c,$(DIR_OBJ)/%.o,$(notdir $(SOURCES)))

HEADERS = -I ./include -I $(DIR_MLX)/include -I $(DIR_LIBFT) -I $(DIR_FT_PRINTF)

MLXLIB = $(DIR_MLX)/build/libmlx42.a
LIBFT = $(DIR_LIBFT)/libft.a
FT_PRINTF = $(DIR_FT_PRINTF)/libftprintf.a

# MLX42 dependencies
MLXLIB_FLAGS = $(DIR_MLX)/build/libmlx42.a -ldl -lglfw -lm
LIBFT_FLAGS = -L $(DIR_LIBFT) -lft
FT_PRINTF_FLAGS = -L $(DIR_FT_PRINTF) -ftp

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(LIBFT) $(FT_PRINTF) $(MLXLIB) $(NAME)

$(MLXLIB):
	@cd library && git clone https://github.com/codam-coding-college/MLX42.git
	@cmake $(DIR_MLX) -B $(DIR_MLX)/build && make -C $(DIR_MLX)/build -j4

$(LIBFT):
	@make -C $(DIR_LIBFT)

$(FT_PRINTF):
	@make -C $(DIR_FT_PRINTF)

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) $(LIBFT_FLAGS) $(MLXLIB) $(MLXLIB_FLAGS) $(HEADERS) -o $@

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
