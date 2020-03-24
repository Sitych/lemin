/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:27:41 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/03/20 21:59:44 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*ft_crtrm(char *str, int bfs_level)
{
	t_room		*tmp;
	char		**lines;
	int			i;

	tmp = NULL;
	if ((lines = ft_strsplit(str, ' ')) == NULL)
		ft_exit("ERROR: SPLIT ERROR");
	if ((tmp = (t_room*)malloc(sizeof(t_room))) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	if ((tmp->name = ft_strdup(lines[0])) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	i = -1;
	while (lines[1][++i])
		if ((lines[1][i] < '0' || lines[1][i] > '9') && lines[1][i])
			ft_exit("ERROR: NO DIGIT COORD");
	tmp->x = ft_atoi(lines[1]);
	i = -1;
	while (lines[2][++i])
		if ((lines[2][i] < '0' || lines[2][i] > '9') && lines[2][i])
			ft_exit("ERROR: NO DIGIT COORD");
	tmp->y = ft_atoi(lines[2]);
	ft_free((void**)lines, 3);
	tmp->bfs_level = bfs_level;
	tmp->links = NULL;
	tmp->num_links = 0;
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
	size_t		i;
	t_room	*room;

	i = 0;
	room = *ptr;
	if (room != NULL)
	{
		ft_strdel(&(room->name));
		if (room->links)
		{
			while (room->links[i])
			{
				ft_strdel(&(room->links[i]));
				i++;
			}
			free(room->links);
		}
	}
}

void		ft_print(t_room *tmp)
{
	int i;

	i = 0;
	ft_printf("name = %s x = %d y = %d bfs_level = %d in = %d out = %d\n", tmp->name, tmp->x, tmp->y, tmp->bfs_level, tmp->in, tmp->out);
	while (i < tmp->num_links)
	{
		if (tmp->links[i] != NULL)
			ft_printf("%s\n", tmp->links[i]);
		i++;
	}
}