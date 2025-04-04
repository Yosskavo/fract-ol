NAME = so_long

SRC = ft_check.c     ft_nbr.c     ft_putadress.c    ft_putone.c  ft_strlen.c  so_long.c\
      ft_countnbr.c  ft_printf.c  ft_putchar.c      ft_putstr.c  ft_unint.c   ft_error.c\
      ft_putnbr_base.c ft_strcmp.c get_next_line_utils.c get_next_line.c ft_split.c ft_substr.c \
      ft_strdup.c ft_strlcpy.c ft_putstr_fd.c 

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
