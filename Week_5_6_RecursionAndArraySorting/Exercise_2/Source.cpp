#include <iostream>

void printStars(int n)
{
    if (n == 0)
    {
        return;
    }
    std::cout << "*";
    printStars(n - 1);
}

void triangle(int m, int n)
{
    if (m > n)
    {
        return;
    }
    printStars(m);
    std::cout << std::endl;
    triangle(m + 1, n);
    printStars(m);
    std::cout << std::endl;
}

int main()
{
    triangle(4, 6);
    return 0;
}
