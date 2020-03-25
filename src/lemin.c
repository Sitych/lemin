/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:54:04 by erodd             #+#    #+#             */
/*   Updated: 2020/03/25 22:05:15 by rretta           ###   ########.fr       */
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
	// t_room	*room;
	// int		i;

	// lem->rooms = &room;
	
	split = NULL;
	// room = NULL;
	// g_nbr = 0;
	split = ft_file_parse(split);
	all = 0;
	while (split[all])
		all++;
	ft_putstr("split\n");
	// i = 0;
	// while (split[i] != 0)
	// {
	// 	ft_putstr(split[i]);
	// 	ft_putchar('\n');
	// 	i++;
	// }
	int q = ft_file_checker(split, all);
	// ft_printf("start link = ");
	// ft_putnbr(ft_find_data("start")->rooms->num_links);
	// ft_putchar('\n');
	// ft_thprint();
	t_room *ptr = ft_find_start();
	ft_putstr("check\n");
	//ft_putnbr(ft_find_data("start")->rooms->bfs_level);
	// ft_bfs_level(q);
	q++;
	// ft_print(ft_find_data("start"));
	// ft_thprint();
	// ft_thprint();
	// ft_print(ft_find_data("start"));
	// ft_del_useless_links("3");
	ft_init_bfs_level();
	ft_manage_way(ptr->name);
	ft_del_htable();
	// ft_print_bfs();
	exit (0);
}
