// Problem: Check if an array is sorted
// - Leetcode: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description
// - (a). Check if an array is sorted in non-decreasing order (can have duplicates)
// - (b). Check if an array is sorted and rotated

// Solution:
// - Optimal approach (a): Traverse the array and compare each element with its previous one
// - Optimal approach (b): Count the number of times an element is greater than the next element in a circular manner and check if the count is less than or equal to 1

// Time Complexity:
// - Optimal approach (a and b): O(n)

// Space Complexity:
// - Optimal approach (a and b): O(1)

// ==================== Code ====================>

#include <iostream>
using namespace std;

int main()
{
    // (a). Array is sorted in non-decreasing order
    int n = 5;
    int arr[5] = {1, 2, 2, 3, 4};

    // Optimal approach:
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            cout << "Array is not sorted in non-decreasing order" << endl;
            return 0;
        }
    }

    cout << "Array is sorted in non-decreasing order" << endl;

    // (b). Array is sorted and rotated
    int n2 = 5;
    int arr2[5] = {3, 4, 5, 1, 2};

    // Optimal approach:
    int count = 0;
    for (int i = 0; i < n2; i++)
    {
        if (arr2[i] > arr2[(i + 1) % n2])
            count++;
    }

    if (count <= 1)
        cout << "Array is sorted and rotated" << endl;
    else
        cout << "Array is not sorted and rotated" << endl;

    return 0;
}