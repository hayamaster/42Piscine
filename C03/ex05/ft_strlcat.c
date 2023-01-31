/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 06:20:07 by juhakim           #+#    #+#             */
/*   Updated: 2023/01/26 10:03:33 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	get_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = get_len(dest);
	src_len = get_len(src);
	if (size == 0)
		return (src_len);
	if (size < dest_len)
		return (src_len + size);
	i = dest_len;
	while ((i < size - 1) && *src)
	{
		*(dest + i) = *src;
		i++;
		src++;
	}
	*(dest + i) = '\0';
	return (dest_len + src_len);
}

//#include <stdio.h>
//int main()
//{
//	char dest[100] = "hello";
//	char *src = "good morning";
//	printf ("\nsize is : %d\n", ft_strlcat(dest, src, 0));
//	printf("%s\n", dest);
//	printf ("\nsize is : %d\n", ft_strlcat(dest, src, 5));
//	printf("%s\n", dest);
	//printf("\nsize is : %d\n", ft_strlcat(dest, src, 7));
	//printf("%s\n", dest);
//	printf("\nsize is : %d\n", ft_strlcat(dest, src, 100));
//	printf("%s\n", dest);
//}
