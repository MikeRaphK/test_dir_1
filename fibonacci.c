#include <stdio.h>
#include <time.h>

// Recursive Fibonacci function
int fib_rec(int n) {
    if (n <= 1) return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

// Fibonacci function with memoization
int fib_memo_helper(int n, int *memo) {
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

    start = clock();
    printf("Fibonacci (Recursion): %d\n", fib_rec(n));
    end = clock();
    printf("Time taken (Recursion): %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    printf("Fibonacci (Memoization): %d\n", fib_memo(n));
    end = clock();
    printf("Time taken (Memoization): %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    printf("Fibonacci (Dynamic Programming): %d\n", fib_dp(n));
    end = clock();
    printf("Time taken (Dynamic Programming): %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}