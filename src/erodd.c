// add 42 header
#include "lem_in.h"

char	*ft_swap_links(char *str)
{
	char *x;
	char *y;

	if (ft_strcmp(ft_strsplit(str, '-')[0], ft_strsplit(str, '-')[1]) == 0)
		ft_exit("ERROR: INVALID COORDINATES");
	else if (ft_strcmp(ft_strsplit(str, '-')[0], ft_strsplit(str, '-')[1]) < 0)
		return (str);
	else
	{
		x = ft_strsplit(str, '-')[1];
		y = ft_strsplit(str, '-')[0];
		if (!(str = (char *)malloc((sizeof(char) * (ft_strlen(x) + ft_strlen(y) + 2)))))
			ft_exit("ERROR: MALLOC ERROR");
		str = ft_strcpy(str, x);
		str = ft_strcat(str, "-");
		str = ft_strcat(str, y);
	}
	ft_putstr(str);
	ft_putchar('\n');
	return (str);
}
