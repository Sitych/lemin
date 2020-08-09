/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:27:41 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/08/08 21:34:52 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*ft_creat_room(char *name, int x, int y)
{
	t_room		*tmp;

	if ((tmp = (t_room*)malloc(sizeof(t_room))) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	tmp->name = ft_strdup(name);
	tmp->x = x;
	tmp->y = y;
	tmp->links = NULL;
	tmp->flag = 0;
	tmp->bf= INFINITY;
	tmp->ants = 0;
	tmp->ant_id = 0;
	return (tmp);
}

t_htable	*ft_insert_room(t_room *room)
{
	t_htable	*p;
	t_htable	*p0;
	int			key;

	// ft_print(room);
	key = ft_hash(room->name);
	if ((p = (t_htable*)malloc(sizeof(t_htable))) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	p0 = g_htable[key];
	g_htable[key] = p;
	p->next = p0;
	p->rooms = room;
	return (p);
}

void		ft_del_room(t_room **ptr)
{
	t_room	*room;
	t_edge	*edge;

	room = *ptr;
	if (room != NULL)
	{
		ft_strdel(&(room->name));
		while (room->links != NULL)
		{
			edge = room->links;
			room->links = room->links->next;
			ft_del_edge(edge);
		}
	}
	free(room);
	room = NULL;
}

void		ft_print(t_room *tmp)
{
	t_edge	*ptr;

	ft_printf("name = %s bfs_level = %d x = %d y = %d\n", tmp->name, tmp->bf, tmp->x, tmp->y);
	ptr = tmp->links;
	while (ptr != NULL)
	{
		ft_printf("link name = %s; ", ptr->name);
		ptr = ptr->next;
	}
	ft_putchar('\n');
}