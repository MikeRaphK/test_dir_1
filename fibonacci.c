#include <stdio.h>
#include <time.h>

// Recursive Fibonacci function
int fib_rec(int n) {
    if (n <= 1) return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

// Memoization for Fibonacci
int memo[100];
int fib_memo(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fib_memo(n - 1) + fib_memo(n - 2);
    return memo[n];
}

// Dynamic Programming for Fibonacci
int fib_dp(int n) {
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

    // Test recursive Fibonacci
    start = clock();
    printf("Fib_rec(%d) = %d\n", n, fib_rec(n));
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Time taken by fib_rec: %f seconds\n", duration);

    // Test memoized Fibonacci
    for (int i = 0; i <= n; i++) memo[i] = -1; // Reset memoization
    start = clock();
    printf("Fib_memo(%d) = %d\n", n, fib_memo(n));
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Time taken by fib_memo: %f seconds\n", duration);

    // Test dynamic programming Fibonacci
    start = clock();
    printf("Fib_dp(%d) = %d\n", n, fib_dp(n));
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Time taken by fib_dp: %f seconds\n", duration);

    return 0;
}