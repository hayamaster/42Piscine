/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honyi <honyi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:56:44 by honyi             #+#    #+#             */
/*   Updated: 2023/01/22 20:19:28 by honyi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	init_clue_array(char *clue_array);
void	update_grid_array(char (*grid_array)[5]);
void	init_grid_cases_array(char (*grid_cases_array)[5]);
int		rush(char *clue_array, char (*grid_array)[5], \
	char (*grid_cases_array)[5]);

int	is_valid_input(int argc, char **argv, int size_of_axis)
{
	char	char_size_of_axis;
	int		iteration;
	int		char_counter;

	if (argc != 2)
		return (0);
	iteration = 0;
	char_size_of_axis = size_of_axis + '0';
	char_counter = 0;
	while (*(*(argv + 1) + iteration))
	{
		if (*(*(argv + 1) + iteration) < '1')
		{
			if (*(*(argv + 1) + iteration) != ' ')
				return (0);
		}
		else if (*(*(argv + 1) + iteration) > char_size_of_axis)
			return (0);
		else
			char_counter++;
		iteration++;
	}
	if (char_counter > 16)
		return (0);
	return (1);
}

void	print_err(void)
{
	char	*err;

	err = "Error\n";
	write(2, err, sizeof(err));
}

/* `size_of_axis` 매개변수 추가: 반복문 돌 때 하드코딩 방지 */
void	print_fin_grid(char (*grid_array)[5], int size_of_axis)
{
	int	row_idx;
	int	col_idx;

	row_idx = 0;
	while (row_idx < size_of_axis)
	{
		col_idx = 0;
		while (col_idx < size_of_axis)
		{
			write(1, *(grid_array + row_idx) + col_idx, 1);
			if (col_idx < 3)
				write(1, " ", 1);
			col_idx++;
		}
		write(1, "\n", 1);
		row_idx++;
	}
}

int	main(int argc, char *argv[])
{
	int		size_of_axis;
	char	grid_array[4][5];
	char	clue_array[17];
	char	grid_cases_array[24][5];

	size_of_axis = 4;
	if (is_valid_input(argc, argv, size_of_axis) == 0)
	{
		print_err();
		return (1);
	}
	/* TODO: Call incomplete functions */
	// init_clue_array(clue_array);
	// update_grid_array(grid_array);
	// init_grid_cases_array(grid_cases_array);
	if (rush(clue_array, grid_array, grid_cases_array) == 1)
	{
		print_err();
		return (1);
	}
	print_fin_grid(grid_array, size_of_axis);
	return (0);
}
