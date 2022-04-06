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

static void	player_draw(t_mlx *handle, void *sprite, int x, int y)
{
	handle->player_x = x;
	handle->player_y = y;
	sprite_draw(handle, sprite, x, y);
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
			else if (handle->map[y][x] == '0' || handle->map[y][x] == 'P')
				sprite_draw(handle, handle->sprite_back, x, y);
			else if (handle->map[y][x] == 'C')
				sprite_draw(handle, handle->sprite_collectable, x, y);
			else if (handle->map[y][x] == 'E')
				exit_draw(handle, x, y);
			x++;
		}
		y++;
	}
	sprite_draw(handle, handle->sprite_player, handle->player_x / 32, handle->player_y / 32);
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