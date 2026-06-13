// Problem: Triangle
// - Leetcode: https://leetcode.com/problems/triangle/description
// - Return the minimum path sum from top to bottom of the triangle

// Time complexity:
// - Memoization: O(m * m)
// - Tabulation: O(m * m)
// - Space optimization: O(m * m)

// Space complexity:
// - Memoization: O(m * m) + O(m)
// - Tabulation: O(m * m)
// - Space optimization: O(1)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

// Triangle problem using memoization
int minPathMemo(int i, int j, vector<vector<int>> triangle, int m, vector<vector<int>> &dp)
{
    if (i == m - 1)
        return triangle[i][j];

    if (dp[i][j] != 1e9)
        return dp[i][j];

    int down = minPathMemo(i + 1, j, triangle, m, dp);
    int diagonal = minPathMemo(i + 1, j + 1, triangle, m, dp);

    dp[i][j] = triangle[i][j] + min(down, diagonal);
    return dp[i][j];
}

// Triangle problem using tabulation
int minPathTab(vector<vector<int>> triangle, int m)
{
    vector<vector<int>> dp(m, vector<int>(m, 0));

    for (int j = 0; j < m; j++)
        dp[m - 1][j] = triangle[m - 1][j];

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            int down = dp[i + 1][j];
            int diagonal = dp[i + 1][j + 1];

            dp[i][j] = triangle[i][j] + min(down, diagonal);
        }
    }

    return dp[0][0];
}

// Triangle problem using space optimization
int minPathOptimized(vector<vector<int>> triangle, int m)
{
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            int down = triangle[i + 1][j];
            int diagonal = triangle[i + 1][j + 1];

            triangle[i][j] = triangle[i][j] + min(down, diagonal);
        }
    }

    return triangle[0][0];
}

int main()
{
    vector<vector<int>> triangle = {{2},
                                    {3, 4},
                                    {6, 5, 7},
                                    {4, 1, 8, 3}};
    int m = triangle.size();

    // (1) Memoization:
    vector<vector<int>> dp(m, vector<int>(m, 1e9));

    int pathMemo = minPathMemo(0, 0, triangle, m, dp);
    cout << "Minimum path sum: " << pathMemo << endl;

    // (2) Tabulation:
    int pathTab = minPathTab(triangle, m);
    cout << "Minimum path sum: " << pathTab << endl;

    // (3) Space optimization:
    int pathOptimized = minPathOptimized(triangle, m);
    cout << "Minimum path sum: " << pathOptimized << endl;

    return 0;
}