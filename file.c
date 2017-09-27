/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:42:03 by asyed             #+#    #+#             */
/*   Updated: 2017/09/27 12:37:05 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

t_grid	*grids;

/*
** Lets have a seperate function to read the file from, this is 
** opening in read only mode.
*/
void	file_reader(char *filename)
{
	int		fd;
	int		r;
	int		small_grids;
	char	buf[BUF_SIZE + 1];

	fd = open(filename, O_RDONLY);
	while ((r = read(fd, buf, BUF_SIZE)))
	{
		buf[r] = '\0';
		printf("%s\n", buf);
		//Process data in buffer.
	}
	small_grids = numofgrids(buf);
	// grids = (t_grid *)ft_memalloc(small_grids * sizeof(struct s_grid *));
	grids = (t_grid *)calloc(small_grids, sizeof(struct s_grid *));
	if (!grids)
	{
		ft_putstr("Error in allocating small grids!");
		exit(2);
	}
	printf("We malloc'd %d grids for a size of %lu bytes\n", small_grids, small_grids * sizeof(struct s_grid *));
}

int		numofgrids(char	*buf)
{
	int	i;

	i = 1;
	while (*buf && *buf != '\n')
		if (*buf++ == ' ')
			i++;
	return (i);
}