/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:43:42 by asyed             #+#    #+#             */
/*   Updated: 2017/09/27 13:15:09 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include "libft.h"

# define BUF_SIZE 2048

typedef	struct	s_grid
{
	char	type;
	char	x;
	char	y;
}				t_grid;

// void	ft_putchar(char c);
// void	ft_putstr(char *str);
void	file_reader(char *filename);
int		numofgrids(char	*buf);

extern	t_grid	*grids;
#endif