/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:14:14 by juhakim           #+#    #+#             */
/*   Updated: 2023/01/31 20:40:36 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_charset(char c, char *charset)
{
	int	idx;

	idx = 0;
	while (*(charset + idx))
	{
		if (c == *(charset + idx))
			return (1);
		idx++;
	}
	return (0);
}

int	get_arr_size(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*(str + i))
	{
		if (check_charset(*(str + i), charset))
		{
			i++;
			continue ;
		}
		count++;
		while (*(str + i) && !check_charset(*(str + i), charset))
			i++;
	}
	return (count);
}

int	get_arr_row_size(char *str, char *charset)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (check_charset(*(str + i), charset))
			return (i);
		i++;
	}
	return (i);
}

char	**make_arr(char **arr, char *str, char *charset, int size)
{
	int		i;
	int		j;
	int		arr_row_size;

	i = 0;
	while (*str && i < size)
	{
		if (check_charset(*str, charset))
		{
			str++;
			continue ;
		}
		arr_row_size = get_arr_row_size(str, charset);
		arr[i] = (char *)malloc(sizeof(char) * arr_row_size + 1);
		j = 0;
		while (*str && !check_charset(*str, charset))
		{
			arr[i][j] = *str;
			j++;
			str++;
		}
		arr[i][j] = '\0';
		i++;
	}
	return (arr);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		size;

	size = get_arr_size(str, charset);
	arr = (char **)malloc(sizeof(char *) * size + 1);
	if (arr == NULL)
		return (0);
	arr[size] = 0;
	return (make_arr(arr, str, charset, size));
}
