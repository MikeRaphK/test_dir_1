#include <stdio.h>
#include <time.h>

// Function to calculate Fibonacci term using recursion
int fib_rec(int n) {
    if (n <= 1) return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

// Function to calculate Fibonacci term using memoization
int fib_memo_helper(int n, int memo[]) {
    if (memo[n] != -1) return memo[n];
    if (n <= 1) return n;
    memo[n] = fib_memo_helper(n - 1, memo) + fib_memo_helper(n - 2, memo);
    return memo[n];
}

int fib_memo(int n) {
    int memo[n + 1];
    for (int i = 0; i <= n; i++) memo[i] = -1;
    return fib_memo_helper(n, memo);
}

// Function to calculate Fibonacci term using dynamic programming
int fib_dp(int n) {
    if (n <= 1) return n;
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n = 10;
    clock_t start;
    double duration;

    // Test recursive Fibonacci
    start = clock();
    printf("Fibonacci %d (Recursion): %d\n", n, fib_rec(n));
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Time taken by fib_rec: %f seconds\n", duration);

    // Test memoization Fibonacci
    start = clock();
    printf("Fibonacci %d (Memoization): %d\n", n, fib_memo(n));
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Time taken by fib_memo: %f seconds\n", duration);

    // Test dynamic programming Fibonacci
    start = clock();
    printf("Fibonacci %d (Dynamic Programming): %d\n", n, fib_dp(n));
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Time taken by fib_dp: %f seconds\n", duration);

    return 0;
}