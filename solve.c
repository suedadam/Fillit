/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 09:49:28 by asyed             #+#    #+#             */
/*   Updated: 2017/10/05 14:47:29 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve(void)
{
	char	**local_solvegrid;
	int		p;
	int		i;
	int		j;
	void	*save;

	local_solvegrid = (char **)ft_memalloc((solveinfo->minimum + 1) * sizeof(char *));

	p = 0;
	i = 0;
	j = 0;
	save = grids;

	while (i < solveinfo->minimum)
	{
		local_solvegrid[i] = (char *)ft_memalloc((solveinfo->minimum + 1) * sizeof(char));
		ft_memset(local_solvegrid[i], '.', solveinfo->minimum * sizeof(char));
		i++;
	}
	while (!solve_helper2(local_solvegrid, 1))
	{
		solveinfo->minimum++;
		local_solvegrid = (char **)ft_realloc(local_solvegrid, (solveinfo->minimum + 1) * sizeof(char *));
		local_solvegrid[solveinfo->minimum] = 0;;
		i = 0;
		while (i < solveinfo->minimum)
		{
			local_solvegrid[i] = (char *)ft_realloc(local_solvegrid[i], (solveinfo->minimum + 1) * sizeof(char));
			local_solvegrid[i][solveinfo->minimum] = '\0';
			ft_memset(local_solvegrid[i], '.', solveinfo->minimum * sizeof(char));
			i++;
		}
	}

	i = 0;
	while (local_solvegrid[i])
	{
		printf("%s\n", local_solvegrid[i]);
		i++;
	}
}

int		totalpieces(void)
{
	int i;

	i = 0;
	while (grids[i].i)
		i++;
	return (i);
}

int		piece_fits(char **local_solvegrid, int x, int y, int spot)
{
	int pc;

	pc = 0;
	if (local_solvegrid[y][x] != '.')
		return (0);
	while (pc < 3)
	{
		if (y + pieces[grids[spot].i].y[pc] >= solveinfo->minimum || x + pieces[grids[spot].i].x[pc] >= solveinfo->minimum)
			return (0);
		if (local_solvegrid[ y + pieces[grids[spot].i].y[pc]][ x + pieces[grids[spot].i].x[pc]] == '.')
			pc++;
		else
			return (0);
	}
	return (1);
}

void	piece_set(char **local_solvegrid, int x, int y, int spot, char c)
{
	int pc;

	pc = 0;
	local_solvegrid[y][x] = c;
	while (pc < 3)
	{
		local_solvegrid[ y + pieces[grids[spot].i].y[pc]][ x + pieces[grids[spot].i].x[pc]] = c;
		pc++;
	}
}

int		solve_helper2(char **local_solvegrid, int spot)
{
	int x;
	int y;
	int i;
	y = 0;
	x = 0;
	if (grids[spot].i)
	{
		while (y < solveinfo->minimum)
		{
			if (piece_fits(local_solvegrid, x, y, spot))
			{
				piece_set(local_solvegrid, x, y, spot, ('A' + spot - 1));
				i = 0;
				while (local_solvegrid[i])
					i++;
				if (solve_helper2(local_solvegrid, spot + 1))
				{
					return (1);
				}
				else
					piece_set(local_solvegrid, x, y, spot, '.');
			}
			if (x == (solveinfo->minimum - 1))
			{
				x = 0;
				y++;
			}
			else
				x++;
		}
		return (0);
	}
	return (1);
}
