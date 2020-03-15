/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:25:03 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/03/16 00:26:04 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_file_checker(char **split, t_r_list **start)
{
	ft_create_htable(HTSIZE);
	ft_val_ant(split[0]);
	ft_putstr("start\n");
	ft_val_bond(split);
	ft_putstr("bond\n");
	ft_val_room(split, start);
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

/*
**	проверка на то, что ## внутри строки
*/

int		ft_check(char **split, size_t i)
{
	int flag;

	if ((ft_word_counter(split[i], ' ') == 3 || split[i][0] == '#')\
					&& split[i][0] != '\n' && split[i][0] == 'L')
		ft_exit("ERROR: SHITTY ROOM INPUT");
	flag = (ft_strstr(split[i - 1], "##start")) ? 0 :\
						ft_strstr(split[i - 1], "##end") ? 1 : -1;
	if (ft_strstr(split[i], "##") && flag == -1)
		return (-2);
	return (flag);
}

int		ft_val_room(char **split, t_r_list **start)
{
	size_t		i;
	int			room_num;
	int			flag;
	t_r_list	*room;

	i = 1;
	room_num = 0;
	start = NULL;
	ft_putstr("init\n");
	while ((ft_word_counter(split[i], ' ') != 1 && ft_word_counter(split[i], '-') != 2) || split[i][0] == '#') 
	{
		if ((flag = ft_check(split, i)) == - 2)
		{
			i++;
			continue ;
		}
		room = ft_crtrm(split[i], flag);
		if (g_htable[ft_hash(room->name)]->rooms != NULL\
			&& !ft_strcmp(room->name, g_htable[ft_hash(room->name)]->rooms->name))
				ft_exit("EROROR: SAME ROOM NAMES");
		if (g_htable[ft_hash(room->name)]->rooms != NULL)
			ft_printf("%d\n", ft_hash(room->name));
		ft_insert_data(room);
		i++;
	}
		// if ((ft_word_counter(split[i], ' ') == 3 || split[i][0] == '#') && split[i][0] != '\n')
		// {
		// 	if (split[i][0] == 'L')
		// 		ft_exit("ERROR: SHITTY ROOM INPUT");
		// 	else if (split[i][0] == '#')
		// 		i++;
		// 	else
		// 	{
		// 		// room is ok
		// 		i++;
		// 		room_num++;
		// 	}
		// }
		// else 
		// 	ft_exit("ERROR: SHITTY ROOM INPUT");
	// }
	// *start = ft_roomdel(start);
	// // work
	// ft_check_name_coord(*start);
	// ft_set_htable(split, i);
	ft_putnbr(room_num);
	ft_putchar('\n');
	ft_val_links(split, i); //TO MOVE TO FT_FILE_CHECKER FUNC (MAYBE)
	return (room_num);
}

int		ft_val_links(char **split, int i)
{
	int	links_num;

	links_num = 0;
	while (split[i])
	{
		if (ft_word_counter(split[i], ' ') == 1 && ft_word_counter(split[i], '-') == 2)
		{
			// link is ok
			
			links_num++;
			i++;
		}
		else if (split[i][0] == '#')
			i++;
		else
			ft_exit("ERROR: SHITTY LINK INPUT");
	}
	ft_putnbr(links_num);
	ft_putchar('\n');
	return (0);
}