/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:28:17 by juhakim           #+#    #+#             */
/*   Updated: 2023/01/30 11:24:34 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_res(int *queen)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = *(queen + i) + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	check_condition(int *queen, int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (queen[i] == col)
			return (0);
		if (abs(row - i) == abs(col - queen[i]))
			return (0);
		i++;
	}
	return (1);
}

void	recursive_queen(int *queen, int *count, int row)
{
	int	col;

	if (row == 10)
	{
		(*count)++;
		print_res(queen);
		return ;
	}
	else
	{
		col = 0;
		while (col < 10)
		{
			if (check_condition(queen, row, col))
			{
				queen[row] = col;
				recursive_queen(queen, count, row + 1);
			}
			col++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	queen[10];
	int	count;
	int	row;

	row = 0;
	count = 0;
	recursive_queen(queen, &count, row);
	return (count);
}
