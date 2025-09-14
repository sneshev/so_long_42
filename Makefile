NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Library paths
MLX42_PATH = ./MLX42
LIBFT_PATH = ./libft
MLX42_REPO = https://github.com/codam-coding-college/MLX42.git
# MLX42_VERSION = ce254c3
LIBFT_REPO = https://github.com/sneshev/libft_42.git
# LIBFT_VERSION = e99f0e6

# Headers and libraries
HEADERS = -I$(MLX42_PATH)/include -I$(LIBFT_PATH)
LIBS = $(MLX42_PATH)/build/libmlx42.a $(LIBFT_PATH)/libft.a -ldl -lglfw -pthread -lm

SRCS = $(wildcard src/*.c) $(wildcard utils/*.c)
OBJS_DIR = obj
OBJS = $(SRCS:src/%.c=$(OBJS_DIR)/%.o)
OBJS := $(OBJS:utils/%.c=$(OBJS_DIR)/%.o)

all: mlx42 libft $(NAME)

mlx42: $(MLX42_PATH)/build/libmlx42.a

$(MLX42_PATH)/build/libmlx42.a:
	@if [ ! -d "$(MLX42_PATH)" ]; then \
		git clone $(MLX42_REPO) $(MLX42_PATH); \
		cd $(MLX42_PATH) && git checkout $(MLX42_VERSION); \
	fi
	@mkdir -p $(MLX42_PATH)/build
	@cd $(MLX42_PATH) && cmake -B build && cmake --build build -j4

libft: $(LIBFT_PATH)/libft.a

$(LIBFT_PATH)/libft.a:
	@if [ ! -d "$(LIBFT_PATH)" ]; then \
		git clone $(LIBFT_REPO) $(LIBFT_PATH); \
		cd $(LIBFT_PATH) && git checkout $(LIBFT_VERSION); \
	fi
	@make all -C $(LIBFT_PATH)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

$(OBJS_DIR)/%.o: src/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(OBJS_DIR)/%.o: utils/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@


clean:
	@make -C $(LIBFT_PATH) clean
	@rm -f $(OBJS)
	@rm -rf $(MLX42_PATH)/build
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)
	@rm -rf $(MLX42_PATH)
	@rm -rf $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re mlx42 libft