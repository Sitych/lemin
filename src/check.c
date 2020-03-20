/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:25:03 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/03/20 22:16:23 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_file_checker(char **split, int all)
{
	int		i;
	char	***links;

	ft_create_htable(HTSIZE);
	ft_val_ant(split[0]);
	ft_putstr("start\n");
	ft_val_bond(split);
	ft_putstr("bond\n");
	i = ft_val_room(split);
	ft_putstr("val_room\n");
	links = ft_val_links(split, i, all); //TO MOVE TO FT_FILE_CHECKER FUNC (MAYBE)
	ft_set_links(links, i, all);
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
	t_room	*room;
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
		ft_val_coords(split, i);
		room = ft_crtrm(split[i], flag);
		if ((ptr = ft_find_data(room->name)) != NULL)
			ft_exit("EROROR: SAME ROOM NAMES");
		ft_insert_room(room);
		i++;
	}
	return (i);
}

char		***ft_val_links(char **links, int i, int all)
{
	int	links_num;
	int		j;
	char	***link;

	links_num = 0;
	j = i;
	if ((link = (char***)ft_memalloc((sizeof(char**)) * (all - i + 1))) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	while (links[i])
	{
		if (links[i][0] == '#')
		{
			i++;
			continue ;
		}
		if (ft_word_counter(links[i], ' ') == 1 && ft_word_counter(links[i], '-') == 2)
		{
			//PASHA insert
			if ((link[i - j] = ft_strsplit(links[i], '-')) == NULL)
				ft_exit("ERROR: SPLIT ERROR");
			link[i - j] = ft_swap_links(&links[i], link[i - j]);
			// VANYA insert
			ft_val_links2(links, j, i, link[i - j]);
			links_num++;
			i++;
		}
		else
			ft_exit("ERROR: SHITTY LINK INPUT");
	}
	ft_putnbr(links_num);
	ft_putchar('\n');
	return (link);
}

int		ft_val_coords(char **split, int i)
{
	int		j;
	char	**xy1;
	char	**xy2;

	j = 1;
	if ((xy2 = ft_strsplit(split[i], ' ')) == NULL)
		ft_exit("ERROR: SPLIT ERROR");
	while (j < i)
	{
		if (split[j][0] == '#')
		{
			j++;
			continue ;
		}
		if ((xy1 = ft_strsplit(split[j], ' ')) == NULL)
			ft_exit("ERROR: SPLIT ERROR");
		if (((ft_strcmp(xy1[1], xy2[1]) == 0)) && (ft_strcmp(xy1[2], xy2[2]) == 0))
			ft_exit("ERROR: SAME ROOM COORDINATES");
		j++;
		ft_free((void**)xy1, 3);
	}
	ft_free((void**)xy2, 3);
	return (0);
}