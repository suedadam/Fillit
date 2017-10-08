/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 09:49:28 by asyed             #+#    #+#             */
/*   Updated: 2017/10/07 18:31:17 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	minimumset(int small_grids)
{
	int i;

	i = 0;
	while (i < small_grids)
	{
		if ((i * i) >= (small_grids * 4))
			break ;
		i++;
	}
	g_solveinfo->minimum = i;
}

int		struct_add(int j)
{
	int i;

	i = 1;
	while (g_grids[i].i)
		i++;
	g_grids[i].i = j;
	return (1);
}

void	piece_set(char **local_solvegrid, int x, int y, int spot)
{
	int		pc;
	char	c;

	pc = 0;
	c = ('A' + spot - 1);
	local_solvegrid[y][x] = c;
	while (pc < 3)
	{
		local_solvegrid[y + g_pieces[g_grids[spot].i].y[pc]]
		[x + g_pieces[g_grids[spot].i].x[pc]] = c;
		pc++;
	}
}

void	piece_unset(char **local_solvegrid, int x, int y, int spot)
{
	int pc;

	pc = 0;
	local_solvegrid[y][x] = '.';
	while (pc < 3)
	{
		local_solvegrid[y + g_pieces[g_grids[spot].i].y[pc]]
		[x + g_pieces[g_grids[spot].i].x[pc]] = '.';
		pc++;
	}
}
