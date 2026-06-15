// Problem: Best time to buy and sell stock II
// - Leetcode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description
// - Return the maximum profit we can achieve from multiple transactions

// ⭐ Pattern: Multiple transactions

// Time complexity:
// - Memoization: O(n * 2)
// - Tabulation: O(n * 2)
// - Space optimization: O(n * 2)

// Space complexity:
// - Memoization: O(n * 2) + O(n)
// - Tabulation: O(n * 2)
// - Space optimization: O(2 * 2)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

// Best time to buy and sell stock problem using memoization
int maxProfitMemo(int index, int canBuy, vector<int> &prices, vector<vector<int>> &dp)
{
    if (index == prices.size())
        return 0;

    if (dp[index][canBuy] != -1)
        return dp[index][canBuy];

    int profit = 0;

    if (canBuy)
    {
        int buy = -prices[index] + maxProfitMemo(index + 1, 0, prices, dp);
        int skip = maxProfitMemo(index + 1, 1, prices, dp);

        profit = max(buy, skip);
    }
    else
    {
        int sell = prices[index] + maxProfitMemo(index + 1, 1, prices, dp);
        int skip = maxProfitMemo(index + 1, 0, prices, dp);

        profit = max(sell, skip);
    }

    dp[index][canBuy] = profit;
    return dp[index][canBuy];
}

// Best time to buy and sell stock problem using tabulation
int maxProfitTab(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    dp[n][0] = dp[n][1] = 0;

    for (int index = n - 1; index >= 0; index--)
    {
        for (int canBuy = 0; canBuy <= 1; canBuy++)
        {
            int profit = 0;

            if (canBuy)
            {
                int buy = -prices[index] + dp[index + 1][0];
                int skip = dp[index + 1][1];

                profit = max(buy, skip);
            }
            else
            {
                int sell = prices[index] + dp[index + 1][1];
                int skip = dp[index + 1][0];

                profit = max(sell, skip);
            }

            dp[index][canBuy] = profit;
        }
    }

    return dp[0][1];
}

// Best time to buy and sell stock problem using space optimization
int maxProfitOptimized(vector<int> &prices)
{
    int n = prices.size();
    vector<int> ahead(2, 0);
    vector<int> curr(2, 0);

    ahead[0] = ahead[1] = 0;

    for (int index = n - 1; index >= 0; index--)
    {
        for (int canBuy = 0; canBuy <= 1; canBuy++)
        {
            int profit = 0;

            if (canBuy)
            {
                int buy = -prices[index] + ahead[0];
                int skip = ahead[1];

                profit = max(buy, skip);
            }
            else
            {
                int sell = prices[index] + ahead[1];
                int skip = ahead[0];

                profit = max(sell, skip);
            }

            curr[canBuy] = profit;
        }
        ahead = curr;
    }

    return ahead[1];
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int n = prices.size();

    // 1. Memoization:
    vector<vector<int>> dp(n, vector<int>(2, -1));

    int profitMemo = maxProfitMemo(0, 1, prices, dp);
    cout << "Maximum profit: " << profitMemo << endl;

    // 2. Tabulation:
    int profitTab = maxProfitTab(prices);
    cout << "Maximum profit: " << profitTab << endl;

    // 3. Space optimization:
    int profitOptimized = maxProfitOptimized(prices);
    cout << "Maximum profit: " << profitOptimized << endl;

    return 0;
}