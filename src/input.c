#include "so_long.h"
#include "head_data.h"

static int collision(t_mlx *handle, int keycode)
{
	int x;
	int y;

	x = handle->player_x / 32;
	y = handle->player_y / 32;
	if (keycode == KEY_D && handle->map[y][x + 1] != '1')
		return (1);
	else if (keycode == KEY_A && handle->map[y][x - 1] != '1')
		return (1);
	else if (keycode == KEY_W && handle->map[y - 1][x] != '1')
		return (1);
	else if (keycode == KEY_S && handle->map[y + 1][x] != '1')
		return (1);
	return (0);
}

int  ft_keyPressed(int keycode, t_mlx *handle)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(handle->mlx, handle->win);
		ft_kill("");
	}
	else if (keycode == KEY_D && collision(handle, KEY_D))
	{
		handle->player_x+=32;
		handle->number_of_moves++;
	}
	else if (keycode == KEY_W && collision(handle, KEY_W))
	{
		handle->player_y-=32;
		handle->number_of_moves++;
	}
	else if (keycode == KEY_A && collision(handle, KEY_A))
	{
		handle->player_x-=32;
		handle->number_of_moves++;
	}
	else if (keycode == KEY_S && collision(handle, KEY_S))
	{
		handle->player_y+=32;
		handle->number_of_moves++;
	}
	return (0);
}