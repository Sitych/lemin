#include "lem_in.h"

t_queue		*ft_creat_elem(char *data)
{
	t_queue	*ptr;

	if ((ptr = (t_queue*)ft_memalloc(sizeof(t_queue))) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	if ((ptr->name = ft_strdup(data)) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	ptr->next = NULL;
	return (ptr);
}

t_queue		*ft_push(t_queue *head, char *data)
{
	t_queue	*ptr;
	t_queue *start;

	ptr = ft_creat_elem(data);
	if (head == NULL)
	{
		head = ptr;
		return (ptr);
	}
	start = head;
	while (start->next != NULL)
		start = start->next;
	start->next = ptr;
	return (head);
}

t_queue		*ft_pop(t_queue **head)
{
	t_queue	*ptr;

	ptr = *head;
	*head = (*head)->next;
	ptr->next = NULL;
	return (ptr);
}

int		ft_queue_size(t_queue *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

int		ft_isempty(t_queue *head)
{
	if (head == NULL)
		return (0);
	else
		return (1);
}

void	ft_del_elem(t_queue **elem)
{
	ft_strdel(&((*elem)->name));
	(*elem)->next = NULL;
	free(*elem);
	*elem = NULL;
}

void	ft_qprint(t_queue *head)
{
	while (head != NULL)
	{
		ft_printf("%s\n", head->name);
		head = head->next;
	}
}