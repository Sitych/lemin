/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:20:09 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/03/15 18:39:10 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// static int		ft_log(size_t a, size_t x)
// {
// 	size_t	n;

// 	if (a < 1)
// 		return (-1);
// 	if (x == 1)
// 		return (0);
// 	n = 0;
// 	while (ft_pow(a, n) > x)
// 		n++;
// 	return (n);
// }

size_t			ft_hash(char *data)
{
	size_t	key;
	size_t	i;

	key = 0;
	i = 0;
	while (data[i])
	{
		key = key + data[i] * ft_pow(P, i);
		i++;
	}
	if (g_nbr == 0)
		ft_exit("ERROR: DIVISION BY ZERO");
	return (key % g_nbr);
}

void			ft_create_htable(size_t len)
{
	size_t i;

	i = 0;
	g_htsize = len;
	if ((g_htable = (t_htable**)malloc(sizeof(t_htable*) * len)) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	while (i < g_htsize)
	{
		if ((g_htable[i] = (t_htable*)malloc(sizeof(t_htable))) == NULL)
			ft_exit("ERROR: MALLOC ERROR");
		g_htable[i]->rooms = NULL;
		g_htable[i]->next = NULL;
		i++;
	}
}

void			ft_set_htable(char **split, size_t len)
{
	t_r_list	*room;
	size_t		i;
	int			flag;

	i = 0;
	g_nbr = len;
	ft_create_htable(len);
	while (++i < g_htsize)
	{
		flag = (i > 0 && ft_strstr(split[i - 1], "##start")) ? 0 :\
						(i > 0 && ft_strstr(split[i - 1], "##end")) ? 1 : -1;
		if (ft_strstr(split[i], "##") != 0 && flag == -1)
			continue ;
		room = ft_crtrm(split[i], flag);
		// ft_printf("name = %s x = %d y = %d flag = %d\n", room->name, room->x, room->y, room->flag);
		g_htable[ft_hash(room->name)]->rooms = room;
	}
}

t_htable	*ft_insert_data(t_r_list *room)
{
	t_htable	*p;
	t_htable	*p0;
	size_t			bucket;

	bucket = ft_hash(room->name);
	if ((p = (t_htable*)malloc(sizeof(t_htable))) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	p0 = g_htable[bucket];
	g_htable[bucket] = p;
	p->next = p0;
	p->rooms = room;
	return (p);
}

t_htable	*ft_find_data(char *data)
{
	t_htable	*p;

	p = g_htable[ft_hash(data)];
	return (p);
}
