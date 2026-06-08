// Subsequence:
// - A subsequence is a sequence that can be derived by deleting some or no elements without changing the order of the remaining elements
// - Number of subsequences of an array (size n) is 2^n

// Example:
// - [1, 2, 3] -> [], [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3]

// Problem: Print all the subsequences

// ⭐ Pattern: Pick and not pick

// Time Complexity: O(2^n)

// Space Complexity: O(n)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

// Print all the subsequences of the array
void printSubsequences(vector<int> arr, int index, vector<int> subseq)
{
    if (index == arr.size())
    {
        for (int num : subseq)
            cout << num << " ";
        cout << endl;
        return;
    }

    // Pick the current element
    subseq.push_back(arr[index]);
    printSubsequences(arr, index + 1, subseq);

    // Don't pick the current element
    subseq.pop_back();
    printSubsequences(arr, index + 1, subseq);
}

int main()
{
    vector<int> arr = {1, 2, 3};

    printSubsequences(arr, 0, {});

    return 0;
}