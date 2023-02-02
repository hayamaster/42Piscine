/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:07:57 by juhakim           #+#    #+#             */
/*   Updated: 2023/01/31 22:56:17 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	long long	size;
	int			*arr;
	long long	i;

	size = max - min;
	if (min >= max)
	{
		arr = NULL;
		return (arr);
	}
	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
