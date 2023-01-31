/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 06:11:54 by juhakim           #+#    #+#             */
/*   Updated: 2023/01/25 06:18:04 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_length(char *to_find)
{
	int	i;

	i = 0;
	while (*(to_find + i))
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	size;
	int	i;

	size = get_length(to_find);
	if (size == 0)
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			i = 0;
			while (*(to_find + i))
			{
				if (*(to_find + i) == *(str + i))
					i++;
				else
					break ;
			}
			if (i == size)
				return (str);
		}
		str++;
	}
	return (0);
}
