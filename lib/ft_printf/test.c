#include "ft_printf.h"

int main ()
{
	int i = ft_printf("%u, %u %u, %p\n", 422, 1228, 123, INT_MAX);
	ft_printf("%d\n",i);
	int a = printf("%u, %u %u, %p\n", 422, 1228, 123, -1);
	printf("%d\n",a);
}