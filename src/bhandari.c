/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bhandari.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:04:29 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/08/09 20:53:45 by rretta           ###   ########.fr       */
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

t_way	*ft_find_solution(t_room *room, t_graph *g)
{
	t_way	*solution;
	t_way	*head;

	solution = ft_find_short_way(g, room, ft_find_minus_one_link);
	head = solution;
	while (solution != NULL)
	{
		solution->next = ft_find_short_way(g ,room, ft_find_minus_one_link);
		solution = solution->next;
	}
	ft_null(g);
	return (head);
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
	tmp = ft_find_short_way(g, g->end, ft_find_min_bfs_link);
	if (tmp != NULL)
	{
		part = tmp->start_node;
		while (part->next)
		{
			ft_find_edge(part->name, part->next->name)->weight = -2;
			ft_find_edge(part->next->name, part->name)->weight = -1;
			part = part->next;
		}
		ft_del_way_return_null(&tmp);
		tmp = ft_find_solution(g->end, g);
	}
	return (tmp);
}

static int	ft_best_way(t_way *way1, t_way *way2, t_graph *g)
{
	int		way1_steps;
	int		way2_steps;

	way1_steps = ft_step_counter(way1, g);
	way2_steps = ft_step_counter(way2, g);
	t_way 	*pr;
	ft_printf("Way1: steps - %d\n", way1_steps);
	pr = way1;
	while (pr)
	{
		ft_print_way(pr);
		pr =  pr->next;
	}
	ft_printf("Way2: steps - %d\n", way2_steps);
	pr = way2;
	while (pr)
	{
		ft_print_way(pr);
		pr =  pr->next;
	}
	if (way1_steps <= way2_steps)
		return (1);
	return (0);
}

// static t_sol	*ft_creat_sol(t_way *way)
// {
// 	t_sol	*sol;

// 	if ((sol = (t_sol*)ft_memalloc(sizeof(t_way))) == NULL)
// 		ft_exit("ERROR: MALLOC ERROR");
// 	sol->way = way;
// 	sol->next = NULL;
// 	return (sol);
// }

// t_sol	*ft_solution(t_graph *g)
// {
// 	t_way		*way1;
// 	t_sol		*sol;
// 	t_sol		*head;

// 	way1 = ft_bhandari(g);
// 	sol = ft_creat_sol(way1);
// 	head = sol;
// 	while ((way1 = ft_bhandari(g)) != NULL)
// 	{
// 		sol->next = ft_creat_sol(way1);
// 		sol = sol->next;
// 	}
// 	return (head);
// }

t_way		*ft_solution(t_graph *g)
{
	t_way	*way1;
	t_way	*way2;
	t_way	*tmp;

	way1 = ft_bhandari(g);
	ft_print_way(way1);
	while ((way2 = ft_bhandari(g)) != NULL)
	{
		ft_sort_solution(way2);
		if (ft_best_way(way1, way2, g) == 1)
		{
			while (way2)
			{
				tmp = way2->next;
				ft_del_way_return_null(&way2);
				way2 = tmp;
			}
		}
		else
		{
			while (way1)
			{
				tmp = way1->next;
				ft_del_way_return_null(&way1);
				way1 = tmp;
			}
			way1 = way2;
		}
	}
	return (way1);
}