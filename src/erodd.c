// paste 42 header
#include "lem_in.h"

void	ft_input_fork(char *data)
{
	if (!ft_strcmp(ft_find_start()->name, data))
		return ;
	t_room	*room;
	int		i;
	int		good_link; //candidate to be EDINSTVENNYM

	i = 0;
	room = ft_find_data(data);
	printf("I'M HERE!\n\n");
	while (i < room->num_links)
	{
		ft_printf("R_NAME %s, OUT_L = %d\n", ft_find_data(room->links[i])->name, ft_find_data(room->links[i])->in);
		if (room->links[i] != NULL)
		{
			if (ft_find_data(room->links[i])->bfs_level < room->bfs_level)
			{
				if (ft_find_data(room->links[i])->in > 1 && ft_find_data(room->links[i])->bfs_level != 0)
				{
					// HERE WILL BE MAGIC
					ft_printf("R_NAME %s, OUT_L = %d\n", ft_find_data(room->links[i])->name, ft_find_data(room->links[i])->in);
					good_link = ft_find_good_link(ft_find_data(room->links[i])->name);
					printf("%s\n", ft_find_data(room->links[good_link])->name);
				}
			}
		}
	i++;
	}
}

int ft_find_good_link(char *data)
{
	int		ways_num;
	ways_num = ft_find_data(data)->in;
	int		ways_length[ways_num];
	int		min_way;
	int		j;
	int		i;

	j = 0;
	while (j < ways_num)
	{
		ways_length[i] = ft_count_way(data);
		j++;
	}
	return (ways_length[j - 1]);
}

int		ft_count_way(char *data)
{

}