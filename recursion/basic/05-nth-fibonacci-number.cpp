// Problem: Nth fibonacci number using recursion

// ⭐ Pattern: Multiple recursive calls (Tree)

// Time Complexity: O(2^n)

// Space Complexity: O(n)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

// Nth fibonacci number using recursion
int fibonacci(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n = 5;

    int fib = fibonacci(n);
    cout << "Fibonacci number at position " << n << " is: " << fib << endl;

    return 0;
}