/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:50:37 by juhakim           #+#    #+#             */
/*   Updated: 2023/02/02 07:09:32 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (*(str + size))
		size++;
	return (size);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		size;
	int		idx;

	size = ft_strlen(src);
	dup = (char *)malloc(sizeof(char) * (size + 1));
	if (dup == NULL)
		return (0);
	idx = 0;
	while (idx < size)
	{
		*(dup + idx) = *(src + idx);
		idx++;
	}
	*(dup + idx) = '\0';
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*arr;

	arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (arr == NULL)
		return (arr);
	i = 0;
	while (i < ac)
	{
		arr[i].size = ft_strlen(av[i]);
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	arr[i].str = 0;
	return (arr);
}
