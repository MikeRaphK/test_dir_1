#include <stdio.h>
#include <time.h>

// Recursive Fibonacci function
int fib_rec(int n) {
    if (n <= 1) return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

// Memoization array
int memo[100];

// Memoized Fibonacci function
int fib_memo(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fib_memo(n - 1) + fib_memo(n - 2);
    return memo[n];
}

// Dynamic Programming Fibonacci function
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
    clock_t start, end;

    // Test recursive Fibonacci
    start = clock();
    printf("Fibonacci (recursive) of %d: %d\n", n, fib_rec(n));
    end = clock();
    printf("Time taken (recursive): %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Test memoized Fibonacci
    for (int i = 0; i <= n; i++) memo[i] = -1; // Initialize memoization array
    start = clock();
    printf("Fibonacci (memoized) of %d: %d\n", n, fib_memo(n));
    end = clock();
    printf("Time taken (memoized): %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Test dynamic programming Fibonacci
    start = clock();
    printf("Fibonacci (dynamic programming) of %d: %d\n", n, fib_dp(n));
    end = clock();
    printf("Time taken (dynamic programming): %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}