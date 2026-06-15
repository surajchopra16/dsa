// Problem: Best time to buy and sell stock
// - Leetcode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description
// - Return the maximum profit we can achieve from one transaction

// ⭐ Pattern: Single transaction

// Time complexity: O(n)

// Space complexity: O(1)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int n = prices.size();

    int minPrice = prices[0];
    int profit = 0;

    for (int i = 1; i < n; i++)
    {
        profit = max(profit, prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }

    cout << "Maximum profit: " << profit << endl;

    return 0;
}