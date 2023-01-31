/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 03:52:44 by juhakim           #+#    #+#             */
/*   Updated: 2023/01/26 11:12:59 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int				size_s1;
	int				size_s2;
	unsigned int	i;

	if (n == 0)
		return (0);
	size_s1 = 0;
	size_s2 = 0;
	while (*(s1 + size_s1))
		size_s1++;
	while (*(s2 + size_s2))
		size_s2++;
	i = 0;
	while (i < n && *(s1 + i))
	{
		if (*(s1 + i) != *(s2 + i))
			return ((unsigned char) *(s1 + i) - (unsigned char) *(s2 + i));
		i++;
	}
	if (size_s1 == size_s2)
		return (0);
	if (i == n)
		i--;
	return ((unsigned char) *(s1 + i) - (unsigned char) *(s2 + i));
}
