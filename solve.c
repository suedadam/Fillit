/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 09:49:28 by asyed             #+#    #+#             */
/*   Updated: 2017/10/07 18:30:06 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve(void)
{
	char	**local_solvegrid;
	int		i;

	local_solvegrid = (char **)ft_memalloc((g_solveinfo->minimum + 1) *
		sizeof(char *));
	i = 0;
	while (i < g_solveinfo->minimum)
	{
		local_solvegrid[i] = (char *)ft_memalloc((g_solveinfo->minimum + 1) *
			sizeof(char));
		ft_memset(local_solvegrid[i], '.', g_solveinfo->minimum * sizeof(char));
		i++;
	}
	solve_stage_2(local_solvegrid, 0);
}

void	solve_stage_2(char **local_solvegrid, int i)
{
	while (!solve_helper(local_solvegrid, 1))
	{
		g_solveinfo->minimum++;
		local_solvegrid = (char **)ft_realloc(local_solvegrid,
			(g_solveinfo->minimum + 1) * sizeof(char *));
		local_solvegrid[g_solveinfo->minimum] = 0;
		i = 0;
		while (i < g_solveinfo->minimum)
		{
			local_solvegrid[i] = (char *)ft_realloc(local_solvegrid[i],
				(g_solveinfo->minimum + 1) * sizeof(char));
			local_solvegrid[i][g_solveinfo->minimum] = 0;
			ft_memset(local_solvegrid[i], '.', g_solveinfo->minimum *
				sizeof(char));
			i++;
		}
	}
	i = 0;
	while (local_solvegrid[i])
	{
		ft_putstr(local_solvegrid[i]);
		ft_putchar('\n');
		i++;
	}
}

int		piece_fits(char **local_solvegrid, int x, int y, int spot)
{
	int pc;

	pc = 0;
	if (local_solvegrid[y][x] != '.')
		return (0);
	while (pc < 3)
	{
		if (y + g_pieces[g_grids[spot].i].y[pc] >= g_solveinfo->minimum || x +
			g_pieces[g_grids[spot].i].x[pc] >= g_solveinfo->minimum)
			return (0);
		if (local_solvegrid[y + g_pieces[g_grids[spot].i].y[pc]]
			[x + g_pieces[g_grids[spot].i].x[pc]] == '.')
			pc++;
		else
			return (0);
	}
	return (1);
}

int		solve_helper(char **local_solvegrid, int spot)
{
	int x;
	int y;
	int i;

	y = 0;
	x = 0;
	if (!g_grids[spot].i)
		return (1);
	while (y < g_solveinfo->minimum)
	{
		if (piece_fits(local_solvegrid, x, y, spot))
		{
			piece_set(local_solvegrid, x, y, spot);
			i = 0;
			while (local_solvegrid[i])
				i++;
			if (solve_helper(local_solvegrid, spot + 1))
				return (1);
			else
				piece_unset(local_solvegrid, x, y, spot);
		}
		x = (x == (g_solveinfo->minimum - 1) && ++y) ? (0) : (x + 1);
	}
	return (0);
}
