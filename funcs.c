#include "header.h"

int **create_map(char **ag)
{
	int i, j = 0;
	int **map;
	
	map = (int**)malloc(sizeof(int*) * 9);

	while (i < 9)
	{
		map[i] = (int*)malloc(sizeof(int) * 9);
		i++;
	}

	i = 0;
	while (i < 9)
	{
		while (j < 9)
		{
			if (**ag == '.')
				map[i][j] = 0;
			else if (**ag >= '1' && **ag <= '9')
				map[i][j] = **ag - 48;
			else
				return (0);
			j++;
			(*ag)++;
		}
		j = 0;
		ag++;
		i++;
	}	
	return(map);
}

int 	sudoku_solver(int **map)
{
	int row = 0;
	int col = 0;
	int guess = 1;

	if (!is_null(map, &row, &col))
		return (1);

	while (guess <= 9)
		{
		if (is_safe(map, row, col, guess))
		{
			map[row][col] = guess;
			if (sudoku_solver(map))
				return (1);
			map[row][col] = 0;	
		}
		guess++;
	}
	return (0);
}

void sudoku_print(int **map)
{
	int j = 0;
	int i = 0;
	char symbol;

	while (i < 9)
	{
		while (j < 9)
		{
			symbol = (map[i][j] + '0');
			write (1, &symbol, 1);
			if (j != 8)
				write (1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}