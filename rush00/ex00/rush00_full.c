/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00_full.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:48:42 by juhakim           #+#    #+#             */
/*   Updated: 2023/01/14 13:48:45 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	frist_line(int w)
{
	int	wcount;

	wcount = 1;
	while (wcount <= w)
	{
		if (wcount == 1)
			write(1, "/", 1);
		else if (wcount == w)
			write(1, "\\", 1);
		else
			write(1, "*", 1);
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
			write(1, "\", 1);
		else if (wcount == w)
			write(1, "/", 1);
		else
			write(1, "*", 1);
		wcount ++;
	}
}

void	between_line(int w)
{
	int	wcount;

	wcount = 1;
	while (wcount <= w)
	{
		if (wcount == 1 | wcount == w)
			write(1, "*", 1);
		else
			write(1, " ", 1);
		wcount ++;
	}
}

void	rush(int w, int h)
{
	int	hcount;

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
		write(1, "\n", 1);
	}
}

int main()
{
	rush(5,6);
	return 0;
}