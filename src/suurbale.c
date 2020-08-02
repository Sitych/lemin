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

// void	ft_suurbale(t_graph *g)
// {
// 	t_way		*ways1;
// 	t_way		*ways2;
// 	t_way_node	*part;
// 	t_way		*buf;

// 	ways1 = NULL;
// 	ft_bellman_ford(g, ft_find_start());
// 	ways1 = ft_find_short_way(ft_find_end());
// 	part = ways1->start_node;
// 	while (part->next)
// 	{
// 		ft_find_edge(part->name, part->next->name, -1);
// 		ft_find_edge(part->next->name, part->name, -2);
// 		part = part->next;
// 	}
// 	ways1->next = NULL;
// 	// start = way;
// 	int i = 0;
// 	while (i++ < 2)
// 	{
// 		ft_bellman_ford(g, ft_find_start());
// 		buf = ft_find_short_way(ft_find_end());
// 		part = buf->start_node;
// 		while (part->next)
// 		{
// 			ft_find_edge(part->name, part->next->name, -1);
// 			ft_find_edge(part->next->name, part->name, -2);
// 			part = part->next;
// 		}
// 		ways2 = ft_find_all_short_ways(ft_find_end());
// 		// cmp ways1 and ways2
// 	}
// }