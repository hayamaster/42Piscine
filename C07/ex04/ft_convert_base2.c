/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:22:03 by juhakim           #+#    #+#             */
/*   Updated: 2023/01/31 15:56:59 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_base(char *base, int base_size)
{
	int	i;
	int	j;

	if (!*base || base_size == 1)
		return (0);
	i = 0;
	while (*(base + i))
	{
		j = i + 1;
		while (*(base + j))
		{
			if (*(base + i) == *(base + j))
				return (0);
			j++;
		}
		if (*(base + i) == '+' || *(base + i) == '-')
			return (0);
		else if ((8 < *(base + i) && *(base + i) < 14) || *(base + i) == 32)
			return (0);
		i++;
	}
	return (1);
}

int	extract_number(char *str, char *base, int base_size, int buho)
{
	long long	num;
	int			base_idx;

	num = 0;
	while (*str)
	{
		base_idx = 0;
		while (*(base + base_idx))
		{
			if (*str == *(base + base_idx))
			{
				num = num * base_size + base_idx;
				break ;
			}
			base_idx++;
		}
		if (base_idx == base_size)
			break ;
		str++;
	}
	return ((int)(buho * num));
}

int	make_atoi(char *nbr, char *base, int base_size)
{
	int		buho;
	char	*str;

	str = nbr;
	buho = 1;
	while ((8 < *str && *str < 14) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			buho *= -1;
		str++;
	}
	return (extract_number(str, base, base_size, buho));
}

int	get_length_converted_num(int num_decimal, int base_size)
{
	int			length;
	long long	num;

	num = (long long)num_decimal;
	length = 0;
	if (num < 0)
	{
		length++;
		num *= -1;
	}
	while (num >= base_size)
	{
		length++;
		num /= base_size;
	}
	length++;
	return (length);
}

char	*change_base_to(long long num, char *base, int base_size)
{
	char	*arr;
	int		arr_size;
	int		i;

	arr_size = get_length_converted_num(num, base_size);
	arr = (char *)malloc(sizeof(char) * arr_size + 1);
	if (arr == NULL)
		return (0);
	arr[arr_size] = '\0';
	if (num < 0)
	{
		arr[0] = '-';
		num = -num;
	}
	i = arr_size - 1;
	while (i > 0)
	{
		if (arr[i - 1] == '-')
			break ;
		arr[i] = base[num % base_size];
		num /= base_size;
		i--;
	}
	arr[i] = base[num];
	return (arr);
}
