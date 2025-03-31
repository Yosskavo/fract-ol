NAME = fractol

SRC = fractol.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

MLXFLAGS = -L/usr/include/minilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lz

%.o : %.c
	gcc -c $< -o $@

$(NAME) : $(OBJ)
	gcc $(OBJ) -o $(NAME) $(MLXFLAGS)

clean : 
	@rm -fv $(OBJ)

fclean : clean
	@rm -fv $(NAME)

re : fclean all

.PHONY : clean re all fclean
