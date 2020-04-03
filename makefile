NAME = compile
FLAG = -Wall -Wextra -Werror
SRC = check.c funcs.c main.c
OBJ = check.o funcs.o main.o
HEAD = header.h

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAG) $(OBJ) -o sudoku

clean:
	/bin/rm -f $(OBJ)