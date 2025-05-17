#include <stdio.h>
#include <time.h>
#include "fibonacci.c"

void test_fibonacci() {
    int n = 10;
    clock_t start, end;

    start = clock();
    fib_rec(n);
    end = clock();
    printf("Test: Time taken by fib_rec for n=10: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    fib_memo(n);
    end = clock();
    printf("Test: Time taken by fib_memo for n=10: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    fib_dp(n);
    end = clock();
    printf("Test: Time taken by fib_dp for n=10: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    test_fibonacci();
    return 0;
}