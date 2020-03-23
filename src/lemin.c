/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:54:04 by erodd             #+#    #+#             */
/*   Updated: 2020/03/21 21:43:59 by rretta           ###   ########.fr       */
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
	// t_htable *ptr = ft_find_data("end");
	// ft_print(ptr->rooms);
		// int i = 0;
		// ptr->rooms->links[5] = NULL;
		// while (ptr->rooms->links[i])
		// {
		// 	ft_printf("%s\n", ptr->rooms->links[i++]);
		// }
	// ft_del_htable();
	ft_putstr("check\n");
	// ft_init_bfs_level();
	//ft_putnbr(ft_find_data("start")->rooms->bfs_level);
	ft_bfs_level(q);
	ft_print_bfs();
	exit (0);
}
