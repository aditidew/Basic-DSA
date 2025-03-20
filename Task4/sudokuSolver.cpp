// Placeholder for Sudoku Solver program

#include <iostream>
#include <vector>

#define N 9

bool isValid(std::vector<std::vector<int>> &grid, int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num ||
            grid[row - row % 3 + x / 3][col - col % 3 + x % 3] == num)
            return false;
    }
    return true;
}

bool solveSudoku(std::vector<std::vector<int>> &grid, int row, int col) {
    if (row == N - 1 && col == N)
        return true;

    if (col == N) {
        row++;
        col = 0;
    }

    if (grid[row][col] != 0)
        return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= N; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

void printGrid(const std::vector<std::vector<int>> &grid) {
    for (const auto &row : grid) {
        for (const auto &num : row)
            std::cout << num << " ";
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> grid = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (solveSudoku(grid, 0, 0))
        printGrid(grid);
    else
        std::cout << "No solution exists" << std::endl;

    return 0;
}

