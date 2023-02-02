/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beomlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:35:02 by beomlee           #+#    #+#             */
/*   Updated: 2023/01/14 15:57:23 by beomlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char input);

void	frist_line(int w)
{
	int	wcount;

	wcount = 1;
	while (wcount <= w)
	{
		if (wcount == 1)
		{
			ft_putchar('A');
		}
		else if (wcount == w)
		{
			ft_putchar('C');
		}
		else
		{
			ft_putchar('B');
		}
		wcount ++;
	}
}

void	end_line(int w)
{
	int	wcount;

	wcount = 1;
	while (wcount <= w)
	{
		if (wcount == 1)
		{
			ft_putchar('C');
		}
		else if (wcount == w)
		{
			ft_putchar('A');
		}
		else
		{
			ft_putchar('B');
		}
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
			ft_putchar('B');
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
		if (hcount == 1)
			frist_line(w);
		else if (hcount == h)
			end_line(w);
		else
			between_line(w);
		hcount++;
		ft_putchar('\n');
	}
}
