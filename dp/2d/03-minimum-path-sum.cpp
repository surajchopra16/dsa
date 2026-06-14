// Problem: Minimum path sum
// - Leetcode: https://leetcode.com/problems/minimum-path-sum/description
// - Return the minimum path sum from top left to bottom right

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
int minPathMemo(int i, int j, vector<vector<int>> grid, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return grid[i][j];

    if (i < 0 || j < 0)
        return INT_MAX;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = minPathMemo(i - 1, j, grid, dp);
    int left = minPathMemo(i, j - 1, grid, dp);

    dp[i][j] = grid[i][j] + min(up, left);
    return dp[i][j];
}

// Minimum path sum problem using tabulation
int minPathTab(int m, int n, vector<vector<int>> grid)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
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

    return dp[m - 1][n - 1];
}

int main()
{
    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};
    int m = grid.size();
    int n = grid[0].size();

    // (1) Memoization:
    vector<vector<int>> dp(m, vector<int>(n, -1));

    int pathMemo = minPathMemo(m - 1, n - 1, grid, dp);
    cout << "Minimum path sum: " << pathMemo << endl;

    // (2) Tabulation:
    int pathTab = minPathTab(m, n, grid);
    cout << "Minimum path sum: " << pathTab << endl;

    // DP table for the above grid:
    // [1, 4, 5]
    // [2, 7, 6]
    // [6, 8, 7]

    return 0;
}