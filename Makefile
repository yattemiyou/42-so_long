# （参考）
# https://zenn.dev/keitean/articles/aaef913b433677
NAME = so_long

INCLUDE = -I. -I./libft -I./mlx

SRCDIR = ./
SRCS = main.c
SRCS += ft_event.c
SRCS += ft_game.c
SRCS += ft_graphic.c
SRCS += ft_map.c
SRCS += ft_util.c
SRCS += ft_validation.c

OBJS = $(addprefix $(SRCDIR),$(SRCS:%.c=%.o))

LIBS = -L./libft -lft
LIBS += -L./mlx -lmlx
LIBS += -lXext -lX11

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $^ $(LIBS) -o $@

%.o: %.c
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $*.o

clean:
	$(MAKE) -C ./libft fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
