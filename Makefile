NAME            = so_long

CC              = cc
CFLAGS          = -Wall -Wextra -Werror

SRC_DIR         = src
OBJ_DIR         = obj
INC_DIR         = inc

DIR_GNL         = get_next_line
DIR_FTPRINTF    = ft_printf
DIR_LIBFT       = libft
DIR_COLLECTOR   = collector
DIR_MINILBIX    = minilibx-linux

INCLUDES        = -I $(INC_DIR) -I $(DIR_LIBFT) -I $(DIR_GNL) -I $(DIR_FTPRINTF) -I $(DIR_COLLECTOR) -I $(DIR_MINILBIX)

SRCS_NAMES      = main.c map_reader.c map_checker.c flood_fill.c \
                  mlx_processes.c render.c key_handler.c utils.c

SRCS            = $(addprefix $(SRC_DIR)/, $(SRCS_NAMES))
OBJS            = $(addprefix $(OBJ_DIR)/, $(SRCS_NAMES:.c=.o))

LIBS            = $(DIR_COLLECTOR)/collector.a \
                  $(DIR_LIBFT)/libft.a \
                  $(DIR_GNL)/get_next_line.a \
                  $(DIR_FTPRINTF)/ft_printf.a \
                  $(DIR_MINILBIX)/libmlx.a \
                  -L $(DIR_MINILBIX) -lmlx -L/usr/X11R6/lib -lXext -lX11 -lm -lbsd

RM              = rm -rf

all: libs $(NAME)

libs:
	@echo "Compiling libraries..."
	@make -s -C $(DIR_GNL)
	@make -s -C $(DIR_FTPRINTF)
	@make -s -C $(DIR_LIBFT)
	@make -s -C $(DIR_COLLECTOR)
	@make -s -C $(DIR_MINILBIX) > /dev/null 2>&1

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)
	@echo "Game ready! Run with: ./$(NAME) maps/map.ber"

clean:
	@$(RM) $(OBJ_DIR)
	@make -s -C $(DIR_GNL) clean
	@make -s -C $(DIR_FTPRINTF) clean
	@make -s -C $(DIR_LIBFT) clean
	@make -s -C $(DIR_COLLECTOR) clean
	@make -s -C $(DIR_MINILBIX) clean > /dev/null 2>&1
	@echo "Object files cleaned."

fclean: clean
	@$(RM) $(NAME)
	@make -s -C $(DIR_GNL) fclean
	@make -s -C $(DIR_FTPRINTF) fclean
	@make -s -C $(DIR_LIBFT) fclean
	@make -s -C $(DIR_COLLECTOR) fclean > /dev/null 2>&1
	@echo "Fully cleaned."

re: fclean all

.PHONY: all clean fclean re libs