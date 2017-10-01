/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:03:47 by asyed             #+#    #+#             */
/*   Updated: 2017/10/01 13:04:26 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	minimumset(int small_grids)
{
	int i;

	i = 0;
	while (i < small_grids)
	{
		if ((i * i) >= (small_grids * small_grids))
			break;
		i++;
	}
	solveinfo->minimum = i;
}
