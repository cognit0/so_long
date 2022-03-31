#include "so_long.h"

int	ft_kill(char *str)
{
	int i;

	i = 0;
	if (str)
		while (str[i])
			write(2, &str[i++], 1);
	exit(1);
}