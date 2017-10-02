/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 09:49:28 by asyed             #+#    #+#             */
/*   Updated: 2017/10/02 09:52:42 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	solve(void)
{
	char	**local_solvegrid;
	int		piecement;
	int	i;
	int	j;
	void	*save;

	local_solvegrid = (char **)ft_memalloc(solveinfo->minimum * sizeof(char *));

	piecement = 0;
	i = 0;
	j = 0;
	save = grids;

	while (local_solvegrid[i])
	{
		local_solvegrid[i] = (char *)ft_memalloc(solveinfo->minimum * sizeof(char));
		local_solvegrid[i] = (char *)ft_memset(local_solvegrid[i], '.', solveinfo->minimum * sizeof(char));
		while (local_solvegrid[i][j])
		{
			if (grids->i <= 0)
			{
				if (nextpiece() == 0)
					return (0);
			}
			if (grids->i == 2)
			{
				local_solvegrid[0][0] = '#';
				local_solvegrid[0][1] = '#';
				local_solvegrid[0][2] = '#';
				local_solvegrid[0][3] = '#';
				j += 4;
			}
			else
			{
				j++;
				grids++;
			}
		}
		i++;
	}
	i = 0;
	printf("Min; %d\n", solveinfo->minimum);
	while (local_solvegrid[i])
	{
		printf("%s\n", local_solvegrid[i]);
		i++;
	}
	return (1);
}

int	nextpiece(void)
{
	if (totalplaced() <= 0)
		return (0);
	while (grids)
	{
		if (grids->i > 0)
			return (1);
		grids++;
	}
	return (0);
}

int		placeable(char **grid, int type, int x, int y)
{
	int i;
	int j;

	i = x;
	j = y;
	if (type == 2)
	{
		while (grid[i][j] && y <= (x + 3))
		{
			if (grid[i][j] == '#')
				return (0);
			else
			{
				i++;
				j++;
			}
		}
		return (1);
	}
	return (0);
}

int		totalplaced(void)
{
	int	i;
	int res;

	i = 0;
	res = 0;
	while (grids[i].i)
	{
		res += grids[i].i;
		i++;
	}
	return (res);
}
