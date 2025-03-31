#include "fractol.h"

int main ()
{
	void *y_init, *y_wind;

	y_init = mlx_init();
	y_wind = mlx_new_window(y_init, 600, 600, "fract-ol");
	mlx_loop(y_init);
	mlx_destroy_window(y_init, y_wind);
	mlx_destroy_display(y_init);
	free(y_init);
}
