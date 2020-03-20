/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:27:41 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/03/20 21:59:44 by rretta           ###   ########.fr       */
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
	tmp->num_links = 0;
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

void		ft_print(t_room *tmp)
{
	ft_printf("name = %s x = %d y = %d flag = %d\n", tmp->name, tmp->x, tmp->y, tmp->flag);
}