/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 09:49:28 by asyed             #+#    #+#             */
/*   Updated: 2017/10/02 09:50:08 by asyed            ###   ########.fr       */
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
