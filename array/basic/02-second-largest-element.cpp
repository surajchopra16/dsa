// Problem: Find the second largest element in an array of integers

// Solution:
// - Brute force approach: Sort the array and find the largest element (n-1) and traverse back from the n-2 index to find the second largest element
// - Better approach: Traverse the array once to find the largest and then traverse again to find the second largest
// - Optimal approach: Traverse the array once and keep track of both largest and second largest

// Time complexity:
// - Brute force approach: O(n log n) + O(n)
// - Better approach: O(n) + O(n) = O(2n)
// - Optimal approach: O(n)

// Space complexity:
// - Brute force approach: O(n)
// - Better approach: O(1)
// - Optimal approach: O(1)

// ==================== Code ====================>

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int arr[n] = {0, 6, 8, 8, 5};

    // 1. Brute force approach:
    // sort(arr, arr + n);
    // int largest = arr[n - 1];

    // int slargest = -1;
    // for (int i = n - 2; i >= 0; i--)
    // {
    //     if (arr[i] != largest)
    //     {
    //         slargest = arr[i];
    //         break;
    //     }
    // }

    // cout << "Second largest element: " << slargest << endl;

    // 2. Better approach:
    // int largest = arr[0];
    // for (int i = 1; i < n; i++)
    // {
    //     if (arr[i] > largest)
    //         largest = arr[i];
    // }

    // int slargest = -1;
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] > slargest && arr[i] != largest)
    //         slargest = arr[i];
    // }

    // cout << "Second largest element: " << slargest;

    // 3. Optimal approach:
    int largest = arr[0];
    int slargest = -1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            slargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > slargest && arr[i] != largest)
        {
            slargest = arr[i];
        }
    }

    cout << "Second largest element: " << slargest;

    return 0;
}