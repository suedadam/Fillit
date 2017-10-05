/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 09:49:28 by asyed             #+#    #+#             */
/*   Updated: 2017/10/05 13:31:01 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	solve(void)
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
	//printf("Bitch\n");
	while (!solve_helper2(local_solvegrid, 1))
	{
		printf("We need to realloc.\n");
		solveinfo->minimum++;
		local_solvegrid = (char **)ft_realloc(local_solvegrid, (solveinfo->minimum + 1) * sizeof(char *));
		printf("Larger\n");
		i = 0;
		while (local_solvegrid[i])
		{
			local_solvegrid[i] = (char *)ft_realloc(local_solvegrid[i], (solveinfo->minimum + 1) * sizeof(char));
			local_solvegrid[i][solveinfo->minimum] = '\0';
			ft_memset(local_solvegrid[i], '.', solveinfo->minimum * sizeof(char));
			i++;
		}
		printf("We expanded to %d\n", solveinfo->minimum);
	}

	i = 0;
	while (local_solvegrid[i])
	{
		printf("%s\n", local_solvegrid[i]);
		i++;
	}
	return (1);
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
	printf("Fired.\n");
	if (local_solvegrid[y][x] != '.')
		return (0);
	while (pc < 3)
	{
		printf("pc: %d\n", pc);
		if (y + pieces[grids[spot].i].y[pc] >= solveinfo->minimum || x + pieces[grids[spot].i].x[pc] >= solveinfo->minimum)
			return (0);
		printf("something after mem breach\n");
		printf("Min: %d\n", solveinfo->minimum);
		printf("(%d) %d %d\n", pc, y, pieces[grids[spot].i].y[pc]);
		if (local_solvegrid[ y + pieces[grids[spot].i].y[pc]][ x + pieces[grids[spot].i].x[pc]] == '.')
		{
			printf("(%d) %d %d\n", pc, y, pieces[grids[spot].i].y[pc]);
			pc++;
		}
		else
		{
			printf("returning 0 is failing?\n");
			return (0);
		}
		printf("8\n");
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
		printf("[%d] (%d,%d) Change = (%d, %d)\n", spot, x, y, pieces[grids[spot].i].x[pc], pieces[grids[spot].i].y[pc]);
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
			// printf("S: %d (%d, %d)\n", spot, x, y);
			printf("0\n");
			if (piece_fits(local_solvegrid, x, y, spot))
			{
				printf("1\n");
				piece_set(local_solvegrid, x, y, spot, ('A' + spot - 1));
				i = 0;
				while (local_solvegrid[i])
				{
					printf("%s\n", local_solvegrid[i]);
					i++;
				}
				printf("2\n");
				if (solve_helper2(local_solvegrid, spot + 1))
				{
					printf("3\n");
					return (1);
				}
				else
				{
					printf("4\n");
					piece_set(local_solvegrid, x, y, spot, '.');
				}
			}
			if (x == (solveinfo->minimum - 1))
			{
				printf("5\n");
				// printf("S: %d Reset y to %d\n", spot, y + 1);
				x = 0;
				y++;
			}
			else
			{
				printf("6\n");
				x++;
			}
		}
		return (0);
	}
	return (1);
}
