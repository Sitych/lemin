/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:27:41 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/03/14 22:46:19 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_r_list	*ft_crtrm(char *str, int flag)
{
	t_r_list	*tmp;
	char		**lines;
	int			i;

	tmp = NULL;
	lines = ft_strsplit(str, ' ');
	if ((tmp = (t_r_list*)malloc(sizeof(t_r_list))) == NULL)
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
	tmp->next = NULL;
	return (tmp);
}

t_r_list	*ft_add_push_back(t_r_list *tmp, char **split, int i)
{
	int flag;

	if (ft_strstr(split[i], "##") != 0)
		return (tmp);
	flag = -1;
	if (i > 0 && ft_strstr(split[i - 1], "##start"))
		flag = 0;
	else if (i > 0 && ft_strstr(split[i - 1], "##end"))
		flag = 1;
	tmp->next = ft_crtrm(split[i], flag);
	tmp = tmp->next;
	return (tmp);
}

t_r_list	*ft_roomdel(t_r_list **ptr)
{
	t_r_list *tmp;

	tmp = (*ptr)->next;
	free((*ptr)->name);
	free(*ptr);
	return (tmp);
}

void		ft_check_name_coord(t_r_list *ptr)
{
	t_r_list	*tmp;

	while (ptr != NULL)
	{
		tmp = ptr->next;
		while (tmp != NULL)
		{
			if (ft_strstr(ptr->name, tmp->name) || (ptr->x == tmp->x && ptr->y == tmp->y))
				ft_exit("EROROR: SAME ROOM NAMES OR SAME ROOM COORDS");
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
}

void		ft_print(t_r_list *tmp)
{
	while (tmp != NULL)
	{
		ft_printf("name = %s x = %d y = %d flag = %d\n", tmp->name, tmp->x, tmp->y, tmp->flag);
		tmp = tmp->next;
	}
}