#include <stdio.h>

int isValid(int grid[9][9], int row, int col, int num)
{
    for (int x = 0; x < 9; x++)
        if (grid[row][x] == num)
            return 0;
    for (int x = 0; x < 9; x++)
        if (grid[x][col] == num)
            return 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + row - row%3][j + col-col%3] == num)
                return 0;
    return 1;
}
int solveSudoku(int grid[9][9], int row, int col)
{
    if (row == 9)
        return 1;
    if (col == 9)
    {
        row++;
        col = 0;
    }
    if (grid[row][col] > 0)
        return solveSudoku(grid, row, col + 1);
    for (int num = 1; num <= 9; num++)
    { 
        if (isValid(grid, row, col, num))
        {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1))
                return 1;
        }
        grid[row][col] = 0;
    }
    return 0;
}
int main()
{
    int grid[9][9];
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            scanf("%d",&grid[i][j]);

    if (solveSudoku(grid, 0, 0))
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                printf("%d ", grid[i][j]);
            printf("\n");
        }
    return 0;
}