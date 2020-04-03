#include "header.h"

int is_null(int **map, int *row, int *col)
{
	while (*row < 9)
	{
		while (*col < 9)
		{
			if (map[*row][*col] == 0)
				return (1);
			(*col)++;
		}
		*col = 0;
		(*row)++;
	}
	return(0);
}

int row_column(int **map, int row, int col, int num)
{
	int i = 0;
	while (i < 9)
	{
		if (map[row][i] == num)
			return (0);
		i++;
	}

	int j = 0;
	while (j < 9)
	{
		if (map[j][col] == num)
			return (0);
		j++;
	}

	return(1);
}

int square(int **map, int row_st, int col_st, int num)
{
	int row = 0;
	int col = 0;
	while (row < 3)
	{
		while (col < 3)
		{
			if (map[row + row_st][col_st + col] == num)
				return (0);
			col++;
		}
		col = 0;
		row++;
	}
	return(1);
} 

int is_safe(int **map, int row, int col, int num)
{
	return (row_column(map, row, col, num) &&
			square(map, row-row%3, col-col%3, num) &&
			map[row][col] == 0);
}