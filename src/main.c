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

static int	argv_checker(char *argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == 'r' && argv[i - 1] == 'e' && argv[i - 2] == 'b'
		&& argv [i - 3] == '.')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	handle;

	if (argc == 2)
	{
		handle.map = read_map(argv[1]);
		if (map_checker(&handle) && argv_checker(argv[1]))
		{
			handle_init(&handle);
			ft_handle_play(&handle);
			mlx_loop(handle.mlx);
		}
		else
		{
			if (handle.map)
			free_map(handle.map);
			printf("Error\nInvalid Map");
			free_all(&handle);
			exit(1);
		}
	}
	else
	{
		printf("Error\nInvalid Syntax");
		exit(1);
	}
	return (0);
}