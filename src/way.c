#include "lem_in.h"

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
			count = ft_manage_way(ft_find_data(start->name));
			start->len = count;
			if (count == 1)
				ft_del_from_links(&(start));
		}
		if (start->prev == NULL && count == 0)
			room->links = start;
		else
			start = start->next;
		count++;
	}
	return (count);
}
