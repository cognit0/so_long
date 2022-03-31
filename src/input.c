#include "so_long.h"
#include "head_data.h"

int  ft_keyPressed(int keycode, t_mlx *handle)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(handle->mlx, handle->win);
		ft_kill("");
	}

	return (0);
}