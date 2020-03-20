// add 42 header
#include "lem_in.h"

void ft_swap_links(char **str)
{
	char **smpl;
	char *x;
	char *y;
	char *tmp;
	char delimeter;

	delimeter = '-';
	smpl = ft_strsplit(*str, '-');
	y = smpl[0];
	x = smpl[1];
	if (ft_strcmp(x, y) == 0)
		ft_exit("ERROR: INVALID COORDINATES");
	else if (ft_strcmp(y, x) < 0)
	{
		ft_free((void **)smpl, 3);
		return ;
	}
	else
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(x) + ft_strlen(y) + 2))))
			ft_exit("ERROR: MALLOC ERROR");
		tmp = ft_strcpy(tmp, x);
		tmp = ft_strncat(tmp, &delimeter, 1);
		tmp = ft_strcat(tmp, y);
		ft_strcpy(*str, tmp);
	}
	free(tmp);
	ft_free((void **)smpl, 3);
	ft_putstr(*str);
	ft_putchar('\n');
}
