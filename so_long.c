#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init;
	if (!mlx_ptr)
		return (1);
	free(mlx_ptr);
	return (0);
	win_ptr = mlx_new_window(mlx_ptr, 600, 400, "test");
	if (!win_ptr)
		return(free(mlx_ptr), 1);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}