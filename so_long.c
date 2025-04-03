#include "so_long.h"

typedef struct s_lst 
{
	void *y_init;
	void *y_wind;
} t_lst;

void ft_free_1(void *y_init, void *y_wind)
{
	mlx_destroy_window(y_init, y_wind);
	mlx_destroy_display(y_init);
	free(y_init);
	exit(0);
}

int key_handler(int key, void *ptr)
{
	t_lst *halo;

	halo = (t_lst *)ptr;
	if (key == XK_Escape)
		ft_free_1(halo->y_init, halo->y_wind);
	return (0);
}

int close_wind(void *ptr)
{       
        t_lst *halo;
        
        halo = (t_lst *)ptr;
        ft_free_1(halo->y_init, halo->y_wind);
        return (0);
}

int main(int ac, char **av)
{
	t_lst y;
	
	if (ac != 2)
		return (ft_printf("input: ./so_long <map.ber>"), 1);
	ft_check(av[1]);
	y.y_init = mlx_init();
	y.y_wind = mlx_new_window(y.y_init, 600, 600, "so_long");
	mlx_hook(y.y_wind, 2, 1L<<0, key_handler, &y);
	mlx_hook(y.y_wind, 17, 0, close_wind, &y);
	mlx_loop(y.y_init);
	ft_free_1(y.y_init, y.y_wind);
}
