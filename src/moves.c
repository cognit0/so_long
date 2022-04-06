#include "so_long.h"

int		ft_bitch_get_d(t_mlx *handle)
{
	handle->player_x+=32;
	handle->number_of_moves++;
	mlx_destroy_image(handle->mlx, handle->sprite_player);
	handle->sprite_player = mlx_xpm_file_to_image(handle->mlx, "img/player_turn_right.xpm", &handle->sprite_w, &handle->sprite_h);
	return (0);
}

int		ft_bitch_get_w(t_mlx *handle)
{
	handle->player_y-=32;
	handle->number_of_moves++;
	mlx_destroy_image(handle->mlx, handle->sprite_player);
	handle->sprite_player = mlx_xpm_file_to_image(handle->mlx, "img/player_turn_back.xpm", &handle->sprite_w, &handle->sprite_h);
	return (0);
}

int		ft_bitch_get_a(t_mlx *handle)
{
	handle->player_x-=32;
	handle->number_of_moves++;
	mlx_destroy_image(handle->mlx, handle->sprite_player);
	handle->sprite_player = mlx_xpm_file_to_image(handle->mlx, "img/player_turn_left.xpm", &handle->sprite_w, &handle->sprite_h);
	return (0);
}

int		ft_bitch_get_s(t_mlx *handle)
{
	handle->player_y+=32;
	handle->number_of_moves++;
	handle->sprite_player = mlx_xpm_file_to_image(handle->mlx, "img/player_turn_front.xpm", &handle->sprite_w, &handle->sprite_h);
	return (0);
}
