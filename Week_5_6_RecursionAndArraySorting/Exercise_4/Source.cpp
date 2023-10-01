#include <iostream>

const int ROWS = 5;
const int COLS = 5;

bool searchMaze(char maze[ROWS][COLS], int row, int col)
{
    // Check if we have reached the end of the maze
    if (maze[row][col] == 'E')
    {
        return true;
    }

    // Check if the current position is a wall or has already been visited
    if (maze[row][col] == 'X' || maze[row][col] == '.')
    {
        return false;
    }

    // Mark the current position as visited
    maze[row][col] = '.';

    // Recursively search in all four directions
    if (searchMaze(maze, row - 1, col) || // Up
        searchMaze(maze, row + 1, col) || // Down
        searchMaze(maze, row, col - 1) || // Left
        searchMaze(maze, row, col + 1))
    { // Right
        return true;
    }

    // If no path was found, mark the current position as unvisited
    maze[row][col] = ' ';

    return false;
}

int main()
{
    char maze[ROWS][COLS] = {
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', ' ', ' ', 'X'},
        {'X', ' ', ' ', ' ', 'X'},
        {'X', ' ', ' ', ' ', ' '},
        {'X', 'E', 'X', 'X', ' '}};

    if (searchMaze(maze, 4, 4)) // zero indexed
    {
        std::cout << "Path found!" << std::endl;
    }
    else
    {
        std::cout << "No path found." << std::endl;
    }

    // Print the maze
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            std::cout << maze[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}