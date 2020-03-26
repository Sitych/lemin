#include "lem_in.h"

void	ft_output_fork(char *data)
{
	if (!ft_strcmp(ft_find_start()->name, data))
		return ;
	t_room	*room;
	int		i;
	i = 0;

	int q; //TO_DELETE

	room = ft_find_data(data);
//	ft_printf("ROOM NAME: %s, OUT_LINKS = %d\n", room->name, room->out);
	while (i < room->num_links)
	{
		if (room->links[i] != NULL)
		{
			if (ft_find_data(room->links[i])->bfs_level < room->bfs_level)
			{
				if (ft_find_data(room->links[i])->out > 1 && ft_find_data(room->links[i])->bfs_level != 0)
				{
					ft_printf("ROOM NAME: %s, OUT_LINKS = %d ", ft_find_data(room->links[i])->name, ft_find_data(room->links[i])->out);
					q = ft_manage_output_fork(ft_find_data(room->links[i])->name);
					ft_printf("BEST_OUT_LINK: %s\n", ft_find_data(room->links[i])->links[q]);
					//ft_delete_output_fork()
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
	int		best_link_id;

	min_way = INT_MAX;
	best_link_id = -1;
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
				way = 0;
				while (find->bfs_level != INT_MAX)
				{
					// ft_printf("ROOM NAME: %s, OUT_LINKS = %d\n", find->name, find->out);
					if (way == 0)
						find = ft_find_data(room->links[i]);
					else
						find = ft_find_suitable_link_for_output_fork(find);
					way++;
				}
				find = room;
				ft_printf("PATH LENGTH = %d\n", way);
				if (way < min_way)
				{
					min_way = way;
					best_link_id = i;
				}
			}
		}
		i++;
	}
	return (best_link_id);
}

t_room		*ft_find_suitable_link_for_output_fork(t_room *room)
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