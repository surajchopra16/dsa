// Problem: Minimum path sum
// - Leetcode: https://leetcode.com/problems/minimum-path-sum/description
// - Return the minimum path sum from top left to bottom right

// ⭐ Pattern: Min or max to reach a target

// Time complexity:
// - Memoization: O(m * n)
// - Tabulation: O(m * n)

// Space complexity:
// - Memoization: O(m * n) + O(m + n)
// - Tabulation: O(m * n)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

// Minimum path sum problem using memoization
int minPathMemo(int m, int n, vector<vector<int>> grid, vector<vector<int>> &dp)
{
    if (m == 0 && n == 0)
        return grid[m][n];

    if (m < 0 || n < 0)
        return INT_MAX;

    if (dp[m][n] != -1)
        return dp[m][n];

    int up = minPathMemo(m - 1, n, grid, dp);
    int left = minPathMemo(m, n - 1, grid, dp);

    dp[m][n] = grid[m][n] + min(up, left);
    return dp[m][n];
}

// Minimum path sum problem using tabulation
int minPathTab(int m, int n, vector<vector<int>> grid)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j];
            else
            {
                int up = (i > 0) ? dp[i - 1][j] : INT_MAX;
                int left = (j > 0) ? dp[i][j - 1] : INT_MAX;

                dp[i][j] = grid[i][j] + min(up, left);
            }
        }
    }

    return dp[m][n];
}

int main()
{
    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};
    int m = grid.size();
    int n = grid[0].size();

    // 1. Memoization:
    vector<vector<int>> dp(m, vector<int>(n, -1));

    int pathMemo = minPathMemo(m - 1, n - 1, grid, dp);
    cout << "Minimum path sum: " << pathMemo << endl;

    // 2. Tabulation:
    int pathTab = minPathTab(m - 1, n - 1, grid);
    cout << "Minimum path sum: " << pathTab << endl;

    // DP table for the above grid:
    // [1, 4, 5]
    // [2, 7, 6]
    // [6, 8, 7]

    return 0;
}