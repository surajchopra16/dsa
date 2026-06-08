// Problem: Count all the subsequences with sum K

// Time Complexity: O(2^n)

// Space Complexity: O(n)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

// Count all the subsequences with sum K
int countSubsequencesWithSumK(vector<int> arr, int k, int index, vector<int> subseq, int sum)
{
    if (index == arr.size())
    {
        if (sum == k)
            return 1;
        return 0;
    }

    // Pick the current element
    subseq.push_back(arr[index]);
    sum += arr[index];

    int left = countSubsequencesWithSumK(arr, k, index + 1, subseq, sum);

    // Don't pick the current element
    subseq.pop_back();
    sum -= arr[index];

    int right = countSubsequencesWithSumK(arr, k, index + 1, subseq, sum);

    return left + right;
}

int main()
{
    vector<int> arr = {1, 2, 1};
    int k = 2;

    int count = countSubsequencesWithSumK(arr, k, 0, {}, 0);
    cout << "Count of subsequences with sum " << k << " is: " << count << endl;

    return 0;
}