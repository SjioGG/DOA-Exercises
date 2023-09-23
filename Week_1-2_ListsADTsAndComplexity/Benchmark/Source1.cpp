//#include <stdio.h>
//#include <time.h>
//
//int main() {
//    int n = 20000; // replace with the desired value of 'n'
//
//    clock_t start_time, end_time;
//    double cpu_time_used;
//
//    start_time = clock(); // record the starting time
//
//    int sum = 0;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            ++sum;
//        }
//    }
//
//    end_time = clock(); // record the ending time
//
//    // calculate the cpu time used in seconds
//    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
//
//    printf("sum: %d\n", sum);
//    printf("cpu time used: %f seconds\n", cpu_time_used);
//
//    return 0;
//}
