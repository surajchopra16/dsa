// Problem: Print one subsequence with sum K

// Time Complexity: O(2^n)

// Space Complexity: O(n)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

// Print one subsequence with sum K
bool printSubsequenceWithSumK(vector<int> arr, int k, int index, vector<int> subseq, int sum)
{
    if (index == arr.size())
    {
        if (sum == k)
        {
            for (int num : subseq)
                cout << num << " ";
            cout << endl;
            return true;
        }
        return false;
    }

    // Pick the current element
    subseq.push_back(arr[index]);
    sum += arr[index];

    if (printSubsequenceWithSumK(arr, k, index + 1, subseq, sum))
        return true;

    // Don't pick the current element
    subseq.pop_back();
    sum -= arr[index];

    if (printSubsequenceWithSumK(arr, k, index + 1, subseq, sum))
        return true;

    return false;
}

int main()
{
    vector<int> arr = {1, 2, 1};
    int k = 2;

    printSubsequenceWithSumK(arr, k, 0, {}, 0);

    return 0;
}