#include "lem_in.h"

void	ft_output_fork(char *data)
{
	if (!ft_strcmp(ft_find_start()->name, data))
		return ;
	t_room	*room;
	int		i;
	i = 0;

	int bad_link; //TO_DELETE

	room = ft_find_data(data);
	while (i < room->num_links)
	{
		if (room->links[i] != NULL)
		{
			if (ft_find_data(room->links[i])->bfs_level < room->bfs_level)
			{
				if (ft_find_data(room->links[i])->out > 1 && ft_find_data(room->links[i])->bfs_level != 0)
				{
					ft_printf("ROOM NAME: %s, OUT_LINKS = %d ", ft_find_data(room->links[i])->name, ft_find_data(room->links[i])->out);
					bad_link = ft_manage_output_fork(ft_find_data(room->links[i])->name);
					ft_printf("WORST_OUT_LINK: %s, link_id = %d\n", ft_find_data(room->links[i])->links[bad_link], bad_link);
					//ft_strdel(&ft_find_data(room->links[i])->links[bad_link]);
					ft_find_data(room->links[i])->out--;
					ft_delete_output_fork(ft_find_data(ft_find_data(room->links[i])->links[bad_link]));
				}
				ft_output_fork(ft_find_data(room->links[i])->name);
			}
		}
		i++;
	}
}

int		ft_manage_output_fork(char *data)
{
	t_room	*room;
	t_room	*find;
	int		min_way;
	int		way;
	int 	i;
	int		worst_link_id;

	min_way = 0;
	worst_link_id = -1;
	i = 0;
	room = ft_find_data(data);
	ft_printf("ROOM NAME: %s\n", room->name);
	find = room;
	while (i < room->num_links)
	{
		if (room->links[i] != NULL)
		{
			if (ft_find_data(room->links[i])->bfs_level > room->bfs_level)
			{
				ft_printf("FORK NAME: %s\n", ft_find_data(room->links[i])->name);
				way = 1;
				find = ft_find_data(room->links[i]);
				while (find->bfs_level != INT_MAX)
				{
					// ft_printf("ROOM NAME: %s, OUT_LINKS = %d\n", find->name, find->out);
					find = ft_find_suitable_link_down(find);
					way++;
				}
				find = room;
				ft_printf("PATH LENGTH = %d\n", way);
				if (way > min_way)
				{
					min_way = way;
					worst_link_id = i;
				}
			}
		}
		i++;
	}
	return (worst_link_id);
}

t_room		*ft_find_suitable_link_down(t_room *room)
{
	int			i;

	i = 0;
	while (i < room->num_links)
	{
		if (room->links[i] != NULL)
			if (ft_find_data(room->links[i])->bfs_level > room->bfs_level)
				return (ft_find_data(room->links[i]));
		i++;
	}
	return (NULL);
}

void		ft_delete_output_fork(t_room *room)
{
	char	*data;
	int		i;

	data = room->name;
	while (room->bfs_level != INT_MAX)
	{
		data = room->name;
		room = ft_find_suitable_link_down(room);
	}
	ft_printf("ROOM NAME: %s, TO DELETE LINK: %s\n", room->name, data);
	i = 0;
	while (i < room->num_links)
	{
		if (room->links[i] != NULL)
		{
			if (ft_strcmp(ft_find_data(room->links[i])->name, data) == 0)
				ft_strdel(&(room->links[i]));
		}
		i++;
	}
}
