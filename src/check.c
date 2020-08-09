/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:25:03 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/08/09 20:52:53 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_check_room(char **line, char **prev_lines, int i, t_graph **g)
{
	int		flag;
	t_room	*room;

	flag = -1;
	if (line[0] == NULL || line[1] == NULL || line[2] == NULL)
		ft_exit("ERROR: SPLIT ERROR");
	if ((ft_word_counter(line[0], ' ') == 3 || line[0][0] == '#')\
					&& line[0][0] != '\n' && line[0][0] == 'L')
		ft_exit("ERROR: SHITTY ROOM INPUT");
	while (prev_lines[i][0] == '#' && flag == -1)
	{
		flag = (ft_strstr(prev_lines[i], "##start")) ? 0 :
								ft_strstr(prev_lines[i], "##end") ? INT_MAX : -1;
		i--;
	}	
	room = ft_creat_room(line[0], ft_atoi(line[1]), ft_atoi(line[2]));
	if (flag == 0)
		(*g)->start = room;
	else if (flag == INT_MAX)
		(*g)->end = room;
	if (ft_find_data(room->name) != NULL)
		ft_exit("EROROR: SAME ROOM NAMES");
	ft_insert_room(room);		
}

static void		ft_check_coord(int i, int j)
{
	t_htable	*ptr;
	t_htable	*tmp;

	while (i++ < HTSIZE)
	{
		tmp = g_htable[i];
		while (tmp)
		{
			j = 0;
			while (j++ < HTSIZE)
			{
				ptr = g_htable[j];
				while (ptr)
				{
					if ((ptr->rooms->x == tmp->rooms->x) && (ptr->rooms->y == tmp->rooms->y) && ptr != tmp)
						ft_exit("ERROR: SAME ROOM COORDINATES");
					ptr = ptr->next;
				}
			}
			tmp = tmp->next;
		}
	}
}

void		ft_del_mas(char ***mas, int len)
{
	int i;
	// len++;
	// (void)mas;
	i = 0;
	if (mas == NULL)
		return ;
	while (i < len)
	{
		if ((*mas)[i] != NULL)
			free((*mas)[i]);
		i++;
	}
	free(*mas);
	*mas = NULL;
}

t_graph		*ft_file_checker(char **lines, int all, t_graph *g)
{
	int		i;
	char	***links;

	if (!ft_strcmp(lines[all - 1], "\n"))
		ft_exit("ERROR: BAD INPUT");
	for (int j = 0; j < HTSIZE; j++)
		g_htable[j] = NULL;
	g->ants = ft_val_ant(lines[0]);
	i = ft_val_room(lines, &g, 1);
	ft_check_coord(0, 0);
	ft_val_bond(lines, g);
	links = ft_val_links(lines, i, all, &g);
	g->edges = (t_all_edges*)malloc((sizeof(t_all_edges)) * g->E);
	ft_set_links(links, i, all, &g);
	ft_printf("%d\n", g->E);
	if (g->E / 2 < 1)
		ft_exit("ERROR: LINKS < 1");
	return (g);
}
