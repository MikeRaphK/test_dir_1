#include <stdio.h>
#include <time.h>

int fib_rec(int n) {
    if (n <= 1)
        return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

int fib_memo(int n, int *memo) {
    if (n <= 1)
        return n;
    if (memo[n] != -1)
        return memo[n];
    memo[n] = fib_memo(n - 1, memo) + fib_memo(n - 2, memo);
    return memo[n];
}

int fib_dp(int n) {
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

    // Testing fib_rec
    start = clock();
    printf("fib_rec(%d) = %d\n", n, fib_rec(n));
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("fib_rec took %f seconds\n", duration);

    // Testing fib_memo
    int memo[n + 1];
    for (int i = 0; i <= n; i++) 
        memo[i] = -1;
    start = clock();
    printf("fib_memo(%d) = %d\n", n, fib_memo(n, memo));
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("fib_memo took %f seconds\n", duration);

    // Testing fib_dp
    start = clock();
    printf("fib_dp(%d) = %d\n", n, fib_dp(n));
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("fib_dp took %f seconds\n", duration);

    return 0;
}