/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_on_overlap_funcs.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honyi <honyi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:57:31 by yujpark           #+#    #+#             */
/*   Updated: 2023/01/22 21:44:03 by yujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_based_on_overlap(char (*grid_array)[5], int box_idx) //행, 열 중복 검사
{
	int	col; //세로(열)
	int	row; //가로(행)
	int	is_overlapped;
	int	accum;

	col = box_idx / 4;
	row = box_idx % 4;
	is_overlapped = 0;
	accum = 0;
	while (accum < 4)
	{
		if (accum != row && grid_array[col][accum] == grid_array[col][row]) //검사 대상의 행에 중복되는 숫자가 있는지 체크
			is_overlapped = 1; //중복되면 is_overlapped값 1로 설정
		if (accum != col && grid_array[accum][row] == grid_array[col][row]) //검사 대상의 열에 중복되는 숫자가 있는지 체크
			is_overlapped = 1; //중복되면 is_overlapped값 1로 설정
		accum++;
	}
	if (is_overlapped == 0 && box_idx < 15) //중복된 값이 발견되지 않았을 경우
	{
		check_based_on_overlap(grid_array, box_idx + 1); //다음 인덱스도 확인
		return (0);
	}
	else //중복된 값을 발견했거나 인덱스를 모두 돌았을 경우
		return (is_overlapped); //그대로 is_overlapped 리턴
}
