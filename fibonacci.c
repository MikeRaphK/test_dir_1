#include <stdio.h>
#include <time.h>

// Function to calculate the n-th Fibonacci term using recursion
int fib_rec(int n) {
    if (n <= 1) return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

// Function to calculate the n-th Fibonacci term using memoization
int fib_memo_helper(int n, int memo[]) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fib_memo_helper(n - 1, memo) + fib_memo_helper(n - 2, memo);
    return memo[n];
}

int fib_memo(int n) {
    int memo[n + 1];
    for (int i = 0; i <= n; i++) memo[i] = -1;
    return fib_memo_helper(n, memo);
}

// Function to calculate the n-th Fibonacci term using dynamic programming
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

    clock_t start, end;

    // Test fib_rec
    start = clock();
    printf("Fibonacci term %d (recursion): %d\n", n, fib_rec(n));
    end = clock();
    printf("Time taken (recursion): %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Test fib_memo
    start = clock();
    printf("Fibonacci term %d (memoization): %d\n", n, fib_memo(n));
    end = clock();
    printf("Time taken (memoization): %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Test fib_dp
    start = clock();
    printf("Fibonacci term %d (dynamic programming): %d\n", n, fib_dp(n));
    end = clock();
    printf("Time taken (dynamic programming): %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}