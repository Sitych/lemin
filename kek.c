#include "libft.h"

int main()
{
	int x = 10;
	int n[5] = {1, 5, 16, 10, 50};

	for (int i = 0; i < 5; i++) 
		ft_printf("%zu\n", ft_pow(x, n[i]));
}
