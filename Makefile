# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 21:59:04 by smamalig          #+#    #+#              #
#    Updated: 2025/08/14 10:27:19 by smamalig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
SRC_DIR		:= src
OBJ_DIR		:= build
BIN_DIR		:= bin
INC_DIR		:= include
LIB_DIR		:= lib
LIBFT_DIR	:= $(LIB_DIR)/libft
LIBMLX_DIR	:= $(LIB_DIR)/mlx

# Output
NAME		:= $(BIN_DIR)/fdf

# Compiler
CC			:= clang
CFLAGS		:= -Wall -Wextra -MMD -MP -std=c99

# Source groups
SRCS_UI		:= ui/switch.c ui/rect.c
SRCS_HOOKS	:= hooks/mouse.c hooks/keys.c hooks/register.c
SRCS_PROJS	:= projections/orthographic.c projections/perspective.c \
				projections/topdown.c projections/conic.c \
				projections/fisheye.c projections/spherical.c \
				projections/stereographic.c projections/panini.c
SRCS_UTILS	:= utils/vectors.c utils/mouse.c
SRCS_WGEN	:= worldgen/init.c
SRCS_OPTS	:= options/init.c
SRCS_GFX	:= gfx/init.c gfx/destroy.c
SRCS_THREADS	:= threads/init.c threads/destroy.c threads/add.c threads/run.c
SRCS_COLOR	:= color/hsv.c color/blend.c color/lerp.c color/get.c color/from.c
SRCS_CLI	:= cli/arguments.c
SRCS_CAMERA	:= camera/mouse.c camera/keys.c
SRCS_RENDER	:= render/bresenham.c render/line.c render/xiaolin_wu.c \
				render/xiaolin_wu_steep.c render/text.c render/projection.c \
				render/pixel.c render/ui.c render/gimbal.c render/triangle.c \
				render/depth.c render/framebuffers.c render/rows.c \
				render/faces.c render/task.c

SRC_FILES	:= main.c parsing.c $(SRCS_COLOR) $(SRCS_WGEN) $(SRCS_UTILS) \
				$(SRCS_CLI) $(SRCS_HOOKS) $(SRCS_UI) $(SRCS_PROJS) $(SRCS_RENDER) \
				$(SRCS_THREADS) $(SRCS_OPTS) $(SRCS_GFX) $(SRCS_CAMERA)

SRCS		:= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# Object and dependency files
OBJS		:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
DEPS		:= $(OBJS:.o=.d)

# Libraries
LIBFT		:= $(LIBFT_DIR)/libft.a
LIBMLX		:= $(LIBMLX_DIR)/libmlx.a
LDLIBS		:= -lft -lmlx -lX11 -lXext -lm
LDFLAGS		:= -L$(LIBFT_DIR) -L$(LIBMLX_DIR)

INCLUDES	:= -I$(INC_DIR) -I$(LIBMLX_DIR) -I$(LIBFT_DIR)/include


ifeq ($(DEBUG), 1)
	CFLAGS += -Og -g3 -D_DEBUG \
			-Wpedantic -Wpacked -Wstrict-prototypes -Wshadow -Wpadded \
			-Wconversion -Wmissing-prototypes -Wmissing-declarations \
			-Wold-style-definition -Winline -Wsign-conversion -Wundef \
			-Wcast-align -Wcast-qual -Wwrite-strings -Wuninitialized \
			-Wdouble-promotion -Wfloat-equal -Wvla -Wnull-dereference \
			-Wformat=2 -fstack-protector-strong
	ifeq ($(SANITIZE), 1)
		CFLAGS += -fsanitize=address -fsanitize=undefined -fsanitize=leak
	endif
else
	CFLAGS += -Werror
endif

ifeq ($(RELEASE), 1)
	CFLAGS += -O3 -DNDEBUG -march=native -flto
endif

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $@
	@printf "\t\e[94;1m$@ Compiled\e[m\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(LIBMLX):
	@$(MAKE) CC=clang -C $(LIBMLX_DIR) --no-print-directory 2>/dev/null

# Tools
NPROC		:= $(shell nproc)

norm:
	echo $(SRCS) | xargs -n1 -P$(NPROC) norminette

tidy:
	echo $(SRCS) | xargs -n1 -P$(NPROC) clang-tidy -p .

# Clean rules
clean:
	rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@make -C $(LIBMLX_DIR) clean --no-print-directory

fclean: clean
	rm -rf $(BIN_DIR)
	@make -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean
	@$(MAKE) all --no-print-directory

-include $(DEPS)

.PHONY: all clean fclean re norm tidy libft libmlx
