RESET           = \033[0m
RED             = \033[31m
GREEN           = \033[32m
YELLOW          = \033[33m
BLUE            = \033[34m

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

INC             = -I $(INC_DIR) -I $(DIR_LIBFT) -I $(DIR_GNL) -I $(DIR_FTPRINTF) -I $(DIR_COLLECTOR) -I $(DIR_MINILBIX)

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

define print_msg
	@echo "$1===============================================$(RESET)"
	@echo "$1$2$(RESET)"
	@echo "$1===============================================$(RESET)"
endef

all: libs $(NAME)

libs:
	$(call print_msg,$(YELLOW),Compiling libraries...)
	@make -s -C $(DIR_GNL)
	$(call print_msg,$(BLUE),get_next_line compiled.)
	@make -s -C $(DIR_FTPRINTF)
	$(call print_msg,$(BLUE),ft_printf compiled.)
	@make -s -C $(DIR_LIBFT)
	$(call print_msg,$(BLUE),libft compiled.)
	@make -s -C $(DIR_COLLECTOR)
	$(call print_msg,$(BLUE),collector compiled.)
	@make -s -C $(DIR_MINILBIX)
	$(call print_msg,$(BLUE),minilibx compiled.)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	$(call print_msg,$(YELLOW),Linking $(NAME)...)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)
	$(call print_msg,$(BLUE),Linking completed.)
	$(call print_msg,$(GREEN),Game ready! Run with: ./$(NAME) (FILE_NAME).ber)

clean:
	@$(RM) $(OBJ_DIR)
	$(call print_msg,$(RED),Object files cleaned.)
	@make -s -C $(DIR_GNL) clean
	@make -s -C $(DIR_FTPRINTF) clean
	@make -s -C $(DIR_LIBFT) clean
	@make -s -C $(DIR_COLLECTOR) clean
	@make -s -C $(DIR_MINILBIX) clean
	$(call print_msg,$(RED),Library files cleaned.)

fclean: clean
	@$(RM) $(NAME)
	$(call print_msg,$(RED),Executable removed.)
	@make -s -C $(DIR_GNL) fclean
	@make -s -C $(DIR_FTPRINTF) fclean
	@make -s -C $(DIR_LIBFT) fclean
	@make -s -C $(DIR_COLLECTOR) fclean
	$(call print_msg,$(RED),Fully cleaned.$(RESET))

re: fclean all

.PHONY: all clean fclean re libs