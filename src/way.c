#include "lem_in.h"

void		ft_del_useless_links(char *data)
{
	int			i;
	t_room		*room;
	int			bfs_level;

	room = ft_find_data(data);
	i = 0;
	while (i < room->num_links)
	{
		if (room->links[i] != NULL)
		{
			bfs_level = ft_find_data(room->links[i])->bfs_level;
			if (room->bfs_level == bfs_level || bfs_level == -1)
				ft_strdel(&(room->links[i]));
		}
		i++;
	}
}

int			ft_deadend(char *data)
{
	t_room	*room;
	int		i;
	int		count;

	room = ft_find_data(data);
	if (room->bfs_level == 0)
		return(1);
	i = 0;
	count = 0;
	while (i < room->num_links)
	{
		if (room->links[i] != NULL)
			if (ft_find_data(room->links[i])->bfs_level > room->bfs_level)
				count++;
		i++;
	}
	return (count);
}

int        ft_del_align_links(char *data)
{
	if (!ft_strcmp(ft_find_end()->name, data))
		return (INT_MAX);
	t_room	*room;
	int		i;
	int		count;

	i = 0;
	room = ft_find_data(data);
	ft_del_useless_links(data);
	while (i < room->num_links)
	{
		if (room->links[i] != NULL)
		{
			if (ft_find_data(room->links[i])->bfs_level > room->bfs_level)
			{
				count = ft_del_align_links(room->links[i]);
				(count == 0) ? ft_strdel(&(room->links[i])) : 0;
			}
			// else
			// 	ft_strdel(&(room->links[i]));
		}
		i++;
	}
	return (ft_deadend(data));
}
