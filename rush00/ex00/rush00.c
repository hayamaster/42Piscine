/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beomlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:48:31 by beomlee           #+#    #+#             */
/*   Updated: 2023/01/14 15:56:21 by beomlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char input);

void	frist_end_line(int w)
{
	int	wcount;

	wcount = 1;
	while (wcount <= w)
	{
		if (wcount == 1 || wcount == w)
			ft_putchar('o');
		else
			ft_putchar('-');
		wcount ++;
	}
}

void	between_line(int w)
{
	int	wcount;

	wcount = 1;
	while (wcount <= w)
	{
		if (wcount == 1 || wcount == w)
			ft_putchar('|');
		else
			ft_putchar(' ');
		wcount ++;
	}
}

void	rush(int w, int h)
{
	int	hcount;

	if (w < 0 || h < 0)
		return ;
		hcount = 1;
	while (hcount <= h)
	{
		if (hcount == 1 || hcount == h)
			frist_end_line(w);
		else
			between_line(w);
		hcount++;
		ft_putchar('\n');
	}
}
