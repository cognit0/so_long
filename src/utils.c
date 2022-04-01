#include "so_long.h"

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
		str[i] = num % 10 + 48;
		num /= 10;
		i--;
	}
	return (str);
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