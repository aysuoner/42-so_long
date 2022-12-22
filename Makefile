NAME	= so_long
SRC		= error_free.c \
		main.c \
		$(wildcard map_ctrl/*.c) \
		$(wildcard put_the_img/*.c) \
		$(wildcard key_events/*.c) \
		$(wildcard asistant/*.c)
OBJ 	= $(SRC:.c=.o)
PF		= ft_printf/libftprintf.a
CFLAGS	= -Wall -Wextra -Werror
LFLAGS	= -framework OpenGL -framework AppKit -L./mlx -lmlx -L./ft_printf -lftprintf

all: $(NAME)

$(NAME): $(OBJ) $(PF)
	make -C ./mlx 2> /dev/null
	gcc $(CFLAGS) $(LFLAGS) $(OBJ) -o $(NAME)

$(PF):
	make -C ./ft_printf

clean:
	make -C ./mlx clean
	make -C ./ft_printf clean
	rm -rf $(OBJ) 

fclean:
	make -C ./ft_printf fclean
	make -C ./mlx clean
	rm -rf $(OBJ) 
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all