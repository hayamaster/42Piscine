/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 01:48:28 by juhakim           #+#    #+#             */
/*   Updated: 2023/02/02 20:52:17 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

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
	write(1, "\n", 1);
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

void	ft_show_tab(struct s_stock_str *par)
{
	int		i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size);
		ft_putstr(par[i].copy);
		i++;
	}
}
