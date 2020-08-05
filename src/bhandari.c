/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bhandari.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:04:29 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/08/05 06:21:45 by rretta           ###   ########.fr       */
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

// static int	ft_best_way(void)
// {
// 	return (1);
// }

t_sol	*ft_solution(t_graph *g)
{
	t_way		*way1;
	t_sol		*sol;
	t_sol		*head;

	way1 = ft_bhandari(g);
	sol = ft_creat_sol(way1);
	head = sol;
	while ((way1 = ft_bhandari(g)) != NULL)
	{
		sol->next = ft_creat_sol(way1);
		sol = sol->next;
	}
	return (head);
}
