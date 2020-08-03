﻿/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:54:04 by erodd             #+#    #+#             */
/*   Updated: 2020/07/31 23:20:45 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lem_in.h"


static void		ft_init_bfs_level(void)
{
	t_room	*room;
	t_queue	*ptr;
	t_queue	*elem;
	t_edge	*edge;

	ptr = ft_creat_elem(ft_find_start()->name);
	while (ft_isempty(ptr))
	{
		elem = ft_pop(&ptr);
		room = ft_find_data(elem->name);
		edge = room->links;
		while (edge != NULL)
		{
			if (ft_find_data(edge->name)->bfs_level != INT_MAX &&
				ft_find_data(edge->name)->bfs_level == -1)
			{
				ft_find_data(edge->name)->bfs_level = room->bfs_level + 1;
				ptr = ft_push(ptr, edge->name);
			}
			edge = edge->next;
		}
		ft_del_elem(&elem);
	}
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
	t_way		*ways = NULL;
	// int c = 0;

	split = NULL;
	g = (t_graph*)malloc(sizeof(t_graph));
	split = ft_file_parse(split);
	all = 0;
	while (split[all])
		all++;
	g = ft_file_checker(split, all, g);
	// ft_thprint();
	ft_init_bfs_level();
	t_room *ptr = ft_find_start();
	ft_manage_way(ptr);
	ways = ft_bhandari(g);
	while (ways)
	{
		ft_print_way(ways);
		ways = ways->next;
	}
	exit (0);
}
