#include <iostream>
#include <ctime>

using namespace std;


long long memo[50] = {0};

long long fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

long long fib_memo(int n) {
    if (n <= 1) return n;

    if (memo[n] != 0) {
        return memo[n];
    }

    memo[n] = fib_memo(n - 1) + fib_memo(n - 2);
    return memo[n];
}

int main() {
    int n = 40;

    cout << "--- 1. Running Memoized Fibonacci ---" << endl;
    clock_t start_memo = clock();
    long long ans_memo = fib_memo(n);
    clock_t end_memo = clock();
    double time_memo = double(end_memo - start_memo) / CLOCKS_PER_SEC;

    cout << "Result: " << ans_memo << endl;
    cout << "Time taken: " << time_memo << " seconds" << endl << endl;


    cout << "--- 2. Running Standard Fibonacci (Please wait...) ---" << endl;
    clock_t start_std = clock();
    long long ans_std = fib(n);
    clock_t end_std = clock();
    double time_std = double(end_std - start_std) / CLOCKS_PER_SEC;

    cout << "Result: " << ans_std << endl;
    cout << "Time taken: " << time_std << " seconds" << endl;

    return 0;
}
