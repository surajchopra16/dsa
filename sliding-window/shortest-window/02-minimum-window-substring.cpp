// Problem: Minimum Window Substring
// - Leetcode: https://leetcode.com/problems/minimum-window-substring/description
// - Return the minimum window (shortest) substring of s that contains all the characters of t

// Solution:
// - Optimal approach: Use a sliding window approach and a frequency array. Expand the window until the window contains all characters of t and then try to shrink the window from the left to find the minimum length

// Time complexity:
// - Optimal approach: O(2n + m)

// Space complexity:
// - Optimal approach: O(256)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    int n = s.size();
    int m = t.size();

    if (m > n)
    {
        cout << "Minimum window substring: " << "" << endl;
        return 0;
    }

    // Optimal approach:
    vector<int> freq(256, 0);
    for (char c : t)
        freq[c]++;

    int minLen = INT_MAX;
    int start = -1;
    int count = 0;

    int left = 0;
    int right = 0;

    while (right < n)
    {
        if (freq[s[right]] > 0)
            count++;
        freq[s[right]]--;

        while (count == m)
        {
            if (right - left + 1 < minLen)
            {
                minLen = right - left + 1;
                start = left;
            }

            freq[s[left]]++;
            if (freq[s[left]] > 0)
                count--;

            left++;
        }

        right++;
    }

    cout << "Minimum window substring: " << (start == -1 ? "" : s.substr(start, minLen)) << endl;

    return 0;
}