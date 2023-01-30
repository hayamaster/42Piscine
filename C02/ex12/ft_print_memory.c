/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 02:34:24 by juhakim           #+#    #+#             */
/*   Updated: 2023/01/25 03:44:24 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	third_addr(unsigned char *str, unsigned int i, unsigned int size)
{
	unsigned int	idx;

	idx = 0;
	while (idx < 16)
	{
		if (idx == size - i)
			break ;
		if (*(str + idx) < 32 || *(str + idx) > 126)
			write(1, ".", 1);
		else
			write(1, (str + idx), 1);
		idx++;
	}
}

void	second_addr(unsigned char *str, unsigned int i, unsigned int size)
{
	char				*hexa;
	unsigned int		idx;

	hexa = "0123456789abcdef";
	write(1, ": ", 2);
	idx = 0;
	while (idx < 16)
	{
		if (idx >= size - i)
			write(1, "  ", 2);
		else
		{
			write(1, &hexa[*(str + idx) / 16], 1);
			write(1, &hexa[*(str + idx) % 16], 1);
		}
		if (idx % 2 == 1)
			write(1, " ", 1);
		idx++;
	}
}

void	first_addr(unsigned long long addr)
{
	char	*hexa;
	char	first_arr[16];
	int		i;

	hexa = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		if (addr < 16)
		{
			first_arr[i] = hexa[addr];
			i++;
			while (i < 16)
				first_arr[i++] = '0';
			break ;
		}
		first_arr[i] = hexa[addr % 16];
		addr = addr / 16;
		i++;
	}
	while (i > 0)
	{
		--i;
		write(1, &first_arr[i], 1);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	if (size == 0)
		return (addr);
	i = 0;
	while (i < size)
	{
		first_addr((unsigned long long)(addr + i));
		second_addr((unsigned char *)(addr + i), i, size);
		third_addr((unsigned char *)(addr + i), i, size);
		write(1, "\n", 1);
		i = i + 16;
	}
	return (addr);
}
