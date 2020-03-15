/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:25:03 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/03/15 18:42:45 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_file_checker(char **split, t_r_list **start)
{
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
	{
		perror("ERROR: INCORRECT INPUT OF ANTS\n");
		exit (1);
	}
	ant_num = ft_atoi(split);
	if (ant_num < 1 || ant_num > INT32_MAX)
	{
		perror("ERROR: INCORRECT QUANTITY OF ANTS\n");
		exit (1);
	}
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
	if (start == 1 && end == 1)
		return (EXIT_SUCCESS);
	else
	{
		perror("ERROR: THERE SHOULD BE ONLY ONE ENTERANCE AND EXIT");
		exit (EXIT_FAILURE);
	}
}

int		ft_val_room(char **split, t_r_list **start)
{
	size_t		i;
	int			room_num;
	// t_r_list	*tmp;

	i = 1;
	room_num = 0;
	// tmp = ft_crtrm("0 0 0", -2);
	// *start = tmp;
	start = NULL;
	ft_putstr("init\n");
	while ((ft_word_counter(split[i], ' ') != 1 && ft_word_counter(split[i], '-') != 2) || split[i][0] == '#') 
	{
		if ((ft_word_counter(split[i], ' ') == 3 || split[i][0] == '#') && split[i][0] != '\n')
		{
			if (split[i][0] == 'L')
				ft_exit("ERROR: SHITTY ROOM INPUT");
			else if (split[i][0] == '#')
				i++;
			else
			{
				// room is ok
				// tmp = ft_add_push_back(tmp, split, i);
				i++;
				room_num++;
			}
		}
		else 
			ft_exit("ERROR: SHITTY ROOM INPUT");
	}
	// *start = ft_roomdel(start);
	// // work
	// ft_check_name_coord(*start);
	ft_set_htable(split, i);
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