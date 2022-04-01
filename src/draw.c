#include "so_long.h"

int	mlx_drawline_coords(t_mlx *handle, int bx, int dx, int by, int dy, int color)
{
	double deltaX = dx - bx;
	double deltaY = dy - by;
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	double pixelX = bx;
	double pixelY = by;
	while (pixels)
	{
		mlx_put_pixel_fast(handle->data, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;

		--pixels;
	}
	return (0);
}



void	mlx_put_pixel_fast(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}



int	mlx_check_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	if (*(unsigned int*)dst == (unsigned int )color)
		return (1);
	return (0);
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
