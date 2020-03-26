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

void		ft_path_forming(int ants)
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
		routes[j] = ft_create_path(ft_find_data(room->links[i]), ft_find_data(room->links[i])->bfs_level, ants);
		t_path	*ptr;
		ptr = routes[j];
		while (ptr != NULL)
		{
			ft_printf("ROOM NAME %s: , ANTS IN ROOM: %d, LENGTH = %d\n", ptr->room_name, ptr->ant_quantity, ptr->path_length);
			ptr = ptr->next;
		}
		j++;
		i++;
	}
}

t_path		*ft_create_path(t_room *room, int length, int ants)
{
	t_path		*route;
	t_path		*tmp;

	route = ft_create_path_element(ft_find_end(), 0, length);
	route->next = NULL;
	while (room->bfs_level != 0)
	{
		tmp = ft_create_path_element(room, 0, length);
		route->prev = tmp;
		tmp = route;
		route = route->prev;
		route->next = tmp;
		room = ft_find_suitable_link(room);
	}
	tmp = ft_create_path_element(room, ants, length);
	route->prev = tmp;
	tmp = route;
	route = route->prev;
	route->next = tmp;
	tmp->prev = NULL;
	return (route);
}

t_room		*ft_find_suitable_link(t_room *room)
{
	int			i;

	i = 0;
	while (i < room->num_links)
	{
		if (room->links[i] != NULL)
			if (ft_find_data(room->links[i])->bfs_level < room->bfs_level)
				return (ft_find_data(room->links[i]));
		i++;
	}
	return (NULL);
}

t_path		*ft_create_path_element(t_room *room, int ants, int length)
{
	t_path	*element;

	if ((element = (t_path*)malloc(sizeof(t_path))) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	if ((element->room_name = ft_strdup(room->name)) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	element->ant_quantity = ants;
	element->path_length = length + 1;
	return (element);
}
