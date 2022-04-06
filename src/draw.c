#include "so_long.h"

void	render_exit(t_mlx *handle)
{
	int x;
	int y;

	y = 0;
	while (handle->map[y])
	{
		x = 0;
		while (handle->map[y][x])
		{
			if (handle->map[y][x] == 'E')
				exit_draw(handle, x, y);
			x++;
		}
		y++;
	}
}

void	mlx_put_pixel_fast(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int  	put_move_count(t_mlx *handle)
{
	char *str;

	str = ft_itoa(handle->number_of_moves);
	mlx_string_put(handle->mlx, handle->win, 64, 0, 0x00FFFFFF, "Moves:");
	mlx_string_put(handle->mlx, handle->win, 128, 0, 0x00FFFFFF, str);
	free(str);
	str = ft_itoa(handle->collectable_obj);
	mlx_string_put(handle->mlx, handle->win, handle->map_width - 128 , 0, 0x00FFFFFF, "Candy:");
	mlx_string_put(handle->mlx, handle->win, handle->map_width - 64, 0, 0x00FFFFFF, str);
	free(str);
	return (0);
}
