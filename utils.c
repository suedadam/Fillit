/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 09:49:28 by asyed             #+#    #+#             */
/*   Updated: 2017/10/05 13:47:35 by asyed            ###   ########.fr       */
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
