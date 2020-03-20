// add 42 header
#include "lem_in.h"

char	**ft_swap_links(char **str, char **link)
{
	char	delimeter;
	char	*buf;

	delimeter = '-';
	if (ft_strcmp(link[0], link[1]) <= 0)
		return (link);
	else
	{
		buf = link[0];
		link[0] = link[1];
		link[1] = buf;
		ft_strcpy(*str, link[1]);
		ft_strncat(*str, &delimeter, 1);
		ft_strcat(*str, link[0]);
	}
	return (link);
}
