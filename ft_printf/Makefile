NAME = ft_printf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =	ft_printf.c ft_printf_utils.c 
OBJS = $(SRCS:.c=.o)
RM	= rm -f
AR	= ar rc

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUSOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
