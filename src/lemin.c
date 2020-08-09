/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:54:04 by erodd             #+#    #+#             */
/*   Updated: 2020/08/09 20:59:29 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lem_in.h"

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
	// int c = 0;

	split = NULL;
	//start not followed by room
	g = (t_graph*)ft_memalloc(sizeof(t_graph));
	g->V = 0;
	g->E = 0;
	split = ft_file_parse(split);
	all = 0;
	while (split[all])
		all++;
	g = ft_file_checker(split, all, g);
	ft_printf("%s %s\n", g->end->name, g->start->name);
	ft_del_mas(&split, all);
	ft_manage_way(g, g->start);
	t_way	*tmp;
	ways = ft_solution(g);
	ft_printf("BEST WAY IS:\n");
	t_way 	*pr;
	ft_printf("Steps - %d\n", ft_step_counter(ways, g));
	pr = ways;
	while (pr)
	{
		ft_print_way(pr);
		pr =  pr->next;
	}
	ft_step_printer(ways, g);
	while (ways)
	{
		tmp = ways->next;
		ft_del_way_return_null(&ways);
		ways = tmp;
	}
	free(g->edges);
	ft_del_htable();
	free(g);
	return (0);
}
