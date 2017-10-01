/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:13:07 by asyed             #+#    #+#             */
/*   Updated: 2017/09/29 11:34:10 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_pieces	*pieces;

void	add_pieces(int *x, int *y)
{
	int i;

	i = 0;
	while (pieces[i].x) // Verify this is okay.
	{
		i++;
	}
	pieces[i].x = x;
	pieces[i].y = y;
}

int *make_array(int x, int x2, int x3)
{
	int		*array;

	array = ft_memalloc(3 * sizeof(int));
	array[0] = x;
	array[1] = x2;
	array[2] = x3;
	return (array);  
}

void	populate_struct(void)
{
	pieces = (t_pieces *)ft_memalloc((20) * sizeof(t_pieces));
	add_pieces(make_array(1,0,1), make_array(0,1,1)); //1
	add_pieces(make_array(1,2,3), make_array(0,0,0)); //2
	add_pieces(make_array(0,0,0), make_array(1,2,3)); //3
	add_pieces(make_array(1,-1,0), make_array(0,1,1)); //4
	add_pieces(make_array(0,1,1), make_array(1,1,2)); //5
	add_pieces(make_array(1,1,2), make_array(0,1,1)); //6
	add_pieces(make_array(-1,0,-1), make_array(1,1,2)); //7
	add_pieces(make_array(1,2,0), make_array(0,0,1)); //8
	add_pieces(make_array(0,0,1), make_array(1,2,2)); //9
	add_pieces(make_array(-2,-1,0), make_array(1,1,1)); //10
	add_pieces(make_array(1,1,1), make_array(0,1,2)); //11
	add_pieces(make_array(1,2,2), make_array(0,0,1)); //12
	add_pieces(make_array(1,0,0), make_array(0,1,2)); //13
	add_pieces(make_array(0,1,2), make_array(1,1,1)); //14
	add_pieces(make_array(0,-1,0), make_array(1,2,2)); //15
	add_pieces(make_array(1,2,1), make_array(0,0,1)); //16
	add_pieces(make_array(0,1,0), make_array(1,1,2)); //17
	add_pieces(make_array(-1,0,1), make_array(-1,1,1)); //18
	add_pieces(make_array(-1,0,0), make_array(1,1,2)); //19
}

int		stage_three(int n, int delta, int row_delta, int col_delta)
{
	if (((((delta + n) % 5) - n % 5) == row_delta) && ((((delta + n) / 5) - (n / 5)) == col_delta))
		return (1);
	return (0);
}

int		what_type(int n, int *delta)
{
	int i;
	int j;

	i = 0;
	while (pieces[i].x) // Verify this is okay.
	{
		j = 0;
		while (j < 3)
		{
			if (!(stage_three(n, delta[j], pieces[i].x[j], pieces[i].y[j])))
				break;
			if (j == 2)
				return (i);
			j++;
		}
		i++;
	}
	ft_putstr("error\n");
	exit(3);
}
