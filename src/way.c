#include "lem_in.h"

void		ft_del_useless_links(char *data)
{
	t_edge	*start;
	t_room	*room;
	int		bfs_level;

	room = ft_find_data(data);
	start = room->links;
	while (room->links != NULL)
	{
		bfs_level = ft_find_data(room->links->name)->bfs_level;
		if (room->bfs_level == bfs_level)
		{
			ft_del_from_links(&(room->links));
			if (room->links->prev == NULL)
				start = room->links;
		}
		room->links = room->links->next;
	}
	room->links = start;
}

int			ft_count_output(char *data)
{
	t_room	*room;
	t_edge	*link;
	int		count;

	room = ft_find_data(data);
	link = room->links;
	count = 0;
	while (link != NULL)
	{
		if (ft_find_data(link->name)->bfs_level > room->bfs_level)
			count++;
		link = link->next;
	}
	return (count);
}

int			ft_count_input(char *data)
{
	t_room	*room;
	t_edge	*link;
	int		count;

	room = ft_find_data(data);
	count = 0;
	link = room->links;
	while (link != NULL)
	{
		if (ft_find_data(link->name)->bfs_level < room->bfs_level)
			count++;
		link = link->next;
	}
	return (count);
}

int			ft_manage_way(t_room *room)
{
	t_edge	*start;
	int		count;

	if (!ft_strcmp(ft_find_end()->name, room->name))
		return (0);
	ft_del_useless_links(room->name);
	start = room->links;
	count = -1;
	room->in = ft_count_input(room->name);
	while (start != NULL)
	{
		if (ft_find_data(start->name)->bfs_level > room->bfs_level)
		{
			count = ft_manage_way(ft_find_data(start->name));
			start->len = count;
			if (count == -1)
				ft_del_from_links(&(start));
		}
		if (start->prev == NULL && !count)
			room->links = start;
		else
			start = start->next;
	}
	room->out = ft_count_output(room->name);
	return (count + 1);
}

/*
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
} */

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
		room = ft_find_suitable_link_up(room);
	}
	tmp = ft_create_path_element(room, ants, length);
	route->prev = tmp;
	tmp = route;
	route = route->prev;
	route->next = tmp;
	tmp->prev = NULL;
	return (route);
}

t_room		*ft_find_suitable_link_up(t_room *room)
{
	t_edge	*link;

	link = room->links;
	while (link != NULL)
	{
		// tmp = ft_find_data(link->name);
		if (ft_find_data(link->name)->bfs_level < room->bfs_level)
			return (ft_find_data(link->name));
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
