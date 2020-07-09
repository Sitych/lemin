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

t_room		*ft_insert_link(char *room, char *link)
{
	t_room	*p;
	t_edge	*links;

	p = ft_find_data(room);
	if (p->links == NULL)
	{
		p->links = ft_creat_edge(link);
		return (p);
	}
	links = p->links;
	while (links->next != NULL)
		links = links->next;
	links->next = ft_creat_edge(link);
	(links->next)->prev = links;
	return (p);
}

int			ft_manage_way(t_room *room)
{
	t_edge	*start;
	int		count;

	if (!ft_strcmp(ft_find_end()->name, room->name))
		return (0);
	start = room->links;
	count = 0;
	while (start != NULL)
	{
		if (ft_find_data(start->name)->bfs_level > room->bfs_level)
		{
			ft_printf("name = %s count = %d\n", start->name, count);
			count = ft_manage_way(ft_find_data(start->name));
			start->len = count;
			if (count == 1)
				ft_del_from_links(&(start));
		}
		if (start->prev == NULL && count == 1)
			room->links = start;
		else
			start = start->next;
		++count;
	}
	return (count);
}
