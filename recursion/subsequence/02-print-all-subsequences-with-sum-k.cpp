// Problem: Print all the subsequences with sum K

// Time Complexity: O(2^n)

// Space Complexity: O(n)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

// Print all the subsequences with sum K
void printSubsequencesWithSumK(vector<int> arr, int k, int index, vector<int> subseq, int sum)
{
    if (index == arr.size())
    {
        if (sum == k)
        {
            for (int num : subseq)
                cout << num << " ";
            cout << endl;
        }
        return;
    }

    // Pick the current element
    subseq.push_back(arr[index]);
    sum += arr[index];
    printSubsequencesWithSumK(arr, k, index + 1, subseq, sum);

    // Don't pick the current element
    subseq.pop_back();
    sum -= arr[index];
    printSubsequencesWithSumK(arr, k, index + 1, subseq, sum);
}

int main()
{
    vector<int> arr = {1, 2, 1};
    int k = 2;

    printSubsequencesWithSumK(arr, k, 0, {}, 0);

    return 0;
}