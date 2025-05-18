#include <stdio.h>
#include <time.h>

int fib_rec(int n) {
    if (n <= 1) return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

int fib_memo(int n, int memo[]) {
    if (memo[n] != -1) return memo[n];
    if (n <= 1) return n;
    memo[n] = fib_memo(n - 1, memo) + fib_memo(n - 2, memo);
    return memo[n];
}

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
    printf("Fibonacci using recursion: %d\n", fib_rec(n));
    end = clock();
    printf("Time taken by fib_rec: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    
    int memo[n + 1];
    for (int i = 0; i <= n; i++) memo[i] = -1;
    
    start = clock();
    printf("Fibonacci using memoization: %d\n", fib_memo(n, memo));
    end = clock();
    printf("Time taken by fib_memo: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    
    start = clock();
    printf("Fibonacci using dynamic programming: %d\n", fib_dp(n));
    end = clock();
    printf("Time taken by fib_dp: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    
    return 0;
}