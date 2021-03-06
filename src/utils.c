#include "so_long.h"

void	ft_handle_play(t_mlx *handle)
{
	mlx_loop_hook(handle->mlx, ft_frame, handle);
	mlx_hook(handle->win, 2, 1L<<0, ft_keyPressed, handle);
	mlx_hook(handle->win, 17, 0L, ft_kill, "");
}

char *ft_itoa(int num)
{
	int tmp = num;
	int i = 0;
	char *str;
	if (!num)
		return (ft_strdup("0"));
	while (tmp)
	{
		tmp/=10;
		i++;
	}
	str = (char *) malloc(sizeof(char) * i);
	i--;
	while (i >= 0)
	{
		str[i] = (num % 10) + 48;
		num /= 10;
		i--;
	}
	return (str);
}

void	free_all(t_mlx *handle)
{
	int i;

	i = 0;
	while (handle->map[i])
		free(handle->map[i++]);
	mlx_destroy_image(handle->mlx, handle->sprite_back);
	mlx_destroy_image(handle->mlx, handle->sprite_wall);
	mlx_destroy_image(handle->mlx, handle->sprite_collectable);
	mlx_destroy_image(handle->mlx, handle->sprite_exit);
	mlx_destroy_image(handle->mlx, handle->sprite_player);
	mlx_destroy_window(handle->mlx, handle->win);
	free(handle->data);
}

int	ft_kill(char *str)
{
	int i;

	i = 0;
	if (str)
		while (str[i])
			write(2, &str[i++], 1);
	exit(1);
}