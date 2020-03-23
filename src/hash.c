/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:20:09 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/03/19 16:46:19 by rretta           ###   ########.fr       */
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
		g_htable[i++] = NULL;
}

void		ft_thprint(void)
{
	int i;

	i = 0;
	while (i < HTSIZE)
	{
		if (g_htable[i] != NULL)
			ft_print(g_htable[i]->rooms);
		i++;
	}
}

t_room		*ft_find_data(char *data)
{
	t_htable	*p;
	int			key;

	key = ft_hash(data);
	p = g_htable[key];
	while (p != NULL)
	{
		if (!ft_strcmp(p->rooms->name, data))
			return (p->rooms);
		p = p->next;
	}
	return (NULL);
}

void		ft_del_htable(void)
{
	int 		i;
	t_htable	*ptr;

	i = 0;
	while (i < HTSIZE)
	{
		ptr = g_htable[i];
		while (ptr != NULL)
		{
			ft_del_room(&(ptr->rooms));
			ptr = ptr->next;
		}
		i++;
	}
	free(g_htable);
}

t_htable	*ft_find_start(void)
{
	int			i;
	t_htable	*ptr;

	i = 0;
	while (i < HTSIZE)
	{
		ptr = g_htable[i];
		if (ptr != NULL)
			if (ptr->rooms->bfs_level == 0)
				return (ptr);
		i++;
	}
	return (NULL);
}