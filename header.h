#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdlib.h>

int is_valid(int ac, char **ag);
int **create_map(char **ag);

int sudoku_solver(int **map);
int is_null(int **map, int *row, int *col);

int roww(int **map, int row, int num);
int column(int **map, int col, int num);
int square(int **map, int row, int col, int num);

int is_safe(int **map, int row, int col, int num);

void sudoku_print(int **map);

#endif