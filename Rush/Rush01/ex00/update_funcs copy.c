/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhakim <juhakim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:25:13 by juhakim           #+#    #+#             */
/*   Updated: 2023/01/22 23:01:00 by juhakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	init_clue_array(char *clue_array, char *argv)
{
	int	clue_arr_idx;
	int	argv_idx;

	clue_arr_idx = 0;
	argv_idx = 0;
	while (*(argv + argv_idx))  // 인자로 받은 argv의 문자열을 처음부터 끝까지 돌음.
	{
		if (*(argv + argv_idx) >= '1' && *(argv + argv_idx) <= '9') // 만약 해당 인덱스 값이 숫자이면 
		{
			clue_array[clue_arr_idx] = *(argv + argv_idx);  // 단서 배열에 넣기
			clue_arr_idx++;      // 단서 배열 인덱스 증가
		}
		argv_idx++; // argv 인덱스 증가
	}
	clue_array[clue_arr_idx] = '\0';
	return ;
}

void	swap(char *data, int idx1, int idx2)
{
	int	temp;

	if (idx1 == idx2)
		return ;
	temp = data[idx1];
	data[idx1] = data[idx2];
	data[idx2] = temp;
}

void	init_grid_cases_array(char **grid_cases_array, char *data, int last_idx)
{
	int	data_idx;
	int	grid_cases_arr_idx;

	data_idx = 0;
	grid_cases_arr_idx = 0;
	if (last_idx == 1) // last_idx 가 감소되여 1이 되었을 때
	{
		while (grid_cases_array[grid_cases_arr_idx][0])    // 경우의 수 배열에 값이 없는 칸 전까지 인덱스 증가
			grid_cases_arr_idx++;
		while (data_idx < 4)    // data에 들어있는 경우의 수 배열에 넣기
		{
			grid_cases_array[grid_cases_arr_idx][data_idx] = data[data_idx];
			data_idx++;
		}
		return ;
	}
	while (data_idx < last_idx)
	{
		swap(data, data_idx, last_idx - 1); // 두 값을 스왑
		init_grid_cases_array(grid_cases_array, data, last_idx - 1); // last_idx를 감소시키며 재귀함수 호출
		swap(data, data_idx, last_idx - 1); // 두 값을 원상복귀
		data_idx++;
	}
}

// void	insert_val_cases_array(char **grid_cases_array, int grid_cases_arr_idx, char (data)[4], int (indexes)[4])
// {
// 	grid_cases_array[grid_cases_arr_idx][0] = data[indexes[0]];
// 	grid_cases_array[grid_cases_arr_idx][1] = data[indexes[1]];
// 	grid_cases_array[grid_cases_arr_idx][2] = data[indexes[2]];
// 	grid_cases_array[grid_cases_arr_idx][3] = data[indexes[3]];
// }

// void	init_grid_cases_array(char **grid_cases_array)
// {
// 	char	*data;
// 	int		indexes[4];
// 	int		grid_cases_arr_idx;

// 	data = "1234";
// 	grid_cases_arr_idx = 0;
// 	indexes[0] = 0;
// 	while (indexes[0] < 4)
// 	{
// 		indexes[1] = 0;
// 		while (indexes[1] < 4)
// 		{
// 			if (indexes[0] == indexes[1])
// 			{
// 				indexes[1]++;
// 				continue ;
// 			}
// 			indexes[2] = 0;
// 			while (indexes[2] < 4)
// 			{
// 				if (indexes[0] == indexes[2] || indexes[1] == indexes[2])
// 				{
// 					indexes[2]++;
// 					continue ;
// 				}
// 				indexes[3] = 0;
// 				while (indexes[3] < 4)
// 				{
// 					if (indexes[0] == indexes[3] || indexes[1] == indexes[3] || indexes[2] == indexes[3])
// 					{
// 						indexes[3]++;
// 						continue ;
// 					}
//                     insert_val_cases_array(grid_cases_array, grid_cases_arr_idx, data, indexes);
// 					grid_cases_arr_idx++;
// 					indexes[3]++;
// 				}
// 				indexes[2]++;
// 			}
// 			indexes[1]++;
// 		}
// 		indexes[0]++;
// 	}
// }

char	**get_new_array(int first_num, int second_num)  // 동적으로 할당된 새로운 2차 배열 생성
{
	char	**new_array;
	int		new_array_idx;

	new_array_idx = 0;
	new_array = (char **)malloc(sizeof(char *) * first_num);
	while (new_array_idx < first_num)
	{
		new_array[new_array_idx] = (char *)malloc(sizeof(char) * second_num);
		new_array_idx++;
	}
	return (new_array);
}


// void	update_grid_array(char **grid_array, char **grid_cases_array, char *clue_array)
// {
// 	int	idx1;
// 	int	idx2;
// 	int	idx3;
// 	int	idx4;

// 	idx1 = 0;
// 	while (idx1 < 24)
// 	{
// 		idx2 = 0;
// 		while (idx2 < 24)
// 		{
// 			idx3 = 0;
// 			while (idx3 < 24)
// 			{
// 				idx4 = 0;
// 				while (idx4 < 24)
// 				{
// 					if (!check_based_on_clue(grid_array, clue_array) && !check_based_on_overlap(grid_array, 1))
// 						return ;
// 					idx4++;
// 					grid_array[3] = grid_cases_array[idx4];
// 				}
// 				idx3++;
// 				grid_array[2] = grid_cases_array[idx3];
// 			}   
// 			idx2++;
// 			grid_array[1] = grid_cases_array[idx2];
// 		}
// 		idx1++;
// 		grid_array[0] = grid_cases_array[idx1];
// 	}
// }

int main()
{
    char imsy[40] = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
    char clue_array[16];
    char **grid_cases_array;
    char **grid_array;
    char    data[4] = "1234";
    
    // init_clue_array
    init_clue_array(clue_array, imsy);
    printf("%s\n", clue_array);

    // init_grid_cases_array
    grid_cases_array = get_new_array(24, 4); //동적할당 된 배열
    init_grid_cases_array(grid_cases_array, data, 4);
    // init_grid_cases_array(grid_cases_array);

    for(int i = 0; i < 24; i++)
        printf("%s\n", grid_cases_array[i]);

    // update_grid_array
    grid_array = get_new_array(4, 4);
    grid_array[0] = "1234";
    grid_array[1] = "1234";
    grid_array[2] = "1234";
    grid_array[3] = "1234";

    // update_grid_array(grid_array, grid_cases_array, clue_array);

    // for (int j = 0; j < 4; j++)
    // {
    //     printf("%s\n", grid_array[j]);
    // }
    return (0);
}
