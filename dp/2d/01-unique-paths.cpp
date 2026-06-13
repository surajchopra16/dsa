// Problem: Unique paths
// - Leetcode: https://leetcode.com/problems/unique-paths/description
// - Return the number of possible unique paths that the robot can take to reach the bottom-right corner

// ⭐ Pattern: Count the number of distinct ways

// Time complexity:
// - Memoization: O(m * n)
// - Tabulation: O(m * n)
// - Space optimized: O(m * n)

// Space complexity:
// - Memoization: O(m * n) + O(m + n)
// - Tabulation: O(m * n)
// - Space optimized: O(n)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

// Unique paths problem using memoization
int uniquePathsMemo(int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 && n == 0)
        return 1;

    if (m < 0 || n < 0)
        return 0;

    if (dp[m][n] != -1)
        return dp[m][n];

    int up = uniquePathsMemo(m - 1, n, dp);
    int left = uniquePathsMemo(m, n - 1, dp);

    dp[m][n] = up + left;
    return dp[m][n];
}

// Unique paths problem using tabulation
int uniquePathsTab(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                int up = (i > 0) ? dp[i - 1][j] : 0;
                int left = (j > 0) ? dp[i][j - 1] : 0;

                dp[i][j] = up + left;
            }
        }
    }

    return dp[m][n];
}

// Unique paths problem using space optimization
int uniquePathsOptimized(int m, int n)
{
    // Combine the previous row and current row answers into a single array
    vector<int> curr(n + 1, 0);

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = 1;
            else
            {
                int up = curr[j];
                int left = (j > 0) ? curr[j - 1] : 0;

                curr[j] = up + left;
            }
        }
    }

    return curr[n];
}

int main()
{
    int m = 3;
    int n = 7;

    // (1) Memoization:
    vector<vector<int>> dp(m, vector<int>(n, -1));

    int pathsMemo = uniquePathsMemo(m - 1, n - 1, dp);
    cout << "Number of unique paths: " << pathsMemo << endl;

    // (2) Tabulation:
    int pathsTab = uniquePathsTab(m - 1, n - 1);
    cout << "Number of unique paths: " << pathsTab << endl;

    // DP table:
    // [1, 1, 1]
    // [1, 2, 3]
    // [1, 3, 6]

    // (3) Space optimized:
    int pathsOptimized = uniquePathsOptimized(m - 1, n - 1);
    cout << "Number of unique paths: " << pathsOptimized << endl;

    return 0;
}