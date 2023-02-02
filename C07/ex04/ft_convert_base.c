/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:08:44 by juhakim           #+#    #+#             */
/*   Updated: 2023/01/31 15:57:30 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_base(char *base, int base_size);
int		make_atoi(char *nbr, char *base, int base_size);
char	*change_base_to(long long num, char *base, int base_size);

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (*(str + size))
		size++;
	return (size);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			base_len1;
	int			base_len2;
	long long	num_decimal;

	base_len1 = ft_strlen(base_from);
	base_len2 = ft_strlen(base_to);
	if (!check_base(base_from, base_len1) || !check_base(base_to, base_len2))
		return (0);
	num_decimal = (long long)make_atoi(nbr, base_from, base_len1);
	return (change_base_to(num_decimal, base_to, base_len2));
}
