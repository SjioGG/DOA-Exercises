#include <stdio.h>
#include <time.h>
#include <math.h>
#include "Stack.h"

int myMethod(int N)
{
    Stack stack;
    for (int i = 0; i < N; i++)
    {
        stack.push(69);
    }
    std::cout << "Stack: ";
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << " ";
    }
    std::cout << std::endl;
    return N;
}

int main(void) {
	int N, msec = 0;
	printf("Input N:");
	scanf_s("%d", &N);
	clock_t before = clock();
	myMethod(N);
	clock_t duration = clock() - before;
	msec = duration * 1000 / CLOCKS_PER_SEC;
	printf("duration in msec: %d", msec);
	return 0;
}