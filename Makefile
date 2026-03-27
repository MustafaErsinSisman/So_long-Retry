NAME 		= so_long
CC		= cc
CFLAGS 		= -Wall -Wextra -Werror
LIBS		= collector/collector.a libft/libft.a get_next_line/get_next_line.a minilibx-linux/libmlx.a -L minilibx-linux -lmlx -L/usr/X11R6/lib -lXext -lX11 -lm -lbsd

SRCS		= main.c
OBJS		= $(SRCS:.c=.o)

RM		= rm -f

DIR_GNL		= get_next_line
DIR_LIBFT	= libft
DIR_COLLECTOR	= collector
DIR_MINILBIX	= minilibx-linux

all: $(NAME)

$(NAME): $(OBJS)
	make -s -C $(DIR_GNL)
	make -s -C $(DIR_LIBFT)
	make -s -C $(DIR_COLLECTOR)
	make -s -C $(DIR_MINILBIX)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	make -s -C $(DIR_GNL) clean
	make -s -C $(DIR_LIBFT) clean
	make -s -C $(DIR_COLLECTOR) clean
	make -s -C $(DIR_MINILBIX) clean

fclean: clean
	$(RM) $(NAME)
	make -s -C $(DIR_GNL) fclean
	make -s -C $(DIR_LIBFT) fclean
	make -s -C $(DIR_COLLECTOR) fclean
	make -s -C $(DIR_MINILBIX) clean

re: fclean all

.PHONY: all clean fclean bonus re
