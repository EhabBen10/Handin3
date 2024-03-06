#pragma once
#include <iostream>

using namespace std;

class Triangle
{
public:
    void printstars(int m) // prints m stars on 1 row and goes 1 line down
    {
        for (int i = 0; i < m; ++i)
        {
            cout << '*';
        }
        cout << endl;
    }

    void triangle(int m, int n)
    {
        // base case
        if (m > n) // m m� ikke v�re st�rre end n
        {
            return;
        }

        printstars(m);

        // recursive case
        triangle(m + 1, n);
        printstars(m);
        return;
    }
};
