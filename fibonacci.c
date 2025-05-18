#include <stdio.h>
#include <time.h>

// Recursive Fibonacci function
int fib_rec(int n) {
    if (n <= 1)
        return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

// Fibonacci function using memoization
int fib_memo_helper(int n, int* memo) {
    if (n <= 1)
        return n;
    if (memo[n] != -1)
        return memo[n];
    memo[n] = fib_memo_helper(n - 1, memo) + fib_memo_helper(n - 2, memo);
    return memo[n];
}

int fib_memo(int n) {
    int memo[n + 1];
    for (int i = 0; i <= n; i++)
        memo[i] = -1;
    return fib_memo_helper(n, memo);
}

// Dynamic programming Fibonacci function
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

    // Time the recursive function
    start = clock();
    printf("Fibonacci of %d (recursion): %d\n", n, fib_rec(n));
    end = clock();
    printf("Time taken by fib_rec: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Time the memoization function
    start = clock();
    printf("Fibonacci of %d (memoization): %d\n", n, fib_memo(n));
    end = clock();
    printf("Time taken by fib_memo: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Time the dynamic programming function
    start = clock();
    printf("Fibonacci of %d (dynamic programming): %d\n", n, fib_dp(n));
    end = clock();
    printf("Time taken by fib_dp: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}