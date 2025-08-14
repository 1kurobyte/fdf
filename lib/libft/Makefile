# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 21:10:40 by smamalig          #+#    #+#              #
#    Updated: 2025/08/01 00:24:02 by smamalig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -MMD -MP -std=c99
SRC_DIR     = src
OBJ_DIR     = obj
SRCS        = $(shell find $(SRC_DIR) -type f -name '*.c')
OBJS        = $(patsubst $(SRC_DIR)/%.c, ${OBJ_DIR}/%.o, $(SRCS))
DEPS        = $(patsubst $(SRC_DIR)/%.c, ${OBJ_DIR}/%.d, $(SRCS))
INCLUDES    = -Iinclude
NPROC       = $(shell nproc)

ifeq ($(DEBUG), 1)
	CFLAGS += -Og -g3 -D_DEBUG \
			-Wpedantic -Wmissing-declarations -Wpadded -Wshadow \
			-Wconversion -Wstrict-prototypes -Wmissing-prototypes \
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

ifeq ($(USE_ERRNO), 1)
	CFLAGS += -DUSE_ERRNO
endif

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

norm:
	echo $(SRCS) | xargs -n1 -P$(NPROC) norminette

tidy:
	echo $(SRCS) | xargs -n1 -P$(NPROC) clang-tidy -p .

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	@make all --no-print-directory

-include $(DEPS)

.PHONY: all clean fclean re norm tidy
