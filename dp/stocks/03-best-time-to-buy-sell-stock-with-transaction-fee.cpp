// Problem: Best time to buy and sell stock with transaction fee
// - Leetcode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
// - Return the maximum profit we can achieve from multiple transactions with a transaction fee

// ⭐ Pattern: Multiple transactions with transaction fee

// Time complexity:
// - Memoization: O(n * 2)
// - Tabulation: O(n * 2)

// Space complexity:
// - Memoization: O(n * 2) + O(n)
// - Tabulation: O(n * 2)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

// Best time to buy and sell stock with transaction fee problem using memoization
int maxProfitMemo(int index, int canBuy, vector<int> &prices, int fee, vector<vector<int>> &dp)
{
    if (index == prices.size())
        return 0;

    if (dp[index][canBuy] != -1)
        return dp[index][canBuy];

    int profit = 0;

    if (canBuy)
    {
        int buy = -prices[index] + maxProfitMemo(index + 1, 0, prices, fee, dp);
        int skip = maxProfitMemo(index + 1, 1, prices, fee, dp);

        profit = max(buy, skip);
    }
    else
    {
        int sell = prices[index] - fee + maxProfitMemo(index + 1, 1, prices, fee, dp);
        int skip = maxProfitMemo(index + 1, 0, prices, fee, dp);

        profit = max(sell, skip);
    }

    dp[index][canBuy] = profit;
    return dp[index][canBuy];
}

// Best time to buy and sell stock with transaction fee problem using tabulation
int maxProfitTab(vector<int> &prices, int fee)
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
                int sell = prices[index] - fee + dp[index + 1][1];
                int skip = dp[index + 1][0];

                profit = max(sell, skip);
            }

            dp[index][canBuy] = profit;
        }
    }

    return dp[0][1];
}

int main()
{
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;

    int n = prices.size();

    // 1. Memoization:
    vector<vector<int>> dp(n, vector<int>(2, -1));

    int profitMemo = maxProfitMemo(0, 1, prices, fee, dp);
    cout << "Maximum profit with transaction fee: " << profitMemo << endl;

    // 2. Tabulation:
    int profitTab = maxProfitTab(prices, fee);
    cout << "Maximum profit with transaction fee: " << profitTab << endl;

    return 0;
}