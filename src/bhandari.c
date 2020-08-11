/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bhandari.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:04:29 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/08/11 00:19:43 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_edge		*ft_find_edge(t_room *from, t_room *to)
{
	t_edge	*link;

	link = from->links;
	while (ft_strcmp(to->name, link->name))
	{
		link = link->next;
		if (link == NULL)
			return (link);
	}
	return (link);
}


t_edge	*ft_find_minus_one_link(t_edge *links)
{
	while (links != NULL)
	{
		if (links->weight == -1 && links->flag != -1)
			break ;
		links = links->next;
	}
	if (links != NULL)
		links->flag = -1;
	return (links);
}

void	ft_null(t_graph *g)
{
	int	i;

	i = 0;
	while (i < g->E)
		*(g->edges[i++].f)= 0;
}

t_way	*ft_bhandari(t_graph *g)
{
	t_way		*tmp;
	t_way_node	*part;

	ft_bellman_ford(g, g->start);
	tmp = ft_find_way(g, g->end, ft_find_min_bfs_link);
	if (tmp != NULL)
	{
		part = tmp->start_node;
		while (part->next)
		{
			// if (ft_find_edge(part->name, part->next->name)->weight != -1)
			ft_find_edge(part->name, part->next->name)->weight = -2;
			if (ft_find_edge(part->next->name, part->name)->weight != -2)
				ft_find_edge(part->next->name, part->name)->weight = -1;
			part = part->next;
		}
		ft_del_way_return_null(&tmp);
		tmp = ft_find_solution(g->end, g);
	}
	return (tmp);
}
