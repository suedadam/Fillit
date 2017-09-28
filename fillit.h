/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:43:42 by asyed             #+#    #+#             */
/*   Updated: 2017/09/28 14:14:38 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include "libft.h"

# define BUF_SIZE 2

typedef	struct			s_grid
{
	uint8_t	i:5; //will hold value from 0-18 or 1-19 
} __attribute__((packed)) t_grid;

void	file_reader(char *filename);
int		numofgrids(char	*buf);

extern	t_grid	*grids;
#endif