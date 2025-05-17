#include <stdio.h>
#include <time.h>

int fib_rec(int n) {
    if (n <= 1)
        return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

int fib_memo(int n, int* memo) {
    if (memo[n] != -1)
        return memo[n];
    if (n <= 1)
        return n;
    memo[n] = fib_memo(n - 1, memo) + fib_memo(n - 2, memo);
    return memo[n];
}

int fib_dp(int n) {
    if (n <= 1)
        return n;
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

int main() {
    int n = 10;
    clock_t start;
    double duration;

    start = clock();
    printf("Fibonacci (Recursion) of %d: %d\n", n, fib_rec(n));
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Time taken (Recursion): %f seconds\n", duration);

    int memo[n + 1];
    for (int i = 0; i <= n; i++)
        memo[i] = -1;

    start = clock();
    printf("Fibonacci (Memoization) of %d: %d\n", n, fib_memo(n, memo));
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Time taken (Memoization): %f seconds\n", duration);

    start = clock();
    printf("Fibonacci (Dynamic Programming) of %d: %d\n", n, fib_dp(n));
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Time taken (Dynamic Programming): %f seconds\n", duration);

    return 0;
}