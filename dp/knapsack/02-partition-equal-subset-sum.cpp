// Problem: Partition equal subset sum
// - Leetcode: https://leetcode.com/problems/partition-equal-subset-sum/description
// - Return true if the array can be partitioned into two subsets with equal sum

// Solution:
// - If the total sum of the array is odd, return false
// - Otherwise, check whether a subset exists with a sum equal to the total / 2

// Time complexity:
// - Tabulation: O(n * total / 2)

// Space complexity:
// - Tabulation: O(n * total / 2)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

// Subset sum equals to k problem using tabulation
bool checkSubsetSumTab(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool pick = arr[i] <= j ? dp[i - 1][j - arr[i]] : false;
            bool notPick = dp[i - 1][j];

            dp[i][j] = pick || notPick;
        }
    }

    return dp[n - 1][k];
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    int n = nums.size();

    // Tabulation:
    int total = accumulate(nums.begin(), nums.end(), 0);

    if (total % 2 == 1)
    {
        cout << "Partition equal subset sum: False" << endl;
        return 0;
    }

    bool partition = checkSubsetSumTab(nums, total / 2);
    cout << "Partition equal subset sum: " << (partition ? "True" : "False") << endl;

    return 0;
}