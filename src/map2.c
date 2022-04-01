#include "so_long.h"

//free map.
void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

// draw sprite
static void	sprite_draw(t_mlx *handle, void *sprite, int x, int y)
{
	mlx_put_image_to_window
		(handle->mlx, handle->win, sprite, x * 32, y * 32);
}

//draw background
static void	player_draw(t_mlx *handle, void *sprite, int x, int y)
{
	handle->player_x = x;
	handle->player_y = y;
	sprite_draw(handle, sprite, x, y);
}

static void	exit_draw(t_mlx *handle, int x, int y)
{
	if (handle->collectable_obj == 0)
	{
		mlx_destroy_image(handle->mlx, handle->sprite_exit);
		handle->sprite_exit = mlx_xpm_file_to_image
			(handle->mlx, "img/exiton.xpm", &handle->sprite_w, &handle->sprite_h);
	}
	sprite_draw(handle, handle->sprite_exit, x, y);
}

int	render_map(t_mlx *handle)
{
	int	x;
	int	y;

	y = 0;
	while (handle->map[y])
	{
		x = 0;
		while (handle->map[y][x])
		{
			if (handle->map[y][x] == '1')
				sprite_draw(handle, handle->sprite_wall, x, y);
			else if (handle->map[y][x] == '0')
				sprite_draw(handle, handle->sprite_back, x, y);
			else if (handle->map[y][x] == 'P')
				player_draw(handle, handle->sprite_player, x, y);
			else if (handle->map[y][x] == 'C')
				sprite_draw(handle, handle->sprite_collectable, x, y);
			else if (handle->map[y][x] == 'E')
				exit_draw(handle, x, y);
			x++;
		}
		y++;
	}
	return (0);
}


// int	exit_game(t_mlx *handle)
// {
// 	free_map(handle->map);
// 	mlx_destroy_image(handle->mlx, handle->img_backg);
// 	mlx_destroy_image(handle->mlx, handle->img_wall);
// 	mlx_destroy_image(handle->mlx, handle->img_player);
// 	mlx_destroy_image(handle->mlx, handle->img_colect);
// 	mlx_destroy_image(handle->mlx, handle->img_exit);
// 	mlx_destroy_window(handle->mlx, handle->win);
// 	// mlx_destroy_display(handle->mlx);
// 	free(handle->mlx);
// 	exit(0);
// 	return (0);
// }