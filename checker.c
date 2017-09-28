/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 14:40:17 by dpearson          #+#    #+#             */
/*   Updated: 2017/09/27 14:40:17 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		numofgrids(char	*buf)
{
	int	i;

	i = 1;
	while (*buf)
		if (*buf++ == '\n' && *((buf + 1) == '\n'))
			i++;
	return (i);
}

int		stage_three(int n, int delta, int row_delta, int col_delta)
{
	if (((delta / 5) - (n / 5) == row_delta) && (((delta % 5) == (n % 5)) == col_delta))
		return (1);
	return (0);
}

void	stage_two(int n, int *delta)
{
	if (stage_three(n, delta[0], 1, 0))			// X,Y (if directly to right) == 1, 2, 4, 6, 8, 11, 12, 13, 16
		if (stage_three(n, delta[1], 1, 0))		// X,Y [2] (if directly to right) == 2, 8, 12, 16

	if (stage_three(n, delta[0], 0, 1))			// X,Y (if directly under) == 3, 5, 9, 14, 15, 17
		
	if (stage_three(n, delta[0], -1, -1))		// X,Y (if -1,-1): 7, 18, 19

	if (stage_three(n, delta, -2, -1))			// It is a 10 or invalid



}

void	stage_one(int n, char *buf)
{
	int delta[3];
	int i;
	int j;

	i = 0;
	j = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			delta[j] = i;
			j++;
		}
		i++;
	}
	stage_two(n, delta);
	// n/5 gets me the row 
	// n % 5 gets me the column

}

int		error_check(char c, int i, int hash)
{
	if ((c != '\n') || (c != '.') || (c != '#'))
		return (0);
	if ((!(i % 5)) && (c != '\n'))
		return (0);
	if ((i == 21) && ((i != '\n') || (hash > 4)))
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
		if (i == 21)
		{
			i = -1;
			hash = 0;
		}
		if (*buf = '#' && (hash++))
			if (hash == 1)
				stage_one(i + 1, *buf);
		i++;
		buf++;
	}
}

int		perform_check(char *buf)
{
	int i;
	int small_grids;
	i = 0;
	small_grids = numofgrids(buf);
	grids = (t_grid *)ft_memalloc((small_grids + 1) * sizeof(struct s_grid *));
		// Grid population ends with grids[end] = NULL;
	if (!grids)
	{
		ft_putstr("Error in allocating small grids!");
		exit(2);
	}
	if (!convert_buf(buf)) // will be using global variable grids. If there is an issue, returns 0
	{
		ft_putstr("error\n");
		exit(3);
	}
	printf("We malloc'd %d grids for a size of %lu bytes\n", small_grids, small_grids * sizeof(struct s_grid *));	

}
