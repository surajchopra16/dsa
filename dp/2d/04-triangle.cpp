// Problem: Triangle
// - Leetcode: https://leetcode.com/problems/triangle/description
// - Return the minimum path sum from top to bottom of the triangle

// ⭐ Pattern: One starting point and multiple ending points

// Time complexity:
// - Memoization: O(m * m)
// - Tabulation: O(m * m)
// - Space optimization: O(m * m)

// Space complexity:
// - Memoization: O(m * m) + O(m)
// - Tabulation: O(m * m)
// - Space optimization: O(2m)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

// Triangle problem using memoization
int minPathMemo(int i, int j, vector<vector<int>> triangle, vector<vector<int>> &dp)
{
    int m = triangle.size();

    if (i == m - 1)
        return triangle[i][j];

    if (dp[i][j] != 1e9)
        return dp[i][j];

    int down = minPathMemo(i + 1, j, triangle, dp);
    int diagonal = minPathMemo(i + 1, j + 1, triangle, dp);

    dp[i][j] = triangle[i][j] + min(down, diagonal);
    return dp[i][j];
}

// Triangle problem using tabulation
int minPathTab(vector<vector<int>> triangle)
{
    int m = triangle.size();

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
int minPathOptimized(vector<vector<int>> triangle)
{
    int m = triangle.size();
    vector<int> prev(m, 0);
    vector<int> curr(m, 0);

    for (int j = 0; j < m; j++)
        prev[j] = triangle[m - 1][j];

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            int down = prev[j];
            int diagonal = prev[j + 1];

            curr[j] = triangle[i][j] + min(down, diagonal);
        }
        prev = curr;
    }

    return prev[0];
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

    int pathMemo = minPathMemo(0, 0, triangle, dp);
    cout << "Minimum path sum: " << pathMemo << endl;

    // (2) Tabulation:
    int pathTab = minPathTab(triangle);
    cout << "Minimum path sum: " << pathTab << endl;

    // (3) Space optimization:
    int pathOptimized = minPathOptimized(triangle);
    cout << "Minimum path sum: " << pathOptimized << endl;

    return 0;
}