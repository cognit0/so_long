#include "so_long.h"

int		put_player_move(t_mlx *handle, int x, int y)
{
	int draw_x = (x / 32) - 1;
	int draw_y = (y / 32) - 1;
	for (int i = draw_x; i < draw_x + 3; i++)
		for (int j = draw_y; j < draw_y + 3; j++)
		{
			if (i == x / 32 && j == y / 32)
				sprite_draw(handle, handle->sprite_player, i, j);
			else if (handle->map[j][i] == '1')
				sprite_draw(handle, handle->sprite_wall, i, j);
			else if (handle->map[j][i] == '0' || handle->map[j][i] == 'P')
				sprite_draw(handle, handle->sprite_back, i, j);
			else if (handle->map[j][i] == 'C')
				sprite_draw(handle, handle->sprite_collectable, i, j);
			else if (handle->map[j][i] == 'E')
				exit_draw(handle, i, j);
		}
	for (int i = 0; i < handle->map_width / 32; i++)
		sprite_draw(handle, handle->sprite_wall, i, 0);
	return (0);
}

int	ft_frame(t_mlx *handle)
{
	if (handle->collectable_obj > 0)
		check_player_on_item(handle, handle->player_x, handle->player_y);
	else
		check_player_on_exit(handle, handle->player_x, handle->player_y);
	put_player_move(handle, handle->player_x, handle->player_y);
	put_move_count(handle);
	return (0);
}