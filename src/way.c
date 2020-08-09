/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:29:27 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/08/09 18:27:09 by rretta           ###   ########.fr       */
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

t_edge	*ft_find_min_bfs_link(t_edge *links)
{
	int		minbfs;
	t_edge	*minbfslink;

	minbfs = INT32_MAX;
	while (links != NULL)
	{
		if (minbfs > ft_find_data(links->name)->bf && links->weight != -1)
		{
			minbfs = ft_find_data(links->name)->bf;
			minbfslink = links;
		}
		links = links->next;
	}
	if (minbfs == INT32_MAX)
		return (NULL);
	return (minbfslink);
}

t_way	*ft_paste_node(t_way *way, t_way_node *node)
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

t_way	*ft_find_short_way(t_graph *g, t_room *room, t_edge *(*func) (t_edge *link))
{
	t_edge		*link;
	t_way	*shortway;
	
	shortway = NULL;
	shortway = ft_paste_node(shortway, ft_create_node(room));
	if ((link = func(room->links)) == NULL)
		return (ft_del_way_return_null(&shortway));
	room = ft_find_data(link->name);
	shortway = ft_paste_node(shortway, ft_create_node(room));
	while (ft_strcmp(room->name, g->start->name))
	{
		if ((link = func(room->links)) == NULL)
			return (ft_del_way_return_null(&shortway));
		shortway = ft_paste_node(shortway, ft_create_node(ft_find_data(link->name)));
		room = ft_find_data(link->name);
	}
	shortway->next = NULL;
	return (shortway);
}

t_way	*ft_del_way_return_null(t_way **way)
{
	t_way_node *tmp;
	t_way_node *ptr;
	
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
	return (NULL);
}

void	ft_print_way(t_way *way)
{
	t_way_node	*node;

	node = way->start_node;
	while (node != NULL)
	{
		ft_printf("%s ", node->name->name);
		node = node->next;
	}
	ft_printf("len = %d\n", way->way_length);
}

// t_way	*ft_sort_solution(t_way *way)
// {
// 	t_way	*left;
// 	t_way	*right;
// 	t_way	*tmp;

// 	left = way;
// 	right = way->next;
// 	while (left->next != NULL)
// 	{
// 		while (right)
// 		{
// 			if (left->way_length < right->way_length)
// 			{
// 				tmp = left;
// 				tmp->next = right->next;
// 				left = right;
// 				right->next = tmp;	
// 			}
// 			right = right->next;
// 		}
// 		left = left->next;
// 		right = left;
// 	}
// 	return (way);
// }

void	ft_sort_solution(t_way *way)
{
	t_way	*left;
	t_way	*right;
	t_way	*tmp;

	left = way;
	right = way->next;
	tmp = ft_memalloc(sizeof(t_way));
	while (left->next != NULL)
	{
		while (right)
		{
			if (left->way_length > right->way_length)
			{
				tmp->start_node = left->start_node;
				tmp->end_node = left->end_node;
				tmp->way_length = left->way_length;
				left->start_node = right->start_node;
				left->end_node = right->end_node;
				left->way_length = right->way_length;
				right->start_node = tmp->start_node;
				right->end_node = tmp->end_node;
				right->way_length = tmp->way_length;
			}
			right = right->next;
		}
		left = left->next;
		right = left->next;
	}
	free(tmp);
}
