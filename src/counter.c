/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:04:54 by rretta            #+#    #+#             */
/*   Updated: 2020/08/05 06:04:42 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_step_counter(t_way *ways, t_graph *g)
{
	int	ant_id;
	int	step_sum;

	ant_id = 1;
	step_sum = 0;
	ant_id = first_step(ways, ant_id, g->ants);
	step_sum++;
	while (ant_id <= g->ants)
	{
		step_sum = step_sum + next_step(ways);
		ant_id = first_step(ways, ant_id, g->ants);
		step_sum++;
	}
	while (ft_find_end()->ants != g->ants)
		step_sum = step_sum + next_step(ways);
	return (step_sum);
}

int		ft_diff_count(t_way *ways, t_way *current)
{
	int diff;

	diff = 0;
	while (ways != current)
	{
		diff = diff + current->way_length - ways->way_length;
		ways = ways->next;
	}
	return (diff);
}

int		first_step(t_way *ways, int ant_id, int ants)
{
	t_way *original_ways;

	original_ways = ways;
	while (ways && (ants - ant_id + 1) > 0)
	{
		if ((ants - ant_id + 1) > ft_diff_count(original_ways, ways))
		{
			ways->start_node->next->name->ant_id = ant_id;
			ways->start_node->next->name->ants++;
			ant_id++;
		}
		ways=ways->next;
	}
	return (ant_id);
}

int		next_step(t_way *ways)
{
	t_way_node	*tmp;
	int			step_sum;

	step_sum = 0;
	while (ways)
	{
		tmp = ways->end_node->prev;
		if (strcmp(tmp->name, ft_find_start()->name))
		{
			ways = ways->next;
			continue ;
		}
		while (strcmp(tmp->name, ft_find_start()->name))
		{
			if (tmp->name->ant_id != 0)
			{
				tmp->next->name->ant_id = tmp->name->ant_id;
				tmp->name->ant_id = 0;
				tmp->next->name->ants++;
				tmp->name->ants--;
				step_sum++;
			}
			tmp = tmp->prev;
		}
		ways = ways->next;
	}
	return (step_sum);
}
