/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:27:41 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/03/16 21:39:39 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*ft_crtrm(char *str, int flag)
{
	t_room		*tmp;
	char		**lines;
	int			i;

	tmp = NULL;
	if ((lines = ft_strsplit(str, ' ')) == NULL)
		ft_exit("ERROR: SPLIT ERROR");
	if ((tmp = (t_room*)malloc(sizeof(t_room))) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	if ((tmp->name = ft_strdup(lines[0])) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	i = -1;
	while (lines[1][i++])
		if ((lines[1][i] < '0' || lines[1][i] > '9') && lines[1][i])
			ft_exit("ERROR: NO DIGIT COORD");
	tmp->x = ft_atoi(lines[1]);
	i = -1;
	while (lines[2][i++])
		if ((lines[2][i] < '0' || lines[2][i] > '9') && lines[2][i])
			ft_exit("ERROR: NO DIGIT COORD");
	tmp->y = ft_atoi(lines[2]);
	ft_free((void**)lines, 3);
	tmp->flag = flag;
	tmp->links = NULL;
	return (tmp);
}

void		ft_del_room(t_room **ptr)
{
	size_t		i;
	t_room	*room;

	i = 0;
	room = *ptr;
	if (room != NULL)
	{
		ft_strdel(&(room->name));
		if (room->links)
		{
			while (room->links[i])
			{
				ft_strdel(&(room->links[i]));
				i++;
			}
			free(room->links);
		}
	}
}

// t_room	*ft_add_push_back(t_room **data ,t_room *data)
// {
// 	int flag;

// 	if (ft_strstr(split[i], "##") != 0)
// 		return (tmp);
// 	flag = -1;
// 	if (i > 0 && ft_strstr(split[i - 1], "##start"))
// 		flag = 0;
// 	else if (i > 0 && ft_strstr(split[i - 1], "##end"))
// 		flag = 1;
// 	tmp->next = ft_crtrm(split[i], flag);
// 	tmp = tmp->next;
// 	return (tmp);
// }

// t_room	*ft_roomdel(t_room **ptr)
// {
// 	t_room *tmp;

// 	tmp = (*ptr)->next;
// 	free((*ptr)->name);
// 	free(*ptr);
// 	return (tmp);
// }

// void		ft_check_name_coord(t_room *ptr)
// {
// 	t_room	*tmp;

// 	while (ptr != NULL)
// 	{
// 		tmp = ptr->next;
// 		while (tmp != NULL)
// 		{
// 			if (ft_strstr(ptr->name, tmp->name) || (ptr->x == tmp->x && ptr->y == tmp->y))
// 				ft_exit("EROROR: SAME ROOM NAMES OR SAME ROOM COORDS");
// 			tmp = tmp->next;
// 		}
// 		ptr = ptr->next;
// 	}
// }

void		ft_print(t_room *tmp)
{
	ft_printf("name = %s x = %d y = %d flag = %d\n", tmp->name, tmp->x, tmp->y, tmp->flag);
}