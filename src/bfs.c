/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:17:14 by rretta            #+#    #+#             */
/*   Updated: 2020/08/08 18:59:37 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"



void		ft_print_bfs(void)
{
	t_htable	*tmp;
	int 		i;

	i = 0;
	while (i < HTSIZE)
	{
		tmp = g_htable[i];
		while (tmp)
		{
			ft_printf("BF LEVEL = %d, ROOM = %s flag = %d\n", tmp->rooms->bf , tmp->rooms->name, tmp->rooms->flag);
			tmp = tmp->next;
		}
		i++;
	}
}
