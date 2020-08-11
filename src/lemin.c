/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:54:04 by erodd             #+#    #+#             */
/*   Updated: 2020/08/10 23:59:32 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lem_in.h"

int			ft_manage_way(t_graph *g, t_room *room)
{
	t_edge	*start;
	int		count;

	if (!ft_strcmp(g->end->name, room->name))
		return (0);
	start = room->links;
	count = 0;
	while (start != NULL)
	{
		if (ft_find_data(start->name)->bfs_level > room->bfs_level)
		{
			if (ft_manage_way(g, ft_find_data(start->name)) == 1)
			{
				--count;
			}
		}
		start = start->next;
		++count;
	}
	if (count == 1 && ft_strcmp(room->name, g->start->name))
		room->bfs_level = -1;
	return (count);
}

void		ft_exit(char *str)
{
	perror(str);
	exit (EXIT_FAILURE);
}

int		main(void)
{
	char		**split;
	int			all;
	t_graph		*g;
	t_way		*ways;

	split = NULL;
	//LEAK!!!!!!!!!!!!!!!!!!!!!!!!!!!! test_1000; maybe del hash table
	g = (t_graph*)ft_memalloc(sizeof(t_graph));
	g->V = 0;
	g->E = 0;
	split = ft_file_parse(split);
	all = 0;
	while (split[all])
		all++;
	g = ft_file_checker(split, all, g);
	ft_manage_way(g, g->start);
	ft_del_mas(&split, all);
	// ft_bellman_ford(g, g->start);
	// ft_thprint();
	ways = ft_solution(g);
	ft_printf("lol");
	ft_step_printer(ways, g);
	ft_del_way_return_null(&ways);
	free(g->edges);
	ft_del_htable();
	free(g);
	return (0);
}
