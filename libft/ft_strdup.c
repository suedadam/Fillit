/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 03:17:10 by dpearson          #+#    #+#             */
/*   Updated: 2017/09/20 03:17:10 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char const *s1)
{
	int		i;
	int		length;
	char	*dup;

	i = 0;
	while (*(s1 + i))
		i++;
	length = i + 1;
	if ((dup = (char*)malloc(i + 1)))
	{
		i = 0;
		while (i < length)
		{
			*(dup + i) = *(s1 + i);
			i++;
		}
		return (dup);
	}
	else
		return (NULL);
}
