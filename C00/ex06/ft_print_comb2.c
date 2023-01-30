/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.cc                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:45:53 by juhakim           #+#    #+#             */
/*   Updated: 2023/01/15 21:14:52 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int i, int j)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = i / 10 + 48;
	b = i % 10 + 48;
	c = j / 10 + 48;
	d = j % 10 + 48;
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < 99)
	{
		while (j < 100)
		{
			ft_putchar(i, j);
			if (i == 98 && j == 99)
				break ;
			write(1, ", ", 2);
			j++;
		}
		i++;
		j = i + 1;
	}
}
