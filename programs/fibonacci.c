#include <stdio.h>
#include <time.h>

// Recursive function to calculate n-th fibonacci number
int fib_rec(int n) {
    if (n <= 1) return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

// Memoization approach to calculate n-th fibonacci number
int fib_memo_helper(int n, int *memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fib_memo_helper(n - 1, memo) + fib_memo_helper(n - 2, memo);
    return memo[n];
}

int fib_memo(int n) {
    int memo[n+1];
    for (int i = 0; i <= n; i++) memo[i] = -1;
    return fib_memo_helper(n, memo);
}

// Dynamic programming approach to calculate n-th fibonacci number
int fib_dp(int n) {
    if (n <= 1) return n;
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}

int main() {
    int n = 10;
    clock_t start, end;
    double cpu_time_used;

    // Measure time for recursive
    start = clock();
    printf("Recursive: %d\n", fib_rec(n));
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by recursive: %f seconds\n", cpu_time_used);

    // Measure time for memoization
    start = clock();
    printf("Memoization: %d\n", fib_memo(n));
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by memoization: %f seconds\n", cpu_time_used);

    // Measure time for dynamic programming
    start = clock();
    printf("Dynamic Programming: %d\n", fib_dp(n));
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by dynamic programming: %f seconds\n", cpu_time_used);

    return 0;
}
