#include <iostream>
using namespace std;

void triangle(int m, int n)
{
    if (m > n)
    {
        return; // Base case: stop recursion when m is greater than n
    }

    for (int i = 0; i < m; i++)
    {
        cout << "*";
    }
    cout << endl;

    triangle(m + 1, n); // Recursively call triangle with m+1

    for (int i = 0; i < m; i++)
    {
        cout << "*";
    }
    cout << endl;
}

int main()
{
    triangle(4, 6);
    return 0;
}
