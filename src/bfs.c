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

// void		ft_init_bfs_level(void)
// {
// 	int i;

// 	i = 0;
// 	while (i < HTSIZE)
// 	{
// 		if (g_htable[i] != NULL)
// 		{
// 			if (g_htable[i]->rooms->flag == 0)
// 				g_htable[i]->rooms->bfs_level = 0;
// 			else if (g_htable[i]->rooms->flag == 1)
// 				g_htable[i]->rooms->bfs_level = INT_MAX;
// 			else
// 				g_htable[i]->rooms->bfs_level = -1;
// 		}
// 		i++;
// 	}
// }

void		ft_bfs_level(int q)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i <= q)
	{
		// ft_printf("i = %d\n", i);
		j = 0;
		while (j < HTSIZE)
		{
			// ft_printf("j = %d\n", j);
			k = 0;
			if (g_htable[j] != NULL)
			{
				if (g_htable[j]->rooms->bfs_level == i)
				{
					while (g_htable[j]->rooms->links[k] != NULL)
					{
						// ft_printf("k = %d\n", k);
						if (ft_find_data(g_htable[j]->rooms->links[k])->bfs_level == -1)
							ft_find_data(g_htable[j]->rooms->links[k])->bfs_level = i + 1;
						k++;
					}
				}
			}
			j++;
		}
		i++;
	}
}

void		ft_print_bfs(void)
{
				// if (g_htable[j] != NULL)
				// ft_printf("BFS LEVEL = %d, ROOM = %s\n", i , g_htable[j]->rooms->name);
	int i;
	i = 0;

	while (i < HTSIZE)
	{
		if (g_htable[i] != NULL)
			ft_printf("BFS LEVEL = %d, ROOM = %s\n", g_htable[i]->rooms->bfs_level , g_htable[i]->rooms->name);
		i++;
	}
}



