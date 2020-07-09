/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:17:14 by rretta            #+#    #+#             */
/*   Updated: 2020/03/26 00:45:38 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"



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
