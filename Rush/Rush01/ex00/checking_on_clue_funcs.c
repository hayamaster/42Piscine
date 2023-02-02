/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_on_clue_funcs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honyi <honyi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:22:56 by yujpark           #+#    #+#             */
/*   Updated: 2023/01/22 21:31:33 by honyi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_based_on_clue(char (*grid_array)[5], char *clue_array)
{
	int	is_overlapped;
	int	count;
	int	flag;

	count = 0;
	while (count < 16)
	{
		if (count / 4 == 0)
			flag = check_colup(grid_array, clue_array, count);
		else if (count / 4 == 1)
			flag = check_coldown(grid_array, clue_array, count);
		else if (count / 4 == 2)
			flag = check_rowleft(grid_array, clue_array, count);
		else
			flag = check_rowright(grid_array, clue_array, count);
		if (flag == 1)
			return (flag);
		else
			count ++;
	}
	return (flag);
}

int	check_colup(char (*grid_array)[5], char	*clue_array, int standard)
{
	int	i;
	int	count;
	int	idx;
	int	max;

	i = 1;
	count = 1;
	standard = idx % 4;
	max = grid_array[0][standard];
	while (i < 4)
	{
		if (max < grid_array[i][standard]) //인덱스가 max값보다 값이 크면
		{
			max = grid_array[i][standard];
			count ++; //count값을 1씩 증가
		}
		i++;
	}
	if (count == clue_array[standard]) //clue값과 count값이 일치하는 경우는
		return (0);
	else
		return (1);
}

int check_rowleft(char (*grid_array)[5], char *clue_array, int standard)
{
	int	i;
	int	count;
	int	idx;
	int	max;

	i = 1;
	count = 1;
	standard = idx % 4;
	max = grid_array[standard][0];
	while (i < 4)
	{
		if (max < grid_array[standard][i])
		{
			max = grid_array[standard][i];
			count ++;
		}
		i++;
	}
	if (count == clue_array[standard])
		return (0);
	else
		return (1);
}

int	check_coldown(char (*grid_array)[5], char *clue_array, int standard)
{
	int	i;
	int	count;
	int	idx;
	int	max;

	i = 2;
	count = 1;
	standard = idx % 4;
	max = grid_array[3][standard];
	while (i > -1)
	{
		if (max < grid_array[i][standard])
		{
			max = grid_array[i][standard];
			count ++;
		}
		i--;
	}
	if (count == clue_array[standard])
		return (0);
	else
		return (1);
}

int	check_rowright(char (*grid_array)[5], char *clue_array, int standard)
{
	int	i;
	int	count;
	int	idx;
	int	max;

	i = 2;
	count = 1;
	standard = idx % 4;
	max = grid_array[standard][3];
	while (i > -1)
	{
		if (max < grid_array[standard][i])
		{
			max = grid_array[standard][i];
			count ++;
		}
		i--;
	}
	if (count == clue_array[standard])
		return (0);
	else
		return (1);
}
