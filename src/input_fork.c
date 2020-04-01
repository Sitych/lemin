#include "lem_in.h"

int		ft_minway(t_room *room, char *link_fork)
{
	int		len;
	t_edge	*links;

	while (room->out == 1 && room->bfs_level != 0)
	{
		links = room->links;
		while (ft_find_data(links->name)->bfs_level > room->bfs_level)
			links = links->next;
		// link_fork = room->name;
		room = ft_find_data(links->name);
	}
	if (room->bfs_level == 0)
		return (-1);
	len = INT_MAX;
	links = room->links;
	while (links != NULL)
	{
		if ((links->len < len) && (ft_strcmp(links->name, room->name) != 0))
			len = links->len;
		links = links->next;
	}
	return (len);
}

void	ft_del_input_fork(t_room *room)
{
	t_edge	*links;
	int		len;
	int		len_min;
	char	*name;

	links = room->links;
	len_min = INT_MAX;
	while (links != NULL)
	{
		if (room->bfs_level > ft_find_data(links->name))
		{
			if ((len = ft_minway(ft_find_data(links->name), room->name)) < len_min)
			{
				if (len == -1)
					len_min = links->len;
				else
					len_min = len;
				name = links->name;
			}
		}
		links = links->next;
	}
}

void	ft_input_fork()
{
	t_room	*room;
	t_queue	*ptr;
	t_queue	*elem;
	t_edge	*links;
	int		count;

	ptr = ft_creat_elem(ft_find_start()->name);
	ft_find_start()->flag = 1;
	while (ft_isempty(ptr))
	{
		elem = ft_pop(&ptr);
		room = ft_find_data(elem->name);
		if (room->in > 1)
			ft_del_input_fork(room);
		links = ft_find_data(elem->name)->links;
		while (links != NULL)
		{
			room = ft_find_data(links->name);
			if (room->bfs_level != INT_MAX && room->flag == 0)
			{
				room->flag = 1;
				ptr = ft_push(ptr, links->name);
			}
			links = links->next;
		}
		ft_del_elem(&elem);
	}
}