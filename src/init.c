#include "so_long.h"

static t_data *data_init(t_mlx *handle)
{
	t_data *data;

	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		ft_kill("DATA MALLOC ERROR exit(1)\n");
	data->img = mlx_new_image(handle->mlx, handle->width, handle->height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,&data->endian);
	return (data);
}

t_mlx *handle_init(int width, int height)
{
	t_mlx *handle;

	handle = (t_mlx *) malloc(sizeof(t_mlx));
	handle->width = width;
	handle->height = height;
	handle->mlx = mlx_init();
	handle->win = mlx_new_window(handle->mlx, width, height, "so_long");
	handle->data = data_init(handle);
	return (handle);
}