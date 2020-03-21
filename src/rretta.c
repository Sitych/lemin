/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rretta.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:17:14 by rretta            #+#    #+#             */
/*   Updated: 2020/03/21 21:40:39 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_val_links2(char **split, int j, int i, char **links)
{
	while (j <= i)
	{
		if (split[j][0] == '#')
		{
			j++;
			continue ;
		}
		if ((ft_find_data(links[0]) == NULL) || (ft_find_data(links[1]) == NULL))
			ft_exit("ERROR: NO SUCH ROOM NAME IN THE LINK INPUT");
		if (ft_strcmp(links[0], links[1]) == 0)
			ft_exit("ERROR: LINK IS LINKED TO ITSELF");
		if (j != i)
			if (ft_strcmp(split[j], split[i]) == 0)
				ft_exit("ERROR: LINK IS REPEATED");
		if (j == i)
		{
			ft_find_data(links[0])->rooms->num_links++;
			ft_find_data(links[1])->rooms->num_links++;
		}
		j++;
	}
	return (0);
}

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

	ft_putchar('q');
	ft_putnbr(q);
	i = 0;
	while (i <= q)
	{
		// ft_printf("i = %d\n", i);
		j = 0;
		while (j < HTSIZE)
		{
			// ft_printf("j = %d\n", j);
			k = 0;
			if (g_htable[j] != NULL && g_htable[j]->rooms->bfs_level == i)
			{
				while (g_htable[j]->rooms->links[k] != NULL)
				{
					// ft_printf("k = %d\n", k);
					if (ft_find_data(g_htable[j]->rooms->links[k])->rooms->bfs_level == -1)
						ft_find_data(g_htable[j]->rooms->links[k])->rooms->bfs_level = i + 1;
					k++;
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



