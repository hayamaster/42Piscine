/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:30:27 by juhakim           #+#    #+#             */
/*   Updated: 2023/02/02 01:41:46 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	all_length(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			len++;
			j++;
		}
		j = 0;
		while (sep[j] && i < size - 1)
		{
			len++;
			j++;
		}
		i++;
	}
	return (len);
}

void	insert_val_arr(int size, char *arr, char **strs, char *sep)
{
	int	i;
	int	j;
	int	idx;

	i = 0;
	idx = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			arr[idx] = strs[i][j];
			idx++;
			j++;
		}
		j = 0;
		while (sep[j] && i < size - 1)
		{
			arr[idx] = sep[j];
			idx++;
			j++;
		}
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;
	int		total_len;

	if (size == 0)
	{
		arr = (char *)malloc(sizeof(char) * 1);
		*arr = 0;
		return (arr);
	}
	total_len = all_length(size, strs, sep);
	arr = (char *)malloc(sizeof(char) * total_len + 1);
	if (arr == NULL)
		return (0);
	insert_val_arr(size, arr, strs, sep);
	arr[total_len] = '\0';
	return (arr);
}
