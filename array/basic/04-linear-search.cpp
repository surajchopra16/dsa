// Problem: Search an element in an array using linear search

// Solution:
// - Brute force approach: Traverse the array and compare each element with the target element

// Time complexity:
// - Brute force approach: O(n)

// Space complexity:
// - Brute force approach: O(1)

// ==================== Code ====================>

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10;
    int arr[n] = {34, 21, 56, 78, 12, 90, 11, 67, 45, 89};

    int num = 67;

    // Linear search:
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            cout << "Element found at index: " << i << endl;
            return 0;
        }
    }

    cout << "Element not found in the array." << endl;

    return 0;
}