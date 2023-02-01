/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 08:15:35 by juhakim           #+#    #+#             */
/*   Updated: 2023/01/28 13:31:26 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_len(char *base)
{
	int	size;

	size = 0;
	while (*(base + size))
		size++;
	return (size);
}

int	is_duplicated_and_plus_minus_base(char *base)
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
		else if ((8 < *(base + i) && *(base + i) < 14) || *(base + i) == 32)
			return (1);
		i++;
	}
	return (0);
}

int	extract_number(char *str, char *base, int base_size)
{
	int	num;
	int	base_idx;

	num = 0;
	while (*str)
	{
		base_idx = 0;
		while (*(base + base_idx))
		{
			if (*str == *(base + base_idx))
			{
				num = num * base_size;
				num += base_idx;
				break ;
			}
			base_idx++;
		}
		if (base_idx == base_size)
			break ;
		str++;
	}
	return (num);
}

int	make_atoi(char *str, char *base, int base_size)
{
	int	buho;

	buho = 1;
	while (*str)
	{
		if ((8 < *str && *str < 14) || *str == 32)
			str++;
		else
			break ;
	}
	while (*str)
	{
		if (*str == '+' || *str == '-')
		{
			if (*str == '-')
				buho *= -1;
			str++;
		}
		else
			break ;
	}
	return (buho * extract_number(str, base, base_size));
}

int	ft_atoi_base(char *str, char *base)
{
	int			base_size;

	base_size = get_len(base);
	if (!*base || base_size == 1 || is_duplicated_and_plus_minus_base(base))
		return (0);
	return (make_atoi(str, base, base_size));
}

/*#include <stdio.h>
int main (int argc, char **argv)
{
	if (argc < 3)
		return (0);
	printf("%d\n",ft_atoi_base(argv[1], argv[2]));
}
*/
