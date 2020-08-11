/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:29:27 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/08/11 00:18:21 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_way_node	*ft_create_node(t_room *link_name)
{
	t_way_node	*tmp;

	tmp = NULL;
	if ((tmp = (t_way_node*)malloc(sizeof(t_way_node))) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	tmp->name = link_name;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

t_edge		*ft_find_min_bfs_link(t_edge *links)
{
	int		minbfs;
	t_edge	*minbfslink;

	minbfs = INT32_MAX;
	while (links != NULL)
	{
		if (minbfs >= ft_find_data(links->name)->bf && links->weight != -1 && links->flag != -3)
		{
			minbfs = ft_find_data(links->name)->bf;
			minbfslink = links;
		}
		links = links->next;
	}
	if (minbfs == INT32_MAX)
		return (NULL);
	minbfslink->flag = -3;
	return (minbfslink);
}

t_way		*ft_paste_node(t_way *way, t_way_node *node)
{
	t_way_node	*tmp;

	if (way == NULL)
	{
		if ((way = (t_way*)malloc(sizeof(t_way))) == NULL)
			ft_exit("MALLOC ERROR");
		way->way_length = 0;
		way->end_node = node;
		way->start_node = node;
		way->next = NULL;
		return (way);
	}
	tmp = way->end_node;
	while (tmp->prev)
		tmp = tmp->prev;
	tmp->prev = node;
	node->next = tmp;
	way->start_node = node;
	way->way_length++;
	way->next = NULL;
	return (way);
}

t_way		*ft_find_way(t_graph *g, t_room *room, t_edge *(*f) (t_edge *))
{
	t_edge		*link;
	t_way		*shortway;

	shortway = NULL;
	shortway = ft_paste_node(shortway, ft_create_node(room));
	if ((link = f(room->links)) == NULL)
		return (ft_del_way_return_null(&shortway));
	room = ft_find_data(link->name);
	shortway = ft_paste_node(shortway, ft_create_node(room));
	while (ft_strcmp(room->name, g->start->name))
	{
		// ft_print(room);
		// ft_printf("weight from %d, weight to %d", ft_find_edge(ft_find_data("Bwt6"), ft_find_data("Wwh2"))->weight, ft_find_edge(ft_find_data("Wwh2"), ft_find_data("Bwt6"))->weight);
		if ((link = f(room->links)) == NULL)
			return (ft_del_way_return_null(&shortway));
		shortway = ft_paste_node(shortway, \
									ft_create_node(ft_find_data(link->name)));
		room = ft_find_data(link->name);
	}
	shortway->next = NULL;
	return (shortway);
}

t_way		*ft_del_way_return_null(t_way **way)
{
	t_way_node	*tmp;
	t_way_node	*ptr;
	t_way		*tmp_way;

	while (*way)
	{
		tmp_way = (*way)->next;
		tmp = (*way)->start_node;
		while (tmp != NULL)
		{
			ptr = tmp;
			tmp = tmp->next;
			ptr->name = NULL;
			free(ptr);
		}
		(*way)->end_node = NULL;
		free(*way);
		*way = NULL;
		*way = tmp_way;
	} 
	return (NULL);
}
