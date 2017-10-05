/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:37:50 by asyed             #+#    #+#             */
/*   Updated: 2017/10/05 14:46:16 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		populate_struct();
		file_reader(argv[1]);
		// printf("MAIN GRIDS: :%d, %d, %d, %d\n", grids[1].i, grids[2].i, grids[3].i, grids[4].i);
	}
	else
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putstr(" source_file\n");
	}
}
