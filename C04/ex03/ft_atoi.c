/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:14:29 by juhakim           #+#    #+#             */
/*   Updated: 2023/01/28 13:22:17 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	extract_num(char *str)
{
	int	num;

	num = 0;
	while (*str)
	{
		if ('0' > *str || *str > '9')
			break ;
		num = num * 10;
		num += *str - '0';
		str++;
	}
	return (num);
}

int	ft_atoi(char *str)
{
	int		buho;

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
		}
		else if ('0' <= *str && *str <= '9')
			break ;
		else
			return (0);
		str++;
	}
	return (buho * extract_num(str));
}

/*
#include <stdio.h>
int	main()
{
	int	num;
	char	*imsy = "   --- +--+12353ak214";

	num = ft_atoi(imsy);
	printf("%d\n", num);
}*/
