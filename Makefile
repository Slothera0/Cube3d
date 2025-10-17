CC = cc

SRCS_PATH = ./

CFLAGS = -Wall -Wextra -Werror -MMD -MP

F_OBJS = .objs/
F_SRCS = srcs/
F_PARSE = $(F_SRCS)parse/
F_REND = $(F_SRCS)rend/

SRCS = $(F_SRCS)main.c $(F_SRCS)utils.c \
		$(F_PARSE)parsing.c $(F_PARSE)colors.c $(F_PARSE)textures.c $(F_PARSE)utils.c $(F_PARSE)checker.c $(F_PARSE)getter.c $(F_PARSE)error.c $(F_PARSE)init.c \
		$(F_REND)start_loop.c $(F_REND)raycasting.c $(F_REND)print_map.c $(F_REND)movement.c $(F_REND)rotation.c \

OBJS = $(SRCS:%.c=$(F_OBJS)%.o)
OBJS_D = $(OBJS:$(F_OBJS)%.o=$(F_OBJS)%.d)

NAME = cub3d

INCLUDES = ./includes
LIBFT_PATH = $(INCLUDES)/Libft/
LIBFT = $(LIBFT_PATH)libft.a
HEADERS = $(INCLUDES)/cub3d.h $(INCLUDES)/parsing.h $(INCLUDES)/rend.h

MLX_PATH = ./mlx_linux

MLX = $(MAKE) -C $(MLX_PATH)

all:
	$(MLX)
	$(MAKE) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -I $(MLX_PATH) -L $(MLX_PATH) -lmlx_Linux -lXext -lX11 -lm -o $(NAME) $(LIBFT)

$(F_OBJS)%.o : %.c $(HEADERS)
	mkdir -p $(F_OBJS) $(F_OBJS)$(F_PARSE) $(F_OBJS)$(F_REND)
	$(CC) $(CFLAGS) -I $(INCLUDES) -I $(MLX_PATH) -c $< -o $@

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_PATH)

valgrind: $(NAME)
	valgrind --track-fds=yes --trace-children=yes --leak-check=full --show-leak-kinds=all --show-mismatched-frees=yes ./cub3d maps/map.cub

clean:
	rm -rf $(F_OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

FORCE:

.PHONY: all clean fclean re FORCE valgrind