/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:43:42 by asyed             #+#    #+#             */
/*   Updated: 2017/09/29 11:34:17 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include "libft.h"
# include <stdint.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define BUF_SIZE 2

typedef	struct			s_grid
{
	uint8_t	i:5; //will hold value from 0-18 or 1-19 
} __attribute__((packed)) t_grid;

typedef struct 			s_info
{
	int		minimum;
	char	*solvedgrid;
}						t_info;

typedef struct 			s_pieces
{
	int		*x;
	int		*y;
}						t_pieces;

void	file_reader(char *filename);
int		numofgrids(char	*buf);
void	perform_check(char *buf);
void	solve(void);
int	what_type(int n, int *delta);

extern	t_grid		*grids;
extern	t_info		*solveinfo;
extern	t_pieces	*pieces;
#endif