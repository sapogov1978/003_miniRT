# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/19 23:46:42 by brattles          #+#    #+#              #
#    Updated: 2021/05/10 18:05:20 by brattles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= miniRT

CC			:= gcc
WFLAGS		:= -Wall -Wextra -Werror

LIBS_DIR	:= libs
INC_DIR		:= includes
OBJ_DIR		:= build

FUNCTIONS	= minirt.c \
			  ft_entry_check.c \
			  ft_struct_init.c \
			  ft_panic.c \
			  ft_print_help.c \
			  ft_rtparser.c \
			  ft_vector_math1.c \
			  ft_vector_math2.c \
			  ft_vector_math3.c \
 			  parser/ft_get_scene_name.c \
			  parser/ft_get_resolution.c \
			  parser/ft_get_ambient.c \
			  parser/ft_get_cameras.c \
			  parser/ft_get_vector.c \
			  parser/ft_get_lights.c \
			  parser/ft_get_plane.c \
			  parser/ft_get_sphere.c \
			  parser/ft_get_cylinder.c \
			  parser/ft_get_cylinder_utl.c \
			  parser/ft_get_square.c \
			  parser/ft_get_triangles.c \
			  parser/ft_light_nrmlz.c \
			  ft_rendering.c \
			  ft_intersects.c \
			  ft_colors.c \
			  ft_colors2.c \
			  ft_camera_switch.c \
			  ft_save_bmp.c

OBJ			:= $(FUNCTIONS:%.c=$(OBJ_DIR)/%.o)
DEP			:= $(OBJ:%.o=%.d)

CFLAGS		:= $(WFLAGS) -O3 -MMD

ifeq ($(shell uname -s), Linux)
	MLX_DIR := $(LIBS_DIR)/minilibx_linux
	MLX_LIB := -L/usr/lib
	LFLAGS	:= -lft -lmlx -lXext -lX11 -lm -lz
else
	MLX_DIR := $(LIBS_DIR)/minilibx_macos
	MLX_LIB := -framework OpenGL -framework AppKit
	LFLAGS	:= -lft -lmlx -lm
endif

FT_DIR		:= $(LIBS_DIR)/libft

MLX_LIB 	+= -L$(MLX_DIR)
FT_LIB		+= -L$(FT_DIR)

LIB			:= $(MLX_LIB) $(FT_LIB)
INC			:= -I$(MLX_DIR) -I$(FT_DIR) -I$(INC_DIR)

vpath %.c src

.PHONY:	all clean fclean re debug

all: $(NAME)

$(NAME): $(OBJ)
	make -sC $(FT_DIR) all
	make -sC $(MLX_DIR) all
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(INC) $(LFLAGS) -o $(NAME)

-include $(DEP)
$(OBJ_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	make -sC $(FT_DIR) clean
	make -sC $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -sC $(FT_DIR) fclean
	rm -rf $(NAME)
	rm -rf renders/*.bmp

re: fclean all