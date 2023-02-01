/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:17:15 by juhakim           #+#    #+#             */
/*   Updated: 2023/01/27 08:14:40 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_length(char *base)
{
	int	size;

	size = 0;
	while (*(base + size))
		size++;
	return (size);
}

int	is_duplicated_plus_minus_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (*(base + i))
	{
		j = i + 1;
		while (*(base + j))
		{
			if (*(base + i) == *(base + j))
				return (1);
			j++;
		}
		if (*(base + i) == '+' || *(base + i) == '-')
			return (1);
		i++;
	}
	return (0);
}

void	print_nbr(long long nbr, char *base, int base_size)
{
	if (nbr < base_size)
	{
		write(1, &base[nbr], 1);
		return ;
	}
	print_nbr((nbr / base_size), base, base_size);
	write(1, &base[nbr % base_size], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_size;
	long long	num;

	base_size = get_length(base);
	if (!*base || base_size == 1 || is_duplicated_plus_minus_base(base))
		return ;
	num = (long long)nbr;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	print_nbr(num, base, base_size);
}

/*
int	main(int argc, char **argv)
{
	if (argc < 3)
		return (0);
	ft_putnbr_base(-2147483648, argv[2]);
}
*/
