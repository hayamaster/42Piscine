/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:00:00 by donglee2          #+#    #+#             */
/*   Updated: 2023/01/29 22:52:37 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	check_atoi(char *str)
{
	long long	num;
	int			i;
	int			sign;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\n' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (('0' <= str[i] && str[i] <= '9') && str[i] != 0)
	{
		num = 10 * num + str[i] - '0';
		i++;
	}
	if (sign == -1 || str[i] == '.')
		return (-1);
	else
		return (num);
}

int	main(int argc, char *argv[])
{
	int		fd;
	int		file_size;
	char	buf[1000];

	if (argc <= 1 || 4 <= argc)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	fd = open("numbers.dict.txt", O_RDONLY);
	if (fd < 0)
	{
		write(2, "Dict Error\n", 11);
		return (0);
	}
	file_size = read(fd, buf, 999);
	buf[file_size] = '\0';
	if (check_atoi(argv[1]) == -1)
		write (1, "Error\n", 6);
	else
		write(1, "Sorry. This is incomplete program", 33);
	close(fd);
	return (0);
}
