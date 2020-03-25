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
			if (room->bfs_level == bfs_level)
				ft_strdel(&(room->links[i]));
		}
		i++;
	}
}

int			ft_count_output(char *data)
{
	t_room	*room;
	int		i;
	int		count;

	room = ft_find_data(data);
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

int			ft_count_input(char *data)
{
	t_room	*room;
	int		i;
	int		count;

	room = ft_find_data(data);
	i = 0;
	count = 0;
	while (i < room->num_links)
	{
		if (room->links[i] != NULL)
			if (ft_find_data(room->links[i])->bfs_level < room->bfs_level)
				count++;
		i++;
	}
	return (count);
}

int			ft_manage_way(char *data)
{
	if (!ft_strcmp(ft_find_end()->name, data))
		return (INT_MAX);
	t_room	*room;
	int		i;
	int		count;

	i = 0;
	room = ft_find_data(data);
	ft_del_useless_links(data);
	room->in = ft_count_input(data);
	while (i < room->num_links)
	{
		if (room->links[i] != NULL)
		{
			if (ft_find_data(room->links[i])->bfs_level > room->bfs_level)
			{
				count = ft_manage_way(room->links[i]);
				(count == 0) ? ft_strdel(&(room->links[i])) : 0;
			}
		}
		i++;
	}
	room->out = ft_count_output(data);
	return (room->out);
}

