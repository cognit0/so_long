#include "so_long.h"

static void	cleanWin(t_mlx *handle)
{
	for (int x = 0; x < handle->map_width; x++)
		for (int y = 0; y < handle->map_height; y++)
			mlx_put_pixel_fast(handle->data, x, y, BLUE);
}



void	ft_handle_play(t_mlx *handle)
{
	mlx_loop_hook(handle->mlx, ft_frame, handle);
	mlx_hook(handle->win, 2, 1L<<0, ft_keyPressed, handle);
	mlx_hook(handle->win, 17, 0L, ft_kill, "");
}



static int check_player_on_item(t_mlx *handle, int x, int y)
{
	if (handle->map[y / 32][x / 32] == 'C')
	{
		handle->collectable_obj--;
		handle->map[y / 32][x / 32] = '0';
	}
	return (0);
}



static int check_player_on_exit(t_mlx *handle, int x, int y)
{
	if (handle->map[y / 32][x / 32] == 'E')
		ft_kill("BYE");

	return (0);
}


int	ft_frame(t_mlx *handle)
{
	cleanWin(handle);
	if (handle->collectable_obj > 0)
		check_player_on_item(handle, handle->player_x, handle->player_y);
	else	
		check_player_on_exit(handle, handle->player_x, handle->player_y);
	render_map(handle);
	put_move_count(handle);
	return (0);
}