#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fib_rec(int n) {
    if (n <= 1) return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

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

int fib_dp(int n) {
    if (n <= 1) return n;
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
    printf("Fibonacci Recursion: %d\n", fib_rec(n));
    end = clock();
    printf("Time taken by fib_rec: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    printf("Fibonacci Memoization: %d\n", fib_memo(n));
    end = clock();
    printf("Time taken by fib_memo: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    printf("Fibonacci Dynamic Programming: %d\n", fib_dp(n));
    end = clock();
    printf("Time taken by fib_dp: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}