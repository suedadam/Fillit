/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 09:49:28 by asyed             #+#    #+#             */
/*   Updated: 2017/10/02 15:08:22 by asyed            ###   ########.fr       */
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

	local_solvegrid = (char **)ft_memalloc(solveinfo->minimum * sizeof(char *));

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
	while (!solve_helper(local_solvegrid, totalpieces()))
	{
		solveinfo->minimum++;
		local_solvegrid = (char **)ft_realloc(local_solvegrid, solveinfo->minimum * sizeof(char *));
		i = 0;
		while (local_solvegrid[i])
		{
			local_solvegrid[i] = (char *)ft_realloc(local_solvegrid, solveinfo->minimum * sizeof(char));
			ft_memset(local_solvegrid[i], '.', solveinfo->minimum * sizeof(char));
			i++;
		}
	}

	// while (local_solvegrid[i])
	// {
	// 	if (nextpiece(local_solvegrid) == 0)
	// 		return (0);
	// 	p = 0;
	// 	while (p < 3)
	// 	{
	// 		local_solvegrid[i][j] = '#';
	// 		local_solvegrid[i + pieces[grids->i].y[p]][j + pieces[grids->i].x[p]] = '#';
	// 		p++;
	// 	}
	// 	grids->i = -grids->i;
	// 	break;
	// }
	// i = 0;
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
	while (grids[i] && grids[i].i)
		i++;
	return (i);
}

int		solve_helper2(char **local_solvegrid, int pc)
{
	int i;

	for (i = 0; i < pc; i++)
	{
		if (grids[i].i > 0)
		{
			grids[i].i *= -1;
			// create solvegrid, breakout with correct solvegrid
			if (/*GRID WORKS CORRECTLY -- this will trigger on last nest*/ )
				return (1);
			else if (solve_helper2(local_solvegrid, pc))
				return (1);
			grids[i].i *= -1;
		}
		i++;
	}
	return (0);
}

// int		solve_helper(char **local_solvegrid, int pc)
// {
// 	int i;

// 	if (!pc)
// 		return (0);

// 	i = 0;
// 	while (local_solvegrid[i])
// 	{
// 		ft_memset(local_solvegrid[i], '.', solveinfo->minimum * sizeof(char));
// 		i++;
// 	}
// 	while ()
// 	{
// 		//We need to somehow recursively check the blocks
// 		// 1 - 2 - 3 - 4
// 		// 1 - 2 - 4 - 3
// 		// 1 - 3 - 2 - 4
// 		// 1 - 3 - 4 - 2
// 		// 1 - 4 - 2 - 3
// 		// 1 - 4 - 3 - 2
// 		// We need a while loop that has recursivity inside of it. It would go
// 		// until the end in each loop, switching to the next number and putting
// 		// that one in
// 		// int		fake_function(array2)
// 		// {
// 		// 	while (array[i])
// 		// 	{
// 		// 		if (i == SOMETHING IN ARRAY 2)
					
// 		// 		thisfunction(array2[i, i that was passed to this one])
// 		// 		i++;
// 		// 	}
// 		// }
// 		// 2 - 1 - 3 - 4
// 		// 2 - 1 - 4 - 3
// 		// 2 - 3 - 1 - 4
// 		// 2 - 3 - 4 - 1
// 		// 2 - 4 - 1 - 3
// 		// 2 - 4 - 3 - 1

// 	}
// 	return (solve_helper(local_solvegrid, pc - 1));


// 	// int i;
// 	// int maxj;
// 	// int maxi;
// 	// int j;
// 	// int p;

// 	// i = 0;
// 	// maxj = 0;
// 	// maxi = 0;
// 	// printf("123\n");
// 	// if (nextpiece() == 0)
// 	// 	return (0);
// 	// while (local_solvegrid[i])
// 	// {
// 	// 	j = 0;
// 	// 	while (local_solvegrid[i][j])
// 	// 	{
// 	// 		printf("here %c\n", local_solvegrid[i][j]);
// 	// 		if (local_solvegrid[i][j] == '.')
// 	// 			break ;
// 	// 		j++;
// 	// 	}
// 	// 	if (j == solveinfo->minimum)
// 	// 		i++;
// 	// 	break ;
// 	// }
// 	// printf("got here.\n");
// 	// p = 0;
// 	// while (p < 3)
// 	// {
// 	// 	local_solvegrid[i][j] = '#';
// 	// 	printf("Seg faulted after this.\n");
// 	// 	if (i + pieces[grids->i].y[p] > solveinfo->minimum || j + pieces[grids->i].x[p] > solveinfo->minimum)
// 	// 	{
// 	// 		if (local_solvegrid[i + pieces[grids->i].y[p]][j + pieces[grids->i].x[p]] == '.')
// 	// 			local_solvegrid[i + pieces[grids->i].y[p]][j + pieces[grids->i].x[p]] = '#';
// 	// 		else
// 	// 			return (0);
// 	// 	}
// 	// 	else
// 	// 		return (0);
// 	// 	printf("Before this\n");
// 	// 	p++;
// 	// }
// 	// grids->i = -grids->i;
// 	// i = 0;
// 	// printf("hi\n");
// 	// if (!solve_helper(local_solvegrid))
// 	// 	return (0);
// 	// return (1);
// }

int	notallused(void)
{
	int n;
	int i;

	n = 0;
	i = 0;
	while (grids[i])
	{
		if (grids[i].i > 0)
			n++;
		i++;
	}
	return (n);
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
