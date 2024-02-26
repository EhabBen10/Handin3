#include <iostream>
#include <vector>
#include "MazeSolver.h"

int main() {
    std::vector<std::vector<char> > maze = {
        {' ', ' ', ' ', 'X', ' '},
        {' ', 'X', ' ', 'X', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', 'X', 'X', 'X', ' '},
        {' ', ' ', ' ', 'E', ' '}
    };

     if (findPath(maze, 0, 0)) {
        std::cout << "Sti til 'E' blev fundet!" << std::endl;
    } else {
        std::cout << "Ingen sti til 'E' blev fundet." << std::endl;
    }

     do 
    {
        std::cout << '\n' << "Press a key to continue...";
    } while (std::cin.get() != '\n');

    return 0;
