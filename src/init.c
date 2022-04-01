#include "so_long.h"


static t_data *data_init(t_mlx *handle)
{
	t_data *data;

	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		ft_kill("DATA MALLOC ERROR exit(1)\n");
	data->img = mlx_new_image(handle->mlx, handle->map_width, handle->map_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,&data->endian);
	return (data);
}

// window size.
static void	size_window_init(t_mlx *handle)
{
	int	i;

	handle->map_width = ft_strlen(handle->map[0]) * 32;
	i = 0;
	while (handle->map[i] != NULL)
		i++;
	handle->map_height = i * 32;
}



static	void sprite_init(t_mlx *handle)
{
	handle->sprite_back = mlx_xpm_file_to_image(handle->mlx, "img/back.xpm", &handle->sprite_w ,&handle->sprite_h);
	handle->sprite_wall = mlx_xpm_file_to_image(handle->mlx, "img/wall.xpm", &handle->sprite_w, &handle->sprite_h);
	handle->sprite_collectable = mlx_xpm_file_to_image(handle->mlx, "img/collectable.xpm", &handle->sprite_w ,&handle->sprite_h);
	handle->sprite_exit = mlx_xpm_file_to_image(handle->mlx, "img/exitof.xpm", &handle->sprite_w, &handle->sprite_h);
	handle->sprite_player = mlx_xpm_file_to_image(handle->mlx, "img/player_turn_front.xpm", &handle->sprite_w, &handle->sprite_h);
	if (!handle->sprite_collectable)
		ft_kill("Sprite hatasi");
}



void	handle_init(t_mlx *handle)
{
	handle->mlx = mlx_init();
	size_window_init(handle);
	handle->win = mlx_new_window(handle->mlx, handle->map_width, handle->map_height, "so_long");
	handle->data = data_init(handle);
	sprite_init(handle);
	render_map(handle);
}

