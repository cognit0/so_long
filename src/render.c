#include "so_long.h"


void	ft_handle_play(t_mlx *handle)
{
	// mlx_loop_hook(handle->mlx, ft_frame, handle);
	mlx_hook(handle->win, 2, 1L<<0, ft_keyPressed, handle);
	mlx_hook(handle->win, 17, 0L, ft_kill, "");
	mlx_hook(handle->win, 9, 1L << 21, render_map, handle);
}


static void	cleanWin(t_mlx *handle)
{
	for (int x = 0; x < handle->map_width; x++)
		for (int y = 0; y < handle->map_height; y++)
			mlx_put_pixel_fast(handle->data, x, y, BLUE);
}



int	ft_frame(t_mlx *handle)
{
	cleanWin(handle);
	mlx_put_image_to_window(handle->mlx, handle->win, handle->data->img, 0, 0);
	return (0);
}