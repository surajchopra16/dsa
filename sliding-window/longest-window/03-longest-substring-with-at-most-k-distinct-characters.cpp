// Problem: Longest substring with at most K distinct characters
// - Leetcode: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description (Premium)
// - GFG: https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1 (Similar)
// - Return the length of the longest substring that contains at most K distinct characters
// - Similar to the fruit into baskets problem

// Solution:
// - Brute force approach: Generate all possible substrings and check if they contain at most K distinct characters. Keep track of the maximum length of such substrings
// - Better approach: Use a sliding window approach with two pointers and a frequency map. Expand the window with the right pointer and shrink the window with the left pointer when the count of distinct elements exceeds K until it becomes valid again
// - Optimal approach: Use a sliding window approach with two pointers and a frequency map. Expand the window with the right pointer and shrink the window with the left pointer when the count of distinct elements exceeds K by only one step

// Time complexity:
// - Brute force approach: O(n^2)
// - Better approach: O(2n)
// - Optimal approach: O(n)

// Space complexity:
// - Brute force approach: O(k + 1)
// - Better approach: O(k + 1)
// - Optimal approach: O(k + 1)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "aabacbebebe";
    int n = s.size();

    int k = 3;

    // 1. Brute force approach:
    // int maxLen = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     unordered_set<char> st;
    //     for (int j = i; j < n; j++)
    //     {
    //         st.insert(s[j]);

    //         if (st.size() > k)
    //             break;

    //         maxLen = max(maxLen, j - i + 1);
    //     }
    // }

    // cout << "Length of the longest substring: " << maxLen << endl;

    // 2. Better approach:
    int maxLen = 0;

    map<char, int> mp;
    int left = 0;
    int right = 0;

    while (right < n)
    {
        mp[s[right]]++;

        while (mp.size() > k)
        {
            mp[s[left]]--;
            if (mp[s[left]] == 0)
                mp.erase(s[left]);
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
        right++;
    }

    cout << "Length of the longest substring: " << maxLen << endl;

    // 3. Optimal approach:
    int maxLen = 0;

    map<char, int> mp;
    int left = 0;
    int right = 0;

    while (right < n)
    {
        mp[s[right]]++;

        if (mp.size() > k)
        {
            mp[s[left]]--;
            if (mp[s[left]] == 0)
                mp.erase(s[left]);
            left++;
        }

        if (mp.size() <= k)
            maxLen = max(maxLen, right - left + 1);
        right++;
    }

    cout << "Length of the longest substring: " << maxLen << endl;

    return 0;
}
