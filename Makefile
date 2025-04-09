NAME = so_long

SRC = ft_check_all.c  ft_nbr.c         ft_putnbr_base.c  ft_strcmp.c   ft_substr.c            so_long.c\
      ft_check.c      ft_printf.c      ft_putone.c       ft_strdup.c   ft_tablen.c\
      ft_countnbr.c   ft_putadress.c   ft_putstr.c       ft_strlcpy.c  ft_unint.c\
      ft_error.c      ft_putchar.c     ft_putstr_fd.c    ft_strlen.c   get_next_line.c\
      ft_memset.c     ft_putchar_fd.c  ft_split.c        ft_strnstr.c  get_next_line_utils.c ft_flood.c ft_key.c ft_start.c ft_putimage.c


OBJ = $(SRC:.c=.o)

all : $(NAME)

CFLAGS = -g

MLXFLAGS = -L/usr/include/minilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lz

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	cc $(CFLAGS) $(OBJ)  -o $(NAME) $(MLXFLAGS)

clean : 
	@rm -fv $(OBJ)

fclean : clean
	@rm -fv $(NAME)

re : fclean all

.PHONY : clean re all fclean
