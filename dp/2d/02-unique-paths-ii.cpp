// Problem: Unique paths II
// - Leetcode: https://leetcode.com/problems/unique-paths-ii/description
// - Return the number of possible unique paths that the robot can take to reach the bottom-right corner given that there are obstacles in the grid

// Solution:
// - If there is an obstacle at the current cell, then the number of paths to reach that cell is 0 because the robot cannot pass through it

// Time complexity:
// - Memoization: O(m * n)
// - Tabulation: O(m * n)

// Space complexity:
// - Memoization: O(m * n) + O(m + n)
// - Tabulation: O(m * n)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

// Unique paths problem using memoization
int uniquePathsMemo(int i, int j, vector<vector<int>> obstacles, vector<vector<int>> &dp)
{
    if (i >= 0 && j >= 0 && obstacles[i][j] == 1)
        return 0;

    if (i == 0 && j == 0)
        return 1;

    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = uniquePathsMemo(i - 1, j, obstacles, dp);
    int left = uniquePathsMemo(i, j - 1, obstacles, dp);

    dp[i][j] = up + left;
    return dp[i][j];
}

// Unique paths problem using tabulation
int uniquePathsTab(int m, int n, vector<vector<int>> obstacles)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (obstacles[i][j] == 1)
                dp[i][j] = 0;
            else if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                int up = (i > 0) ? dp[i - 1][j] : 0;
                int left = (j > 0) ? dp[i][j - 1] : 0;

                dp[i][j] = up + left;
            }
        }
    }

    return dp[m - 1][n - 1];
}

int main()
{
    vector<vector<int>> obstacles = {{0, 0, 0},
                                     {0, 1, 0},
                                     {0, 0, 0}};
    int m = obstacles.size();
    int n = obstacles[0].size();

    // (1) Memoization:
    vector<vector<int>> dp(m, vector<int>(n, -1));

    int pathsMemo = uniquePathsMemo(m - 1, n - 1, obstacles, dp);
    cout << "Number of unique paths: " << pathsMemo << endl;

    // (2) Tabulation:
    int pathsTab = uniquePathsTab(m, n, obstacles);
    cout << "Number of unique paths: " << pathsTab << endl;

    return 0;
}