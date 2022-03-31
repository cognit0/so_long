#include "so_long.h"

// char map[11][7] = 
// {
// 	"1111111111",
// 	"1000000001",
// 	"1000000001",
// 	"1000000001",
// 	"1000000001",
// 	"1000000001",
// 	"1111111111"
// };

int main(int argc, char **argv)
{
	t_mlx *handle;

	handle = handle_init(600, 400);

	mlx_loop_hook(handle->mlx, ft_frame, handle);
	mlx_hook(handle->win, 2, 1L<<0, ft_keyPressed, handle);
	mlx_hook(handle->win, 17, 0L, ft_kill, "");
	mlx_loop(handle->mlx);
	return (0);
}