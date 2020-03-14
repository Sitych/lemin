/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:54:04 by erodd             #+#    #+#             */
/*   Updated: 2020/03/14 22:47:15 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lem_in.h"

void		ft_exit(char *str)
{
	perror(str);
	exit (EXIT_FAILURE);
}

void		ft_arrclr(char **arr)
{
	char **tmp;

	if (!arr)
		return ;
	tmp = arr;
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free(tmp);
}

int		main(void)
{
	// t_lemin *lem;
	// t_room	room;
	char		**split;
	t_r_list	*room;
	// int		i;

	// lem->rooms = &room;
	
	split = NULL;
	room = NULL;
	split = ft_file_parse(split);
	ft_putstr("split\n");
	// i = 0;
	// while (split[i] != 0)
	// {
	// 	ft_putstr(split[i]);
	// 	ft_putchar('\n');
	// 	i++;
	// }

	ft_file_checker(split, &room);
	t_r_list *ptr;
	size_t	i;

	i = 0;
	ptr = room;
	g_hash_table = (t_hash_table**)malloc(sizeof(t_hash_table*) * (g_hash_table_size + 1));
	ft_printf("111\n");
	while (i < g_hash_table_size)
	{
		g_hash_table[i] = (t_hash_table*)malloc(sizeof(t_hash_table));
		g_hash_table[i]->rooms = ft_crtrm();
		ft_bzero((void*)g_hash_table[i]->rooms, sizeof(g_hash_table[i]->rooms));
		i++;
	}
	ft_printf("111111111\n");
	while (ptr)
	{
		ft_printf("name = %s x = %d y = %d flag = %d\n", ptr->name, ptr->x, ptr->y, ptr->flag);
		g_hash_table[ft_hash(ptr->name)] = ft_insert_data(ptr);
		ptr = ptr->next;
	}
	// ft_print(room);
	ft_putstr("check\n");
	//CRT DBLLNKD LST RM
	// t_dbl_room *rm = create_dbl_room(split[i]);
	//ft_putstr(split[0]);
	// lem_init(&lem);
	// ants_parse(&lem);
	ft_arrclr(split);
	//perror("TUPO GAME OVER");
	exit (0);
}

int		lem_init(t_lemin *lem)
{
	lem->ants = 0;
	lem->start = 0;
	lem->end = 0;
	lem->pipes = NULL;
	lem->rooms = NULL;

	return (EXIT_SUCCESS);
}

// t_dbl_room *create_dbl_room(char *str)
// {
// 	str = 0;
	
// 	t_dbl_room *tmp = (t_dbl_room *)malloc(sizeof(t_dbl_room));
// 	tmp->size = 0;
// 	tmp->head = NULL;
// 	tmp->head = NULL;

// 	return (tmp);
// }