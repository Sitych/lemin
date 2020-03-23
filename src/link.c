#include "lem_in.h"

int		ft_val_links2(char **split, int j, int i, char **links)
{
	while (j <= i)
	{
		if (split[j][0] == '#')
		{
			j++;
			continue ;
		}
		if ((ft_find_data(links[0]) == NULL) || (ft_find_data(links[1]) == NULL))
			ft_exit("ERROR: NO SUCH ROOM NAME IN THE LINK INPUT");
		if (ft_strcmp(links[0], links[1]) == 0)
			ft_exit("ERROR: LINK IS LINKED TO ITSELF");
		if (j != i)
			if (ft_strcmp(split[j], split[i]) == 0)
				ft_exit("ERROR: LINK IS REPEATED");
		if (j == i)
		{
			ft_find_data(links[0])->rooms->num_links++;
			ft_find_data(links[1])->rooms->num_links++;
		}
		j++;
	}
	return (0);
}

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

void		ft_set_links(char ***links, int i, int all)
{
	char		**link;
	int			j;

	j = 0;
	while (j < all - i)
	{
		
		if (links[j]== NULL)
		{
			j++;
			continue ;
		}
		link = links[j];
		ft_insert_link(link[0], link[1]);
		ft_insert_link(link[1], link[0]);
		ft_free((void**)links[j], 2);
		j++;
	}
	free(links);
}

void		ft_del_useless_links(char *data)
{
    int			i;
    t_room		*room;

    room = ft_find_data(data)->rooms;
    i = 0;
	while (room->links[i])
	{
		if (room->bfs_level == ft_find_data(room->links[i])->rooms)
		i++;
	}
}