// Problem: Minimum falling path sum
// - Leetcode: https://leetcode.com/problems/minimum-falling-path-sum/description
// - Return the minimum sum of any falling path through matrix

// ⭐ Pattern: Multiple starting points and multiple ending points

// Time complexity:
// - Memoization: O(n * n)
// - Tabulation: O(n * n)
// - Space optimization: O(n * n)

// Space complexity:
// - Memoization: O(n * n) + O(n)
// - Tabulation: O(n * n)
// - Space optimization: O(2n)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

// Minimum falling path sum using memoization
int minPathMemo(int i, int j, vector<vector<int>> matrix, vector<vector<int>> &dp)
{
    int n = matrix.size();

    if (j < 0 || j >= n)
        return INT_MAX;

    if (i == 0)
        return matrix[i][j];

    if (dp[i][j] != 1e9)
        return dp[i][j];

    int leftD = minPathMemo(i - 1, j - 1, matrix, dp);
    int up = minPathMemo(i - 1, j, matrix, dp);
    int rightD = minPathMemo(i - 1, j + 1, matrix, dp);

    dp[i][j] = matrix[i][j] + min({leftD, up, rightD});
    return dp[i][j];
}

// Minimum falling path sum using tabulation
int minPathTab(vector<vector<int>> matrix)
{
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int j = 0; j < n; j++)
        dp[0][j] = matrix[0][j];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int leftD = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;
            int up = dp[i - 1][j];
            int rightD = (j < n - 1) ? dp[i - 1][j + 1] : INT_MAX;

            dp[i][j] = matrix[i][j] + min({leftD, up, rightD});
        }
    }

    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
}

// Minimum falling path sum using space optimization
int minPathOptimized(vector<vector<int>> matrix)
{
    int n = matrix.size();
    vector<int> prev(n, 0);
    vector<int> curr(n, 0);

    for (int j = 0; j < n; j++)
        prev[j] = matrix[0][j];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int leftD = (j > 0) ? prev[j - 1] : INT_MAX;
            int up = prev[j];
            int rightD = (j < n - 1) ? prev[j + 1] : INT_MAX;

            curr[j] = matrix[i][j] + min({leftD, up, rightD});
        }
        prev = curr;
    }

    return *min_element(prev.begin(), prev.end());
}

int main()
{
    vector<vector<int>> matrix = {{2, 1, 3},
                                  {6, 5, 4},
                                  {7, 8, 9}};
    int n = matrix.size();

    // (1) Memoization:
    vector<vector<int>> dp(n, vector<int>(n, 1e9));

    int pathMemo = INT_MAX;
    for (int j = 0; j < n; j++)
        pathMemo = min(pathMemo, minPathMemo(n - 1, j, matrix, dp));
    cout << "Minimum falling path sum: " << pathMemo << endl;

    // (2) Tabulation:
    int pathTab = minPathTab(matrix);
    cout << "Minimum falling path sum: " << pathTab << endl;

    // (3) Space optimization:
    int pathOpt = minPathOptimized(matrix);
    cout << "Minimum falling path sum: " << pathOpt << endl;

    return 0;
}