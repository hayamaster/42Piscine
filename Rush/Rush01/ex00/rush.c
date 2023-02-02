/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honyi <honyi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:25:37 by honyi             #+#    #+#             */
/*   Updated: 2023/01/22 20:44:02 by honyi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_based_on_clue(char (*grid_array)[5], char *clue_array);
int		check_based_on_overlap(char (*grid_array)[5], int box_idx);
void	update_grid_array(char (*grid_array)[5], char (*grid_cases_array)[5]);

int	rush(char *clue_array, char (*grid_array)[5], \
	char (*grid_cases_array)[5])
{
	int	is_passed_checks;
	int	first_box_idx;

	is_passed_checks = 0;
	first_box_idx = 0;
	if (check_based_on_clue(grid_array, clue_array) == 1)
		is_passed_checks = 1;
	else if (check_based_on_overlap(grid_array, first_box_idx) == 1)
		is_passed_checks = 1;
	if (is_passed_checks == 0)
	{
		update_grid_array(grid_array, grid_cases_array);
	}
	/* TODO: 업데이트 마지막 조건, 경우의 수 배열의 마지막 인덱스의 값이 `4321`이 아님 */
	return (is_passed_checks);
}
