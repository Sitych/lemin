/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:54:04 by erodd             #+#    #+#             */
/*   Updated: 2020/03/26 21:26:40 by rretta           ###   ########.fr       */
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

	
	split = NULL;
	split = ft_file_parse(split);
	all = 0;
	while (split[all])
		all++;
	ft_putstr("split\n");
	int q = ft_file_checker(split, all);
	q = 1 + q -1;
	ft_init_bfs_level();
	ft_thprint();
	ft_putchar('\n');
	// ft_print(ft_find_data("1"));
	// ft_del_useless_links("1");
	// ft_print(ft_find_data("1"));
	ft_putstr("check\n");
	t_room *ptr = ft_find_start();
	ft_manage_way(ptr->name);
	ft_thprint();
	// ft_output_fork(ft_find_end()->name);
	// ft_manage_way(ptr->name); //x2 da pohui che b i ne vizvat'
	// ft_path_forming(q);
	// ft_del_htable();
	exit (0);
}
