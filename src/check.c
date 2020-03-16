/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:25:03 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/03/16 22:52:42 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_file_checker(char **split)
{
	ft_create_htable(HTSIZE);
	ft_val_ant(split[0]);
	ft_putstr("start\n");
	ft_val_bond(split);
	ft_putstr("bond\n");
	ft_val_room(split);
	ft_putstr("val_room\n");
	return(0);
}

int		ft_val_ant(char *split)
{
	int	ant_num;
	int	i;

	i = 0;
	while (ft_isdigit(split[i]))
		i++;
	if (split[i])
		ft_exit("ERROR: INCORRECT INPUT OF ANTS\n");
	ant_num = ft_atoi(split);
	if (ant_num < 1 || ant_num > INT32_MAX)
		ft_exit("ERROR: INCORRECT QUANTITY OF ANTS\n");
	ft_putnbr(ant_num);
	ft_putchar('\n');
	return (1);
}

int		ft_val_bond(char **split)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (*split != 0)
	{
		if (ft_strstr(*split, "##start\0") != 0)
			start++;
		if (ft_strstr(*split, "##end\0") != 0)
			end++;
		split++;
	}
	if (start != 1 && end != 1)
		ft_exit("ERROR: THERE SHOULD BE ONLY ONE ENTERANCE AND EXIT");
	return (EXIT_SUCCESS);
}

int		ft_check_room(char **split, int i)
{
	int flag;

	if ((ft_word_counter(split[i], ' ') == 3 || split[i][0] == '#')\
					&& split[i][0] != '\n' && split[i][0] == 'L')
		ft_exit("ERROR: SHITTY ROOM INPUT");
	flag = (ft_strstr(split[i - 1], "##start")) ? 0 :\
						ft_strstr(split[i - 1], "##end") ? 1 : -1;
	if (ft_strstr(split[i], "#") && flag == -1)
		return (-2);
	return (flag);
}

int		ft_val_room(char **split)
{
	int			i;
	int			room_num;
	int			flag;
	t_r_list	*room;
	t_htable	*ptr;

	i = 1;
	room_num = 0;
	ft_putstr("init\n");
	while ((ft_word_counter(split[i], ' ') != 1 && ft_word_counter(split[i], '-') != 2) || split[i][0] == '#') 
	{
		if ((flag = ft_check_room(split, i)) == - 2)
		{
			i++;
			continue ;
		}
		room_num++;
		ft_printf("%d\n", i);
		room = ft_crtrm(split[i], flag);
		if ((ptr = ft_find_data(room->name))->rooms != NULL)
			ft_exit("EROROR: SAME ROOM NAMES");
		ft_printf("%d\n", ft_hash(room->name));
		ft_insert_room(room);
		i++;
	}
	ft_val_links(split, i); //TO MOVE TO FT_FILE_CHECKER FUNC (MAYBE)
	return (room_num);
}

int		ft_val_links(char **links, int i)
{
	int	links_num;
	char **split;

	links_num = 0;
	split = NULL;
	while (links[i])
	{
		if (ft_word_counter(links[i], ' ') == 1 && ft_word_counter(links[i], '-') == 2 && links[i][0] != '#')
		{
			// link is ok
			if ((split = ft_strsplit(links[i], '-')) == NULL)
				ft_exit("ERROR: SPLIT ERROR");
			// g_htable[ft_hash(split[0])]->rooms;
			links_num++;
			i++;
		}
		else
			ft_exit("ERROR: SHITTY LINK INPUT");
	}
	ft_putnbr(links_num);
	ft_putchar('\n');
	return (0);
}