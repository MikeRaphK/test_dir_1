#include <stdio.h>
#include <time.h>
#include "fibonacci.c"

void test_fibonacci() {
    int n = 10;
    clock_t start, end;

    start = clock();
    printf("Fibonacci (recursion): %d\n", fib_rec(n));
    end = clock();
    printf("Time taken (recursion): %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    printf("Fibonacci (memoization): %d\n", fib_memo(n));
    end = clock();
    printf("Time taken (memoization): %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    printf("Fibonacci (dynamic programming): %d\n", fib_dp(n));
    end = clock();
    printf("Time taken (dynamic programming): %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    test_fibonacci();
    return 0;
}