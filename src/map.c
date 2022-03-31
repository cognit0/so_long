#include "so_long.h"

static int	is_retangular(char **map)
{
	int	i;

	i = 1;
	if (!map)
		return (0);
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
		i++;
	}
	return (1);
}



// is wall
static int	is_wall(char **map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (map[i] != NULL)
		i++;
	while (map[0][j] != '\0' && map[i - 1][j] != '\0')
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	len = ft_strlen(map[i]);
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}



// "P" , "E" , "C" varmi kontrolu.
static int	is_pec(t_mlx *handle)
{
	int	i;
	int	j;

	handle->collectable_obj= 0;
	handle->player_obj= 0;
	handle->exit_obj = 0;
	i = 0;
	while (handle->map[i] != NULL)
	{
		j = 0;
		while (handle->map[i][j] != '\0')
		{
			if (handle->map[i][j] == 'P')
				handle->player_obj++;
			else if (handle->map[i][j] == 'E')
				handle->exit_obj ++;
			else if (handle->map[i][j] == 'C')
				handle->collectable_obj++;
			j++;
		}
		i++;
	}
	if (handle->player_obj != 1 || handle->exit_obj  == 0 || handle->collectable_obj == 0)
		return (0);
	return (1);
}



// eger baska birsey var ise.
static int	is_validate(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != '0' && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}



// hepsini aynanda yapiyor.
int	map_checker(t_mlx *handle)
{
	if (is_retangular(handle->map) && is_wall(handle->map) && is_pec(handle)
		&& is_validate(handle->map))
		return (1);
	return (0);
}