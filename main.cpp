#include <iostream>

#define Empty 0
#define N 9
//#define N so6

unsigned short grid[N][N] = {};

bool isValid(unsigned short row, unsigned short col, unsigned short num)
{
    for(unsigned short i = 0; i < N; i++)
        if(grid[i][col] == num || grid[row][i] == num)
            return false;

    if(N == 9){
        unsigned short boxStartRow = row - row % 3,
              boxStartCol = col - col % 3;

        for(unsigned short row = 0; row < 3; row++)
            for(unsigned short col = 0; col < 3; col++)
                if(grid[row + boxStartRow][col + boxStartCol] == num)
                    return false;
    }else if(N == 6){
        unsigned short boxStartRow = row - row % 2,
              boxStartCol = col - col % 3;

        for(unsigned short row = 0; row < 2; row++)
            for(unsigned short col = 0; col < 3; col++)
                if(grid[row + boxStartRow][col + boxStartCol] == num)
                    return false;
    }

    return true;
}

bool FindEmptyLocation(unsigned short &row, unsigned short &col)
{
    for(row = 0; row < N; row++)
        for(col = 0; col < N; col++)
            if(grid[row][col] == Empty)
                return true;
    return false;
}

bool SolveSudoku(){
    unsigned short row, col;

    if(!FindEmptyLocation(row, col))
        return true;

    for(unsigned short num = 1; num <= N; num++){
        if(isValid(row, col, num)){
            grid[row][col] = num;

            if(SolveSudoku())
                return true;

            grid[row][col] = Empty;
        }
    }

    return false;
}

void getInput()
{
    FILE *inFile = fopen("inFile.in", "r");

    for(unsigned short row = 0; row < N; row++)
        for(unsigned short col = 0; col < N; col++)
            fscanf(inFile, "%u", &grid[row][col]);
}

void printGrid()
{
    for(unsigned short row = 0; row < N; row++){
        for(unsigned short col = 0; col < N; col++)
                printf("%i ", grid[row][col]);
        printf("\n");
    }
}

int main()
{
    getInput();

    if(SolveSudoku())
        printGrid();
    else
        printf("No solution exists");
}

/*
0 0 0 2 6 0 7 0 1
6 8 0 0 7 0 0 9 0
1 9 0 0 0 4 5 0 0
8 2 0 1 0 0 0 4 0
0 0 4 6 0 2 9 0 0
0 5 0 0 0 3 0 2 8
0 0 9 3 0 0 0 7 4
0 4 0 0 5 0 0 3 6
7 0 3 0 1 8 0 0 0

0 2 0 0 0 0 0 0 0
0 0 0 6 0 0 0 0 3
0 7 4 0 8 0 0 0 0
0 0 0 0 0 3 0 0 2
0 8 0 0 4 0 0 1 0
6 0 0 5 0 0 0 0 0
0 0 0 0 1 0 7 8 0
5 0 0 0 0 9 0 0 0
0 0 0 0 0 0 0 4 0

0 3 0 0 0 1
2 0 0 0 0 0
0 2 0 0 1 0
0 0 0 0 0 6
0 0 4 6 5 0
5 0 2 0 4 0
*/
