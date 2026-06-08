// Problems:
// - Sum of first N natural numbers using recursion
// - Factorial of a number using recursion

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

// Sum of first N natural numbers using parameterised approach
void sumParameterised(int n, int sum)
{
    if (n == 0)
    {
        cout << "Sum using parameterised approach: " << sum << endl;
        return;
    }

    sumParameterised(n - 1, sum + n);
}

// Sum of first N natural numbers using functional approach
int sumFunctional(int n)
{
    if (n == 0)
        return 0;

    return n + sumFunctional(n - 1);
}

// Factorial of a number using recursion
int factorial(int n)
{
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}

int main()
{
    int n = 5;

    sumParameterised(n, 0);

    int sum = sumFunctional(n);
    cout << "Sum using functional approach: " << sum << endl;

    int fact = factorial(n);
    cout << "Factorial of " << n << " is: " << fact << endl;

    return 0;
}