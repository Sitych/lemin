/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:20:09 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/03/16 22:51:10 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_hash(char *data)
{
	int	key;
	int	i;

	key = 0;
	i = 0;
	while (data[i])
	{
		key = key + data[i] * ft_pow(P, i);
		i++;
	}
	return (key % HTSIZE);
}

void			ft_create_htable(int len)
{
	int i;

	i = 0;
	if ((g_htable = (t_htable**)malloc(sizeof(t_htable*) * len)) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	while (i < len)
	{
		if ((g_htable[i] = (t_htable*)malloc(sizeof(t_htable))) == NULL)
			ft_exit("ERROR: MALLOC ERROR");
		g_htable[i]->rooms = NULL;
		g_htable[i]->next = NULL;
		i++;
	}
}

t_htable	*ft_insert_room(t_r_list *room)
{
	t_htable	*p;
	t_htable	*p0;
	int		key;

	key = ft_hash(room->name);
	if ((p = (t_htable*)malloc(sizeof(t_htable))) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	p0 = g_htable[key];
	g_htable[key] = p;
	p->next = p0;
	p->rooms = room;
	return (p);
}

// t_htable	*ft_insert_link(char *data, t_r_list *link)
// {
// 	t_htable	*p;
// 	int		key;

// 	key = ft_hash(data);
// 	// while lst != NULL
// 	while (g_htable[key]->rooms->next != NULL)
// 		g_htable[key]->rooms = g_htable[key]->rooms->next;
// 	g_htable[key]->rooms->next;
// }

void		ft_thprint(void)
{
	int i;

	i = 0;
	while (i < HTSIZE)
	{
		if (g_htable[i]->rooms != NULL)
			ft_print(g_htable[i]->rooms);
		i++;
	}
}

t_htable	*ft_find_data(char *data)
{
	t_htable	*p;
	int			key;

	key = ft_hash(data);
	p = g_htable[key];
	while (p->rooms != NULL)
	{
		if (!ft_strcmp(p->rooms->name, data))
			return (p);
		p = p->next;
	}
	return (p);
}
