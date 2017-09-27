/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:42:03 by asyed             #+#    #+#             */
/*   Updated: 2017/09/27 12:04:51 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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
		//Process data in buffer.
	}
}
