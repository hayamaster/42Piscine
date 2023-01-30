/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:16:50 by juhakim           #+#    #+#             */
/*   Updated: 2023/01/17 05:45:22 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(int nb, int size)
{
	char	n;

	while (nb / 10)
	{
		n = nb / size + '0';
		write(1, &n, 1);
		nb %= size;
		size /= 10;
		while ((nb == 0 && size > 1) || (nb != 0 && (nb / size) == 0))
		{
			write(1, "0", 1);
			size /= 10;
		}
	}
	n = nb + '0';
	write(1, &n, 1);
}

int	for_size(int nb)
{
	int	i;

	i = 1;
	while (nb / 10)
	{
		nb = nb / 10;
		i = i * 10;
	}
	return (i);
}

void	ft_putnbr(int nb)
{
	int	size;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	size = for_size(nb);
	putchar(nb, size);
}
