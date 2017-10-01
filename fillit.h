/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:43:42 by asyed             #+#    #+#             */
/*   Updated: 2017/10/01 12:39:26 by asyed            ###   ########.fr       */
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
	int	minimum;
}						t_info;

void	file_reader(char *filename);
int		numofgrids(char	*buf);
void	perform_check(char *buf);
int		totalplaced(void);
int		nextpiece(void);
void	minimumset(int small_grids);
int		solve(void);


extern	t_grid	*grids;
extern	t_info	*solveinfo;
#endif