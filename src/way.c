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

void        ft_del_align_links(char *data)
{
	if (!ft_strcmp(ft_find_end()->name, data))
		return ;
	t_room	*room;
	int		i;

	i = 0;
	room = ft_find_data(data);
	ft_del_useless_links(data);
	while (i < room->num_links)
	{
		if (room->links[i] != NULL)
		{
			if (ft_find_data(room->links[i])->bfs_level > room->bfs_level)
				ft_del_align_links(room->links[i]);
			// else
			// 	ft_strdel(&(room->links[i]));
		}
		i++;
	}
}

void	ft_del_deadend(char *data)
{
	
}