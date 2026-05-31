// Array: It is a data structure that stores a collection of similar elements in contiguous memory locations

// Notes:
// - Global arrays are initialized to 0, while local arrays contain garbage values
// - Global array max size is 10^7, while local array max size is 10^6

// Problem: Find the largest element in an array of integers

// Solution:
// - Brute force approach: Sort the array and last element will be the largest element
// - Optimal approach: Traverse the array and keep track of the largest element

// Time complexity:
// - Brute force approach: O(n log n)
// - Optimal approach: O(n)

// Space complexity:
// - Brute force approach: O(n)
// - Optimal approach: O(1)

// ==================== Code ====================>

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int arr[n] = {3, 5, 7, 2, 8};

    // 1. Brute force approach:
    // sort(arr, arr + n);
    // cout << "Largest element: " << arr[n - 1] << endl;

    // 2. Optimal approach:
    int largest = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
            largest = arr[i];
    }

    cout << "Largest element: " << largest << endl;

    return 0;
}