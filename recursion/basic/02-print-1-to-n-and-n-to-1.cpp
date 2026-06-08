// Problems:
// - Print numbers from N to 1 using recursion
// - Print numbers from 1 to N using recursion

// ⭐ Pattern: Single recursive call (Linear)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

// Print numbers from N to 1 using recursion
void printNto1(int n)
{
    if (n == 0)
        return;

    // Action BEFORE the recursive call
    cout << n << " ";

    printNto1(n - 1);
}

// Print numbers from 1 to N using recursion
void print1toN(int n)
{
    if (n == 0)
        return;

    print1toN(n - 1);

    // Action AFTER the recursive call
    cout << n << " ";
}

int main()
{
    int n = 5;

    cout << "Printing numbers from " << n << " to 1:" << endl;
    printNto1(n);

    cout << endl;

    cout << "Printing numbers from 1 to " << n << ":" << endl;
    print1toN(n);

    return 0;
}