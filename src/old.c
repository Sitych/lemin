#include "lem_in.h"

void			ft_set_htable(char **split, size_t len)
{
	t_r_list	*room;
	size_t		i;
	size_t		j;
	int			flag;

	i = 0;
	ft_create_htable(len);
	while (++i < HTSIZE)
	{
		j = 0;
		flag = (i > 0 && ft_strstr(split[i - 1], "##start")) ? 0 :\
						(i > 0 && ft_strstr(split[i - 1], "##end")) ? 1 : -1;
		if (ft_strstr(split[i], "##") != 0 && flag == -1)
			continue ;
		room = ft_crtrm(split[i], flag);
		if (g_htable[ft_hash(room->name)]->rooms != NULL)
		{
			if (ft_strcmp(room->name, g_htable[ft_hash(room->name)]->rooms->name))
				ft_insert_room(room);
			else
				ft_exit("EROROR: SAME ROOM NAMES");
		}
		ft_insert_room(room);
	}
}

void		ft_prng(unsigned int seed)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		seed = (8253729 * seed + 2396403);
		g_rand8[i] = seed % HTSIZE;
		i++;
	}
}

t_thindex	ft_hash(char *data)
{
	t_thindex		h;
	unsigned char	h1;
	unsigned char	h2;
	
	if (*data == 0)
		return (0);
	h1 = *data;
	h2 = *data + 1;
	while (*data++)
	{
		h1 = g_rand8[h1 ^ *data];
		h2 = g_rand8[h2 ^ *data];
	}
	h = ((t_thindex)h1 << 8) | (t_thindex)h2;
	return (h % HTSIZE);
}

static int		ft_log(size_t a, size_t x)
{
	size_t	n;

	if (a < 1)
		return (-1);
	if (x == 1)
		return (0);
	n = 0;
	while (ft_pow(a, n) > x)
		n++;
	return (n);
}
