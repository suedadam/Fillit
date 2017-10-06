/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 09:49:28 by asyed             #+#    #+#             */
/*   Updated: 2017/10/05 19:03:10 by asyed            ###   ########.fr       */
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

# define BUF_SIZE 2
# define MAX(a,b) (((a)>(b))?(a):(b))

typedef struct				s_grid
{
	uint8_t	i:5;
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

int							main(int argc, char *argv[]);
void						file_reader(char *filename);
int							struct_add(int j);
void						minimumset(int small_grids);
void						solve(void);
int							totalpieces(void);
int							piece_fits(char **local_solvegrid, int x, int y,
							int spot);
void						piece_set(char **local_solvegrid, int x, int y,
							int spot, char c);
int							solve_helper(char **local_solvegrid, int spot);
void						add_pieces(int *x, int *y);
int							*make_array(int x, int x2, int x3);
void						populate_struct(void);
int							stage_three(int n, int delta, int row_delta,
							int col_delta);
int							what_type(int n, int *delta);
int							numofgrids(char	*buf);
void						stage_one(int n, char *buf);
int							error_check(char c, int i, int hash);
int							convert_buf(char *buf);
void						perform_check(char *buf);

extern	t_grid		*g_grids;
extern	t_info		*g_solveinfo;
extern	t_pieces	*g_pieces;

#endif
