#include <stdio.h>
#include <time.h>

// Recursive Fibonacci function
int fib_rec(int n) {
    if (n <= 1) return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

// Memoization Fibonacci function
int fib_memo_helper(int n, int *memo) {
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

// Dynamic Programming Fibonacci function
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

    start = clock();
    printf("Fibonacci (Recursion) of %d: %d\n", n, fib_rec(n));
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Time taken by fib_rec: %f seconds\n", duration);

    start = clock();
    printf("Fibonacci (Memoization) of %d: %d\n", n, fib_memo(n));
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Time taken by fib_memo: %f seconds\n", duration);

    start = clock();
    printf("Fibonacci (Dynamic Programming) of %d: %d\n", n, fib_dp(n));
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Time taken by fib_dp: %f seconds\n", duration);

    return 0;
}