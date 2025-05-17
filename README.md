# test_dir_1
This is a sample patch.

This is another sample patch.
# Fibonacci Functions

This repository now includes an implementation of Fibonacci functions in C. The following functions are available:

- `fib_rec(int n)`: Calculates the n-th Fibonacci term using recursion.
- `fib_memo(int n)`: Calculates the n-th Fibonacci term using memoization.
- `fib_dp(int n)`: Calculates the n-th Fibonacci term using dynamic programming.

## Usage

Compile the `fibonacci.c` file and run the executable to see the time taken for each method:

```bash
gcc fibonacci.c -o fibonacci
./fibonacci
```

This will calculate the 10th Fibonacci term and print the runtime for each method.