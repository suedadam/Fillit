/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:42:03 by asyed             #+#    #+#             */
/*   Updated: 2017/10/05 19:08:24 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Lets have a seperate function to read the file from, this is
** opening in read only mode.
*/

void	file_reader(char *filename)
{
	int		fd;
	int		r;
	int		count;
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
			buf = (char *)ft_realloc(buf, (count + BUF_SIZE + 1) *
				sizeof(char));
	}
	if (r < 0)
	{
		ft_putstr("error\n");
		exit(4);
	}
	buf[count] = '\0';
	perform_check(buf);
}
