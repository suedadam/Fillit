/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:42:03 by asyed             #+#    #+#             */
/*   Updated: 2017/09/27 15:38:47 by asyed            ###   ########.fr       */
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
	int		count;
	int		small_grids;
	char	*buf;

	fd = open(filename, O_RDONLY);
	count = 0;

	buf = (char *)ft_memalloc((BUF_SIZE + 1) * sizeof(char));
	if (!buf)
		exit(2);

	while ((r = read(fd, &buf[count], BUF_SIZE)) > 0)
	{
		count += r;
		if (r == BUF_SIZE)
			buf = (char *)ft_realloc(buf, (count + 1) * sizeof(char));
	}
	if (r < 0)
		exit(4);
	buf[count] = '\0';
	printf("(%d)\n%s\n", count, buf);
	small_grids = numofgrids(buf);
	grids = (t_grid *)ft_memalloc(small_grids * sizeof(struct s_grid *));
	if (!grids)
	{
		ft_putstr("Error in allocating small grids!");
		exit(2);
	}
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