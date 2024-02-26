#include <iostream>
#include <vector>
#include "MazeSolver.h"

const int ROWS = 5;  // Antal rækker i labyrinten
const int COLS = 5;  // Antal kolonner i labyrinten


    bool findPath(std::vector<std::vector<char> > maze, int row, int col) {
        // Hvis vi er uden for labyrinten eller på en 'X' position skal der returnes false
        if (row < 0 || col < 0 || row >= ROWS || col >= COLS || maze[row][col] == 'X') {
            return false;
        }

        // Hvis vi når 'E', returner true
        if (maze[row][col] == 'E') {
            return true;
        }

        // Marker den aktuelle position som besøgt
        maze[row][col] = 'V';  // 'V' kan være en marker for besøgte steder

        // forsøg at bevæge sig op, ned, venstre og højre
        if (findPath(maze, row - 1, col) || findPath(maze, row + 1, col) ||
            findPath(maze, row, col - 1) || findPath(maze, row, col + 1)) {
            return true;
        }

        // Hvis ingen af ​​de fire retninger fører til 'E', marker positionen som ikke en del af stien
        maze[row][col] = '.';

        return false;
    }