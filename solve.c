/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 10:03:27 by asyed             #+#    #+#             */
/*   Updated: 2017/09/29 11:34:17 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve(void)
{
	char	**solvegrid;

	solvegrid = (char **)ft_memalloc(solveinfo->minimum * sizeof(char *));
	*solvegrid = (char *)ft_memalloc(solveinfo->minimum * sizeof(char));
}
