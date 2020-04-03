#include "header.h"

int main(int ac, char *ag[])
{
	int **map;

	if (ac == 10)
	{
		ag++;
		map = create_map(ag);
		if (map != 0)
		{
			if (sudoku_solver(map) == 1)
				sudoku_print(map);
			else
				write (1, "Error\n", 6);
		}
		else
			write (1, "Error\n", 6);
	}

	else
		write (1, "Error\n", 6);

	return 0;
}