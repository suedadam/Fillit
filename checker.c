/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 09:49:28 by asyed             #+#    #+#             */
/*   Updated: 2017/10/06 10:46:49 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_grid	*g_grids;
t_info	*g_solveinfo;

int		numofgrids(char *buf)
{
	int	i;

	i = 1;
	while (*buf)
	{
		if (*buf == '\n' && *(buf + 1) == '\n')
			i++;
		buf++;
	}
	return (i);
}

void	stage_one(int n, char *buf)
{
	int delta[3];
	int i;
	int j;

	i = 1;
	j = 0;
	while (buf[i])
	{
		if (buf[i] == '#' && j < 3)
		{
			delta[j] = i;
			j++;
		}
		i++;
	}
	struct_add(what_type(n, delta));
}

int		error_check(char c, int i, int hash)
{
	if (hash > 4)
		return (0);
	if (i == 20 && c != '\n')
	{
		if (c != '\n')
			return (0);
		else
			return (1);
	}
	if ((i + 1) % 5 == 0 || i == 20)
	{
		if (c != '\n')
			return (0);
		else
			return (1);
	}
	if ((i + 1) % 5 && c != '.' && c != '#')
		return (0);
	return (1);
}

int		convert_buf(char *buf)
{
	int i;
	int hash;

	i = 0;
	hash = 0;
	while (*buf)
	{
		if (!(error_check(*buf, i, hash)))
			return (0);
		if (i == 20)
		{
			i = -1;
			hash = 0;
		}
		if (*buf == '#')
		{
			hash++;
			if (hash == 1)
				stage_one(i + 1, buf);
		}
		i++;
		buf++;
	}
	return (i != 20 || (hash != 4) ? 0 : 1);
}

void	perform_check(char *buf)
{
	int small_grids;

	small_grids = numofgrids(buf);
	g_solveinfo = (t_info *)ft_memalloc(sizeof(g_solveinfo));
	g_grids = (t_grid *)ft_memalloc(small_grids + 1);
	g_solveinfo = (t_info *)ft_memalloc(sizeof(struct s_info *));
	g_solveinfo->minimum = small_grids;
	if (!g_grids)
	{
		ft_putstr("Error in allocating small grids!");
		exit(2);
	}
	minimumset(small_grids);
	if (!(convert_buf(buf)))
	{
		ft_putstr("error\n");
		exit(3);
	}
	solve();
}
