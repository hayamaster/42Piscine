/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:17:30 by juhakim           #+#    #+#             */
/*   Updated: 2023/01/19 13:55:02 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alphabet(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

char	upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char	lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

char	state_machine(char c, char prev)
{
	char	state;

	state = prev;
	if (ft_str_is_alphabet(c))
	{
		if (prev == '\0' || prev == 'D')
			state = 'A';
		else if (prev == 'A' || prev == 'B' || prev == 'G')
			state = 'B';
	}
	else if ((c >= '0' && c <= '9'))
		state = 'G';
	else
		state = 'D';
	return (state);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	state;
	char	prev;

	state = '\0';
	i = 0;
	while (*(str + i))
	{
		prev = state;
		state = state_machine(*(str + i), prev);
		if (prev == '\0' && state == 'A')
				*(str + i) = upper(*(str + i));
		if (prev == 'A' && state == 'B')
				*(str + i) = lower(*(str + i));
		if (prev == 'B' && state == 'B')
				*(str + i) = lower(*(str + i));
		if (prev == 'D' && state == 'A')
				*(str + i) = upper(*(str + i));
		if (prev == 'G' && state == 'B')
				*(str + i) = lower(*(str + i));
		i++;
	}
	return (str);
}
