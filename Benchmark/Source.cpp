//#include <stdio.h>
//#include <time.h>
//
//int main() {
//    int n = 20000000;  // Set the value of 'n' as needed
//
//    clock_t start_time, end_time;
//    double cpu_time_used;
//    start_time = clock();  // Record the starting time
//
//    int sum = 0;
//    for (int i = 0; i < n; ++i) {
//        ++sum;
//    }
//
//    end_time = clock();  // Record the ending time
//
//    // Calculate the CPU time used in seconds
//    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
//
//    printf("Sum: %d\n", sum);
//    printf("CPU time used: %f seconds\n", cpu_time_used);
//
//    return 0;
//}
