// Problem: Subset sum equals to k
// - GFG: https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
// - Return true if there is a subset with sum equals to k

// Time complexity:
// - Memoization: O(n * k)
// - Tabulation: O(n * k)
// - Space optimized: O(n * k)

// Space complexity:
// - Memoization: O(n * k) + O(n)
// - Tabulation: O(n * k)
// - Space optimized: O(2k)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

// Subset sum equals to k problem using memoization
bool checkSubsetSumMemo(int index, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if (k == 0)
        return true;

    if (index == 0)
        return arr[0] == k;

    if (dp[index][k] != -1)
        return dp[index][k];

    bool pick = arr[index] <= k ? checkSubsetSumMemo(index - 1, k - arr[index], arr, dp) : false;
    bool notPick = checkSubsetSumMemo(index - 1, k, arr, dp);

    dp[index][k] = pick || notPick;
    return dp[index][k];
}

// Subset sum equals to k problem using tabulation
bool checkSubsetSumTab(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Base cases
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    // Fill the DP table
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

// Subset sum equals to k problem using space optimization
bool checkSubsetSumOptimized(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<bool> prev(k + 1, false);
    vector<bool> curr(k + 1, false);

    prev[0] = curr[0] = true;
    if (arr[0] <= k)
        prev[arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool pick = arr[i] <= j ? prev[j - arr[i]] : false;
            bool notPick = prev[j];

            curr[j] = pick || notPick;
        }
        prev = curr;
    }

    return prev[k];
}

int main()
{
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int k = 9;

    int n = arr.size();

    // 1. Memoization:
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    bool ansMemo = checkSubsetSumMemo(n - 1, k, arr, dp);
    cout << "Subset sum equals to k: " << (ansMemo ? "True" : "False") << endl;

    // 2. Tabulation:
    bool ansTab = checkSubsetSumTab(arr, k);
    cout << "Subset sum equals to k: " << (ansTab ? "True" : "False") << endl;

    // 3. Space optimization:
    bool ansOptimized = checkSubsetSumOptimized(arr, k);
    cout << "Subset sum equals to k: " << (ansOptimized ? "True" : "False") << endl;

    return 0;
}