#include "so_long.h"

int check_player_on_item(t_mlx *handle, int x, int y)
{
	if (handle->map[y / 32][x / 32] == 'C')
	{
		handle->collectable_obj--;
		handle->map[y / 32][x / 32] = '0';
	}
	return (0);
}

int check_player_on_exit(t_mlx *handle, int x, int y)
{
	render_exit(handle);
	if (handle->map[y / 32][x / 32] == 'E')
		ft_kill("YOU WIN");
	return (0);
}

void	sprite_draw(t_mlx *handle, void *sprite, int x, int y)
{
	mlx_put_image_to_window
		(handle->mlx, handle->win, sprite, x * 32, y * 32);
}

void	exit_draw(t_mlx *handle, int x, int y)
{
	if (handle->collectable_obj == 0)
	{
		mlx_destroy_image(handle->mlx, handle->sprite_exit);
		handle->sprite_exit = mlx_xpm_file_to_image
			(handle->mlx, "img/exiton.xpm", &handle->sprite_w, &handle->sprite_h);
	}
	sprite_draw(handle, handle->sprite_exit, x, y);
}