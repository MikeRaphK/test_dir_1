#include <stdio.h>
#include <time.h>

// Recursive Fibonacci function
int fib_rec(int n) {
    if (n <= 1) return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

// Memoization Fibonacci function
int fib_memo_helper(int n, int* memo) {
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
    int fib[n + 1];
    fib[0] = 0; fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

int main() {
    int n = 10;
    clock_t start, end;

    // Testing fib_rec
    start = clock();
    printf("fib_rec(%d) = %d\n", n, fib_rec(n));
    end = clock();
    printf("Time taken by fib_rec: %lf seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    // Testing fib_memo
    start = clock();
    printf("fib_memo(%d) = %d\n", n, fib_memo(n));
    end = clock();
    printf("Time taken by fib_memo: %lf seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    // Testing fib_dp
    start = clock();
    printf("fib_dp(%d) = %d\n", n, fib_dp(n));
    end = clock();
    printf("Time taken by fib_dp: %lf seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    return 0;
}