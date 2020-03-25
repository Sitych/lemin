/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rretta.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:17:14 by rretta            #+#    #+#             */
/*   Updated: 2020/03/23 14:26:13 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_init_bfs_level(void)
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

void		ft_print_bfs(void)
{
	int i;
	i = 0;

	while (i < HTSIZE)
	{
		if (g_htable[i] != NULL)
			ft_printf("BFS LEVEL = %d, ROOM = %s\n", g_htable[i]->rooms->bfs_level , g_htable[i]->rooms->name);
		i++;
	}
}



