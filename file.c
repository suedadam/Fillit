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
	char	buf[BUF_SIZE + 1];

	fd = open(filename, O_RDONLY);
	while ((r = read(fd, buf, BUF_SIZE)))
	{
		buf[r] = '\0';
		printf("%s\n", buf);
	}
	perform_check(buf);
}