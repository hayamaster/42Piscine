/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:41:24 by juhakim           #+#    #+#             */
/*   Updated: 2023/01/30 11:46:57 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	num;

	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	if (nb == 0)
		return (0);
	num = 1;
	while (power > 0)
	{
		num *= nb;
		power--;
	}
	return (num);
}

/*
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_iterative_power(3031, 0));
}*/
