/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reculsive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:53:10 by juhakim           #+#    #+#             */
/*   Updated: 2023/01/28 18:08:46 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	num;

	if (nb == 0 && power == 0)
		return (1);
	if (power == 0)
		return (1);
	if (nb == 0 || power < 0)
		return (0);
	num = nb * ft_recursive_power(nb, power - 1);
	return (num);
}

/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_recursive_power(14, 0));
}*/
