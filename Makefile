# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 11:40:06 by mvallhon          #+#    #+#              #
#    Updated: 2024/03/11 13:10:49 by mvallhon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

GCC = gcc
CFLAGS = -Wall -Wextra -Werror -g
FRAMEWORK = -framework AppKit -framework OpenGL
RM = rm -f

LIBFT = libs/libft
LIBMLX = libs/minilibx_macos

SRCS_FILES = main.c \
			 ft_strcmp.c \
			 double_atoi.c \
			 calc_mandelbrot.c \
			 calc_julia.c \
			 calc_burning.c \
			 mlx_utils.c \
			 mlx_utils2.c \
			 paint_mandelbrot.c \
			 paint_julia.c \
			 paint_burning.c \
			 paint_utils.c \

HEAD = fractol.h
MAKE = Makefile

SRCS_DIR = srcs/
OBJS_DIR = objs/


OBJS_FILES = $(SRCS_FILES:.c=.o)
DEPS_FILES = $(SRCS_FILES:.c=.d)

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_FILES))
DEPS = $(addprefix $(OBJS_DIR), $(DEPS_FILES))

all: $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	mkdir -p objs
	$(GCC) $(CFLAGS) -c -MMD $< -o $@

make_libs: $(OBJS) $(HEAD) $(MAKE)
	@make -C $(LIBFT)
	@make -C $(LIBMLX)

$(NAME): $(OBJS) $(HEAD) $(MAKE) make_libs
	$(GCC) $(CFLAGS) $(OBJS) $(LIBFT)/libft.a $(LIBMLX)/libmlx.a $(FRAMEWORK) -o $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)
	$(RM) -r $(OBJS_DIR)
	@make clean -C $(LIBFT)
	@make clean -C $(LIBMLX)

fclean: clean
	$(RM) $(NAME)
	$(RM) libft.a
	$(RM) libmlx.a
	$(RM) $(LIBFT)/libft.a
	$(RM) $(LIBMLX)/libmlx.a

re: fclean all

-include $(DEPS)

.PHONY: clean fclean re all
