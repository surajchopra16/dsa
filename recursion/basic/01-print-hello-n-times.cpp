// Recursion:
// - A function that calls itself until a base case is met
// - A base case is a condition under which the recursive function will stop calling itself
// - When a recursive function does not have a base case or the base case is never reached, it will call itself indefinitely, leading to a stack overflow or segmentation fault

// Recursion Tree:
// - A tree data structure that represents the recursive calls made by a function
// - Each node represents a function call, and the edges represent the flow of execution from one call to another

// Problem: Print "Hello, World!" N times using recursion

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

// Print "Hello, World!" N times using recursion
void printHello(int n)
{
    if (n == 0)
        return;

    cout << "Hello, World!" << endl;

    printHello(n - 1);
}

int main()
{
    int n = 5;

    cout << "Printing \"Hello, World!\" " << n << " times:" << endl;
    printHello(n);

    return 0;
}