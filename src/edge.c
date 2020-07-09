#include "lem_in.h"

t_edge		*ft_creat_edge(char *name)
{
	t_edge	*ptr;

	if ((ptr = (t_edge*)ft_memalloc(sizeof(t_edge))) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	if ((ptr->name = ft_strdup(name)) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	ptr->len = 0;
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}

void		ft_del_edge(t_edge *ptr)
{
	ft_strdel(&(ptr->name));
	free(ptr);
}

void			ft_del_from_links(t_edge **ptr)
{
	t_edge	*prev;
	t_edge	*next;
	t_edge	*tmp;

	prev = (*ptr)->prev;
	next = (*ptr)->next;
	if (prev != NULL)
		prev->next = (*ptr)->next;
	if (next != NULL)
		next->prev = (*ptr)->prev;
	tmp = *ptr;
	if (prev != NULL)
		*ptr = prev;
	else
		*ptr = next;
	ft_del_edge(tmp);
}
  