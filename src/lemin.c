/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:54:04 by erodd             #+#    #+#             */
/*   Updated: 2020/03/16 22:46:45 by qjosmyn          ###   ########.fr       */
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
	// t_room	*room;
	// int		i;

	// lem->rooms = &room;
	
	split = NULL;
	// room = NULL;
	// g_nbr = 0;
	split = ft_file_parse(split);
	ft_putstr("split\n");
	// i = 0;
	// while (split[i] != 0)
	// {
	// 	ft_putstr(split[i]);
	// 	ft_putchar('\n');
	// 	i++;
	// }
	ft_file_checker(split);
	// ft_del_htable();
	// ft_thprint();
	// while (g_htable[62322])
	// {
	// 	ft_printf("%s\n", g_htable[62322]->rooms->name);
	// 	g_htable[62322] = g_htable[62322]->next;
	// }
	// ft_print(room);
	ft_putstr("check\n");
	//CRT DBLLNKD LST RM
	// t_dbl_room *rm = create_dbl_room(split[i]);
	//ft_putstr(split[0]);
	// lem_init(&lem);
	// ants_parse(&lem);
	//perror("TUPO GAME OVER");
	exit (0);
}
