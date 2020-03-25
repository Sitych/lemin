/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:54:04 by erodd             #+#    #+#             */
/*   Updated: 2020/03/26 00:47:02 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lem_in.h"

static void		ft_init_bfs_level(void)
{
	t_room	*room;
	t_queue	*ptr;
	t_queue	*elem;
	int		i;

	ptr = ft_creat_elem(ft_find_start()->name);
	while (ft_isempty(ptr))
	{
		elem = ft_pop(&ptr);
		room = ft_find_data(elem->name);
		i = 0;
		while (i < room->num_links)
		{
			if (ft_find_data(room->links[i])->bfs_level != INT_MAX &&\
				ft_find_data(room->links[i])->bfs_level == -1)
			{
				ft_find_data(room->links[i])->bfs_level = room->bfs_level + 1;
				ptr = ft_push(ptr, room->links[i]);
			}
			i++;
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
	t_room *ptr = ft_find_start();
	ft_putstr("check\n");
	ft_init_bfs_level();
	ft_manage_way(ptr->name);
	ft_path_forming(q);
	ft_del_htable();
	exit (0);
}
