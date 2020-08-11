/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:16:55 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/08/10 16:45:52 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_val_ant(char *line)
{
	int	ant_num;
	int	i;

	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	if (line[i])
		ft_exit("ERROR: INCORRECT INPUT OF ANTS\n");
	ant_num = ft_atoi(line);
	if (ant_num < 1 || ant_num > INT32_MAX)
		ft_exit("ERROR: INCORRECT QUANTITY OF ANTS\n");
	return (ant_num);
}

int		ft_val_bond(char **lines, t_graph *g)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (*lines != 0)
	{
		if (ft_strstr(*lines, "##start\0") != 0)
			start++;
		if (ft_strstr(*lines, "##end\0") != 0)
			end++;
		lines++;
	}
	if (g->start == NULL || g->end == NULL)
		ft_exit("ERROR: NO END OR START ROOM");
	if (start != 1 || end != 1)
		ft_exit("ERROR: THERE SHOULD BE ONLY ONE ENTERANCE AND EXIT");
	return (EXIT_SUCCESS);
}

int		ft_val_room(char **lines, t_graph **g, int i)
{
	char		**split;

	while (lines[i])
	{
		if (ft_word_counter(lines[i], '-') == 2 && lines[i][0] != '#')
			break ;
		if (lines[i][0] == '#')
		{
			i++;
			continue ;
		}
		if ((split = ft_strsplit(lines[i], ' ')) == NULL)
			ft_exit("ERROR: SPLIT ERROR");
		if (split[3])
			ft_exit("ERROR: NOT VALID INPUT");
		ft_val_coords(split[1], split[2]);
		ft_check_room(split, lines[i - 1], g);
		(*g)->V++;
		ft_del_mas(&split, 3);
		i++;
	}
	if ((*g)->V < 2)
		ft_exit("ERROR: ROOM < 2");
	return (i);
}

int		ft_val_coords(char *x, char *y)
{
	int i;

	i = 0;
	if (x == NULL)
		ft_exit("ERROR: NO FIRST COORD");
	while (x[i])
		if (!ft_isdigit(x[i++]))
			ft_exit("ERROR: NO DIGIT COORD");
	if (y == NULL)
		ft_exit("ERROR: NO FIRST COORD");
	i = 0;
	while (y[i])
		if (!ft_isdigit(y[i++]))
			ft_exit("ERROR: NO DIGIT COORD");
	return (0);
}
