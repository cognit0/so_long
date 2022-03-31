#include "so_long.h"

static void	cleanWin(t_mlx *handle)
{
	for (int x = 0; x < handle->width; x++)
		for (int y = 0; y < handle->height; y++)
			mlx_put_pixel_fast(handle->data, x, y, 0x00FFFF00);
}

int  	ft_frame(t_mlx *handle)
{
	cleanWin(handle);
	mlx_put_image_to_window(handle->mlx, handle->win, handle->data->img, 0, 0);
	return (0);
}