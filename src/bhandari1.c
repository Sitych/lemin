/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bhandari.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:04:29 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/08/05 04:45:07 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_find_edge(t_room *from, t_room *to, int w)
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
		if (links->weight == -1 && links->flag != -1)
			break ;
		links = links->next;
	}
	if (links != NULL && ft_find_edge1(ft_find_end(), ft_find_data(links->name)))
		links->flag = -1;
	return (links);
}

t_way	*ft_find_solution(t_room *room)
{
	t_way	*solution;
	t_way	*head;
	t_edge	*link;

	solution = ft_find_short_way(room, ft_find_minus_one_link);
	head = solution;
	while (solution != NULL)
	{
		solution->next = ft_find_short_way(room, ft_find_minus_one_link);
		solution = solution->next;
	}
	link = ft_find_end()->links;
	while (link != NULL)
	{
		link->flag = 0;
		link = link->next;
	}
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

static t_way	*ft_bhandari(t_graph *g)
{
	t_way		*tmp;
	t_way_node	*part;
	t_way		*way;

	ft_bellman_ford(g, ft_find_start());
	tmp = ft_find_short_way(ft_find_end(), ft_find_min_bfs_link);
	way = NULL;
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
		way = ft_find_solution(ft_find_end());
	}
	return (way);
}

static int	ft_best_way(void)
{
	return (1);
}

t_way	*ft_solution(t_graph *g)
{
	t_way		*way1;
	t_way		*way2;

	way1 = ft_bhandari(g);
	while ((way2 = ft_bhandari(g)) != NULL)
	{
		if (ft_best_way())
			way1 = way2;
	}
	return (way1);
}

// t_way	*ft_solution(t_graph *g)
// {
// 	t_way		*way;
// 	t_sol		*sol;
// 	t_sol		*start;

// 	way = ft_bhandari(g);
// 	while ((way2 = ft_bhandari(g)) != NULL)
// 	{
// 		if (ft_best_way())
// 			way1 = way2;
// 	}
// 	return (way1);
// }
