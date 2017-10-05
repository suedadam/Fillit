/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 09:49:28 by asyed             #+#    #+#             */
/*   Updated: 2017/10/05 11:58:22 by asyed            ###   ########.fr       */
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
# define MAX(a,b) (((a)>(b))?(a):(b))

typedef	struct				s_grid
{
	uint8_t	i:5;//will hold value from 0-18 or 1-19å
} __attribute__((packed))	t_grid;

typedef struct				s_info
{
	int		minimum;
	char	*solvedgrid;
}							t_info;

typedef struct				s_pieces
{
	int		*x;
	int		*y;
}							t_pieces;

void	file_reader(char *filename);
int		numofgrids(char	*buf);
void	perform_check(char *buf);
int		solve(void);
int		what_type(int n, int *delta);
void	populate_struct(void);
int		totalplaced(void);
int		nextpiece(void);
void	minimumset(int small_grids);
int		solve(void);
int		solve_helper2(char **local_solvegrid, int spot);


extern	t_grid		*grids;
extern	t_info		*solveinfo;
extern	t_pieces	*pieces;

#endif