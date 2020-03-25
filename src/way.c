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

void		ft_path_forming()
{
	int		ways;
	int		i;
	int		j;
	t_room	*room;
	t_path	**routes;

	ways = 0;
	i = 0;
	room = ft_find_end();
	while (i < room->num_links)
	{
		if (room->links[i] != NULL)
			ways++;
		i++;
	}
	if ((routes = (t_path**)malloc(sizeof(t_path*) * ways)) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	i = 0;
	j = 0;
	while (j < ways)
	{
		if (room->links[i] == NULL)
			i++;
		routes[j] = ft_create_path(room->links[i], ft_find_data(room->links[i])->bfs_level);
		j++;
		i++;
	}
}

t_path		*ft_create_path(char *data, int length)
{
	t_path		*route;
	t_path		*tmp;
	int			i;
	int			j;
	int			bfs;

	// route = tmp;
	bfs = length;
	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < ft_find_data(data)->num_links)
		{
			if ((ft_find_data(data)->links[i] != NULL) && ((ft_find_data(ft_find_data(data)->links[i])->bfs_level) < bfs))
			{
				bfs = ft_find_data(ft_find_data(data)->links[i])->bfs_level;
				if ((tmp = (t_path*)malloc(sizeof(t_path))) == NULL)
					ft_exit("ERROR: MALLOC ERROR");
				if ((tmp->room_name = ft_strdup(ft_find_data(data)->name)) == NULL)
					ft_exit("ERROR: MALLOC ERROR");
				tmp->ant_quantity = 0;
				tmp->path_length = length;
				route->prev = tmp;
				tmp = route;
				route = route->prev;
				route->next = tmp;
			}
			j++;
		}
		i++;
	}
	tmp = NULL;
	return (tmp);
}
