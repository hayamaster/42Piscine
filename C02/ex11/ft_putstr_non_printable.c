/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:40:01 by juhakim           #+#    #+#             */
/*   Updated: 2023/01/19 16:35:38 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*hexa;

	hexa = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		if (str[i] < ' ' || str[i] > 126)
		{
			write(1, "\\", 1);
			write(1, &hexa[(unsigned char) str[i] / 16], 1);
			write(1, &hexa[(unsigned char) str[i] % 16], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
