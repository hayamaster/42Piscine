/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:44:16 by juhakim           #+#    #+#             */
/*   Updated: 2023/01/16 23:26:30 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	reculsive(int idx, int val, int n, int arr[])
{
	int	i;
	int	c;

	if (idx == n)
	{
		i = 0;
		while (i < n)
		{
			c = arr[i] + '0';
			write(1, &c, 1);
			i++;
		}
		if (!(arr[idx - 1] == 9 && arr[0] == 10 - n))
			write(1, ", ", 2);
	}
	else
	{
		while (val < 11 - n + idx)
		{
			arr[idx] = val;
			reculsive(idx + 1, val + 1, n, arr);
			val++;
		}
	}
}

void	ft_print_combn(int n)
{
	int	arr[10];

	reculsive(0, 0, n, arr);
}
