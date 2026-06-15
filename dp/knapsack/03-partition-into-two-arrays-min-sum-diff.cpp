// Problem: Partition array into two arrays to minimize sum difference
// - GFG: https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1
// - Return the minimum possible difference between the sums of the two subsets of equal size

// Solution:
// - Calculate the total sum of the array
// - Use the subset sum problem to find all possible sums that can be formed using the elements of the array
// - Iterate through the possible sums and calculate the difference between the two subsets, and keep track of the minimum difference

// Time complexity:
// - Tabulation: O(n * total)

// Space complexity:
// - Tabulation: O(n * total)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

// Subset sum equals to k problem using tabulation
vector<bool> checkSubsetSumTab(vector<int> &arr, int k)
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

    return dp[n - 1];
}

int main()
{
    vector<int> nums = {3, 9, 7, 3};
    int n = nums.size();

    // Tabulation:
    int total = accumulate(nums.begin(), nums.end(), 0);

    vector<bool> possibleSums = checkSubsetSumTab(nums, total);

    int minDiff = INT_MAX;
    for (int i = 0; i <= total; i++)
    {
        if (possibleSums[i])
        {
            int sum1 = i;
            int sum2 = total - i;
            minDiff = min(minDiff, abs(sum2 - sum1));
        }
    }

    cout << "Minimum sum difference: " << minDiff << endl;

    return 0;
}