/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:20:09 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/03/19 16:46:19 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_hash(char *data)
{
	int	key;
	int	i;

	key = 0;
	i = 0;
	while (data[i])
	{
		key = key + data[i] * ft_pow(P, i);
		i++;
	}
	return (key % HTSIZE);
}

void			ft_create_htable(int len)
{
	int i;

	i = 0;
	if ((g_htable = (t_htable**)malloc(sizeof(t_htable*) * len)) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	while (i < len)
		g_htable[i++] = NULL;
}

t_htable	*ft_insert_room(t_room *room)
{
	t_htable	*p;
	t_htable	*p0;
	int			key;

	key = ft_hash(room->name);
	if ((p = (t_htable*)malloc(sizeof(t_htable))) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	p0 = g_htable[key];
	g_htable[key] = p;
	p->next = p0;
	p->rooms = room;
	return (p);
}

t_htable	*ft_insert_link(char *room, char *link)
{
	t_htable	*p;
	//int			key;
	int			i;

	p = ft_find_data(room);
	i = 0;
	if (p->rooms->links == NULL)
	{
		if ((p->rooms->links = (char**)ft_memalloc(sizeof(char*) *\
												p->rooms->num_links)) == NULL)
			ft_exit("ERROR: MALLOC ERROR");
		while (i < p->rooms->num_links)
			p->rooms->links[i++] = NULL;
	}
	i = 0;
	while (p->rooms->links[i] != NULL)
		i++;
	p->rooms->links[i] = ft_strdup(link);
	return (p);
}

void		ft_thprint(void)
{
	int i;

	i = 0;
	while (i < HTSIZE)
	{
		if (g_htable[i] != NULL)
			ft_print(g_htable[i]->rooms);
		i++;
	}
}

t_htable	*ft_find_data(char *data)
{
	t_htable	*p;
	int			key;

	key = ft_hash(data);
	p = g_htable[key];
	while (p != NULL)
	{
		if (!ft_strcmp(p->rooms->name, data))
			return (p);
		p = p->next;
	}
	return (p);
}

void		ft_del_htable(void)
{
	int 		i;
	t_htable	*ptr;

	i = 0;
	while (i < HTSIZE)
	{
		ptr = g_htable[i];
		while (ptr != NULL)
		{
			ft_del_room(&(ptr->rooms));
			ptr = ptr->next;
		}
		i++;
	}
	free(g_htable);
}