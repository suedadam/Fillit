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

t_pieces	*pieces;

void	add_piece(int *x, int *y)
{
	int i;

	i = 0;
	while (pieces[i])
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
	int i;

	i = 20;
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

void	what_type(int n, int pos)
{

}
