/* ************************************************************************** */
/* */
/* ::: :::::::: */
/* counter.c :+: :+: :+: */
/* +:+ +:+ +:+ */
/* By: rretta <rretta@student.42.fr> +#+ +:+ +#+ */
/* +#+#+#+#+#+ +#+ */
/* Created: 2020/08/05 01:04:54 by rretta #+# #+# */
/* Updated: 2020/08/06 02:54:30 by rretta ### ########.fr */
/* */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_diff_count (t_way *ways, t_way *current)
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

static int		first_step(t_way *ways, int ant_id, int ants)
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

static int		next_step(t_way *ways, t_graph *g)
{
	t_way_node	*tmp;
	int			step_sum;
	int			test;

	step_sum = 0;
	tmp = 0;
	test = 0;
	while (ways)
	{
		tmp = ways->end_node->prev;
		if (ft_strcmp(tmp->name->name, g->start->name) == 0)
		{
			ways = ways->next;
			continue ;
		}
		while (ft_strcmp(tmp->name->name, g->start->name) != 0)
		{
			if (tmp->name->ant_id != 0)
			{
				test = 1;
				tmp->next->name->ant_id = tmp->name->ant_id;
				tmp->name->ant_id = 0;
				tmp->next->name->ants++;
				tmp->name->ants--;
			}
			tmp = tmp->prev;
		}
		ways = ways->next;
	}
	if (test == 1)
		step_sum++;
	return (step_sum);
}

int			ft_step_counter(t_way *ways, t_graph *g)
{
	int ant_id;
	int step_sum;
	int tmp;

	ant_id = 1;
	step_sum = 0;
	ant_id = first_step(ways, ant_id, g->ants);
	step_sum++;
	while (ant_id <= g->ants)
	{
		// ft_printf("%d - %d\n", ant_id, step_sum);
		tmp = step_sum;
		step_sum = step_sum + next_step(ways, g);
		ant_id = first_step(ways, ant_id, g->ants);
		if (tmp == step_sum)
			step_sum++;
	}
	t_way *test;
	t_way_node *test2;
	test = ways;
	while (test)
	{
		test2 = test->start_node;
		while (test2 != NULL)
		{
			ft_printf("Room %s ant %d ", test2->name->name, test2->name->ant_id);
			test2 = test2->next;
		}
		ft_printf("\n");
		test = test->next;
	}
	
	while (g->end->ants != g->ants)
	{
		
		step_sum = step_sum + next_step(ways, g);
		test = ways;
		while (test)
		{
			test2 = test->start_node;
			while (test2 != NULL)
			{
				ft_printf("Room %s ant %d ", test2->name->name, test2->name->ant_id);
				test2 = test2->next;
			}
			ft_printf("\n");
			test = test->next;
		}
		// ft_printf("%d\n", g->end->ants);
	}
	g->end->ants = 0;
	return (step_sum);
}
