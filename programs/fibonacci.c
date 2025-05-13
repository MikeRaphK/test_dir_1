#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the n-th Fibonacci term using recursion
int fib_rec(int n) {
    if (n <= 1) return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

// Function to calculate the n-th Fibonacci term using memoization
int fib_memo_helper(int n, int *memo) {
    if (memo[n] != -1) return memo[n];
    if (n <= 1) return n;
    memo[n] = fib_memo_helper(n - 1, memo) + fib_memo_helper(n - 2, memo);
    return memo[n];
}

int fib_memo(int n) {
    int *memo = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) memo[i] = -1;
    int result = fib_memo_helper(n, memo);
    free(memo);
    return result;
}

// Function to calculate the n-th Fibonacci term using dynamic programming
int fib_dp(int n) {
    int *dp = (int *)malloc((n + 1) * sizeof(int));
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int result = dp[n];
    free(dp);
    return result;
}

int main() {
    int n = 10;
    clock_t start, end;

    start = clock();
    printf("Fibonacci (Recursion) for %d: %d\n", n, fib_rec(n));
    end = clock();
    printf("Time taken (Recursion): %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    printf("Fibonacci (Memoization) for %d: %d\n", n, fib_memo(n));
    end = clock();
    printf("Time taken (Memoization): %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    printf("Fibonacci (Dynamic Programming) for %d: %d\n", n, fib_dp(n));
    end = clock();
    printf("Time taken (Dynamic Programming): %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}