/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:13:52 by juhakim           #+#    #+#             */
/*   Updated: 2023/01/30 16:18:50 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_length(char *src)
{
	int	i;

	i = 0;
	while (*(src + i))
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		size;
	int		idx;

	size = get_length(src);
	dup = (char *)malloc(sizeof(char) * size + 1);
	if (dup == NULL)
		return (0);
	idx = 0;
	while (idx < size)
	{
		*(dup + idx) = *(src + idx);
		idx++;
	}
	*(dup + idx) = 0;
	return (dup);
}
