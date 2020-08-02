/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurbale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:04:29 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/07/29 20:42:01 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_find_edge(t_room *from, t_room *to, int w)
{
	t_edge	*link;

	link = from->links;
	while (ft_strcmp(to->name, link->name))
		link = link->next;
	link->weight = w;
}

t_edge	*ft_find_minus_one_link(t_edge *links)
{
	while (links != NULL)
	{
		if (links->weight == -1 && ft_find_data(links->name)->flag != -1)
			break ;
		links = links->next;
	}
	if (links != NULL && ft_strcmp(ft_find_start()->name, links->name))
		ft_find_data(links->name)->flag = -1;
	return (links);
}

t_way	*ft_find_solution(t_room *room)
{
	t_way	*solution;
	t_way	*head;

	solution = ft_find_short_way(room, ft_find_minus_one_link);
	head = solution;
	while (solution != NULL)
	{
		solution->next = ft_find_short_way(room, ft_find_minus_one_link);
		solution = solution->next;
	}
	ft_null();
	return (head);
}

void	ft_null(void)
{
	int			i;
	t_htable	*room;

	i = 0;
	while (i < HTSIZE)
	{
		room = g_htable[i];
		while (room != NULL)
		{
			room->rooms->flag = 0;
			room = room->next;
		}
		i++;
	}
}

t_way	*ft_bhandari(t_graph *g)
{
	t_way	*tmp;
	t_way	*ways;
	t_way	*way;
	t_way_node *part;

	ft_bellman_ford(g, ft_find_start());
	tmp = ft_find_short_way(ft_find_end(), ft_find_min_bfs_link);
	part = tmp->start_node;
	while (part->next)
	{
		ft_find_edge(part->name, part->next->name, -1);
		ft_find_edge(part->next->name, part->name, -2);
		part = part->next;
	}
	//free tmp
	way = ft_find_solution(ft_find_end());
	ways = way;
	while (way != NULL)
	{
		ft_bellman_ford(g, ft_find_start());
		tmp = ft_find_short_way(ft_find_end(), ft_find_min_bfs_link);
		if (tmp != NULL)
		{
			part = tmp->start_node;
			while (part->next)
			{
				ft_find_edge(part->name, part->next->name, -1);
				ft_find_edge(part->next->name, part->name, -2);
				part = part->next;
			}
			//free tmp
			way->next = ft_find_solution(ft_find_end());
		}
		way = way->next;
	}
	return (ways);
}
