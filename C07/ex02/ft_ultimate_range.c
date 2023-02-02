/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:27:07 by juhakim           #+#    #+#             */
/*   Updated: 2023/01/31 22:56:43 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long	size;
	long long	i;
	int			*range2;

	size = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	range2 = (int *)malloc(sizeof(int) * size);
	if (!range2)
		return (-1);
	while (i < size)
	{
		range2[i] = min + i;
		i++;
	}
	*range = range2;
	return (size);
}
