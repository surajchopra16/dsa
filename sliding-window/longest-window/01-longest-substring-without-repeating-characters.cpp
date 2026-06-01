// Problem: Longest substring without repeating characters
// - Leetcode: https://leetcode.com/problems/longest-substring-without-repeating-characters/description
// - Return the length of the longest substring without repeating characters

// Solution:
// - Brute force approach: Generate all possible substrings and check if they contain repeating characters and keep track of the maximum length of valid substrings
// - Better approach: Use a sliding window approach with two pointers and a frequency array. Expand the window with the right pointer and shrink the window with the left pointer when a repeating character is found
// - Optimal approach: Use a sliding window approach with two pointers and a last index array. Expand the window with the right pointer and move the left pointer to the lastIndex + 1 when a repeating character is found

// Time complexity:
// - Brute force approach: O(n^2)
// - Better approach: O(2n)
// - Optimal approach: O(n)

// Space complexity:
// - Brute force approach: O(256)
// - Better approach: O(256)
// - Optimal approach: O(256)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abcabcbb";
    int n = s.size();

    // 1. Brute force approach:
    // int maxLen = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     vector<int> freq(256, 0);

    //     for (int j = i; j < n; j++)
    //     {
    //         freq[s[j]]++;

    //         if (freq[s[j]] > 1)
    //             break;

    //         maxLen = max(maxLen, j - i + 1);
    //     }
    // }

    // cout << "Length of the longest substring: " << maxLen << endl;

    // 2. Better approach:
    int maxLen = 0;

    vector<int> freq(256, 0);
    int left = 0;
    int right = 0;

    while (right < n)
    {
        freq[s[right]]++;

        while (freq[s[right]] > 1)
        {
            freq[s[left]]--;
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
        right++;
    }

    cout << "Length of the longest substring: " << maxLen << endl;

    // 3. Optimal approach:
    int maxLen = 0;

    vector<int> lastIndex(256, -1);
    int left = 0;
    int right = 0;

    while (right < n)
    {
        if (lastIndex[s[right]] != -1 && lastIndex[s[right]] >= left)
            left = lastIndex[s[right]] + 1;

        lastIndex[s[right]] = right;

        maxLen = max(maxLen, right - left + 1);
        right++;
    }

    cout << "Length of the longest substring: " << maxLen << endl;

    return 0;
}
