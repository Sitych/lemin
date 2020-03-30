#include "lem_in.h"

// void	ft_input_fork()
// {
// 	t_room	*room;
// 	t_queue	*ptr;
// 	t_queue	*elem;
// 	int		i;
// 	int		count;

// 	ptr = ft_creat_elem(ft_find_start()->name);
// 	while (ft_isempty(ptr))
// 	{
// 		elem = ft_pop(&ptr);
// 		room = ft_find_data(elem->name);
// 		i = 0;
// 		while (i < room->num_links)
// 		{
// 			if (ft_find_data(room->links[i])->bfs_level != INT_MAX &&\
// 				ft_find_data(room->links[i])->bfs_level > room->bfs_level)
// 				ptr = ft_push(ptr, room->links[i]);
// 			i++;
// 		}
// 		while (room->in > 1)
// 		{
// 			if ((count = ft_without_output_fork(room)) != 0)
				
// 		}
// 		ft_del_elem(&elem);
// 	}
// }