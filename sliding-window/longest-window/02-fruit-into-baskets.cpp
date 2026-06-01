// Problem: Fruit into baskets (longest subarray with at most 2 distinct elements)
// - Leetcode: https://leetcode.com/problems/fruit-into-baskets/description
// - Return the maximum number of fruits you can pick using two baskets and each basket can only hold one type of fruit

// Solution:
// - Brute force approach: Generate all possible subarrays and check if they contain at most 2 distinct elements. Keep track of the maximum length of such subarrays
// - Better approach: Use a sliding window approach with two pointers and a frequency map. Expand the window with the right pointer and shrink the window with the left pointer when the count of distinct elements exceeds 2 until it becomes valid again
// - Optimal approach: Use a sliding window approach with two pointers and a frequency map. Expand the window with the right pointer and shrink the window with the left pointer when the count of distinct elements exceeds 2 by only one step

// Time complexity:
// - Brute force approach: O(n^2)
// - Better approach: O(2n)
// - Optimal approach: O(n)

// Space complexity:
// - Brute force approach: O(3)
// - Better approach: O(3)
// - Optimal approach: O(3)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> fruits = {1, 2, 3, 2, 2};
    int n = fruits.size();

    // 1. Brute force approach:
    // int maxFruits = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     unordered_set<int> st;
    //     for (int j = i; j < n; j++)
    //     {
    //         st.insert(fruits[j]);

    //         if (st.size() > 2)
    //             break;

    //         maxFruits = max(maxFruits, j - i + 1);
    //     }
    // }

    // cout << "Maximum number of fruits: " << maxFruits << endl;

    // 2. Better approach:
    int maxFruits = 0;

    map<int, int> mp;
    int left = 0;
    int right = 0;

    while (right < n)
    {
        mp[fruits[right]]++;

        while (mp.size() > 2)
        {
            mp[fruits[left]]--;
            if (mp[fruits[left]] == 0)
                mp.erase(fruits[left]);
            left++;
        }

        maxFruits = max(maxFruits, right - left + 1);
        right++;
    }

    cout << "Maximum number of fruits: " << maxFruits << endl;

    // 3. Better approach:
    int maxFruits = 0;

    map<int, int> mp;
    int left = 0;
    int right = 0;

    while (right < n)
    {
        mp[fruits[right]]++;

        if (mp.size() > 2)
        {
            mp[fruits[left]]--;
            if (mp[fruits[left]] == 0)
                mp.erase(fruits[left]);
            left++;
        }

        if (mp.size() <= 2)
            maxFruits = max(maxFruits, right - left + 1);

        right++;
    }

    cout << "Maximum number of fruits: " << maxFruits << endl;

    return 0;
}
