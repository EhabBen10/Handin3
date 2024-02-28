#include <iostream>
#include <vector>

const int ROWS = 5;
const int COLS = 5;
const char START = 'S';
const char END = 'E';
const char WALL = 'X';
const char PATH = '.';
const char VISITED = 'V';
std::vector<std::pair<int, int>> path;

bool findPath(char maze[ROWS][COLS], int x, int y)
{
    // If the current position is out of bounds or is a wall, return false
    if (x < 0 ||
        y < 0 ||
        x >= ROWS ||
        y >= COLS ||
        maze[x][y] == WALL ||
        maze[x][y] == VISITED)
    {
        return false;
    }

    // If the current position is the end, return true
    if (maze[x][y] == END)
    {
        return true;
    }

    // Mark the current position as visited by turning it into a wall
    path.push_back(std::make_pair(x, y));
    maze[x][y] = VISITED;

    // Try to solve the maze by moving in each direction from the current position
    if (findPath(maze, x - 1, y) ||
        findPath(maze, x + 1, y) ||
        findPath(maze, x, y - 1) ||
        findPath(maze, x, y + 1))
    {
        return true;
    }

    // If none of the moves solved the maze, return false
    return false;
}

int main()
{
    char maze[ROWS][COLS] = {
        {WALL, WALL, WALL, WALL, WALL},
        {WALL, PATH, PATH, PATH, WALL},
        {WALL, PATH, WALL, PATH, WALL},
        {WALL, PATH, WALL, PATH, WALL},
        {WALL, END, WALL, WALL, WALL}};

    if (findPath(maze, 1, 1))
    {
        std::cout << "Maze solved! and the path is: " << std::endl;
        for (int i = 0; i < path.size(); i++)
        {
            std::cout << path[i].first << ", " << path[i].second << std::endl;
        }
    }
    else
    {
        std::cout << "Maze not solvable." << std::endl;
    }

    return 0;
}