RESET		= \033[0m
RED		= \033[31m
GREEN		= \033[32m
YELLOW		= \033[33m
BLUE		= \033[34m

NAME		= so_long
NAME_BONUS	= so_long_bonus

CC		= cc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= inc

SRC_BON_DIR	= src_bonus
OBJ_BON_DIR	= obj_bonus
INC_BON_DIR	= inc_bonus

DIR_GNL		= get_next_line
DIR_FTPRINTF	= ft_printf
DIR_LIBFT	= libft
DIR_COLLECTOR	= collector
DIR_MINILBIX	= minilibx-linux

INC		= -I $(INC_DIR) -I $(INC_BON_DIR) -I $(DIR_LIBFT) -I $(DIR_GNL) -I $(DIR_FTPRINTF) -I $(DIR_COLLECTOR) -I $(DIR_MINILBIX)

SRCS_NAMES	= main.c map_reader.c map_checker.c flood_fill.c \
                  mlx_processes.c render.c key_handler.c utils.c

SRCS		= $(addprefix $(SRC_DIR)/, $(SRCS_NAMES))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS_NAMES:.c=.o))

SRCS_BON_NAMES	= main_bonus.c map_reader_bonus.c map_checker_bonus.c flood_fill_bonus.c \
		  mlx_processes_bonus.c render_bonus.c key_handler_bonus.c utils_bonus.c

SRCS_BON	= $(addprefix $(SRC_BON_DIR)/, $(SRCS_BON_NAMES))
OBJS_BON	= $(addprefix $(OBJ_BON_DIR)/, $(SRCS_BON_NAMES:.c=.o))

LIBS		= $(DIR_COLLECTOR)/collector.a \
		$(DIR_LIBFT)/libft.a \
		$(DIR_GNL)/get_next_line.a \
		$(DIR_FTPRINTF)/ft_printf.a \
		$(DIR_MINILBIX)/libmlx.a \
		-L $(DIR_MINILBIX) -lmlx -L/usr/X11R6/lib -lXext -lX11 -lm -lbsd

RM		= rm -rf

define print_msg
	@echo "$1============================================================$(RESET)"
	@echo "$1$2$(RESET)"
	@echo "$1============================================================$(RESET)"
endef

all: libs $(NAME)

bonus: libs $(NAME_BONUS)

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

$(OBJ_BON_DIR)/%.o: $(SRC_BON_DIR)/%.c
	@mkdir -p $(OBJ_BON_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	$(call print_msg,$(YELLOW),Linking $(NAME)...)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)
	$(call print_msg,$(BLUE),Linking completed.)
	$(call print_msg,$(GREEN),Game ready! Run with: ./$(NAME) (FILE_NAME).ber)

$(NAME_BONUS): $(OBJS_BON)
	$(call print_msg,$(YELLOW),Linking $(NAME_BONUS)...)
	@$(CC) $(OBJS_BON) $(LIBS) -o $(NAME_BONUS)
	$(call print_msg,$(BLUE),Linking completed.)
	$(call print_msg,$(GREEN),Bonus game ready! Run with: ./$(NAME_BONUS) (FILE_NAME).ber)

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(OBJ_BON_DIR)
	$(call print_msg,$(RED),Object files cleaned.)
	@make -s -C $(DIR_GNL) clean
	@make -s -C $(DIR_FTPRINTF) clean
	@make -s -C $(DIR_LIBFT) clean
	@make -s -C $(DIR_COLLECTOR) clean
	@make -s -C $(DIR_MINILBIX) clean
	$(call print_msg,$(RED),Library files cleaned.)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	$(call print_msg,$(RED),Executable removed.)
	@make -s -C $(DIR_GNL) fclean
	@make -s -C $(DIR_FTPRINTF) fclean
	@make -s -C $(DIR_LIBFT) fclean
	@make -s -C $(DIR_COLLECTOR) fclean
	$(call print_msg,$(RED),Fully cleaned.$(RESET))

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re libs bonus rebonus