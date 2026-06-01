// Problem: Longest repeating character replacement
// - Leetcode: https://leetcode.com/problems/longest-repeating-character-replacement/description
// - Return the length of the longest substring containing the same letter after performing at most K character replacements

// Solution:
// - Brute force approach: Generate all possible substrings and check whether the number of replacements needed (substring length - maximum character frequency) is at most K and keep track of the maximum length of valid substrings
// - Better approach: Use a sliding window approach with two pointers and a frequency array. Expand the window with the right pointer and shrink the window with the left pointer when the number of replacements needed exceeds K until it becomes valid again
// - Optimal approach: Use a sliding window approach with two pointers and a frequency array. Expand the window with the right pointer and shrink the window with the left pointer when the number of replacements needed exceeds K by only one step

// Time complexity:
// - Brute force approach: O(n^2)
// - Better approach: O(2n * 26)
// - Optimal approach: O(n)

// Space complexity:
// - Brute force approach: O(26)
// - Better approach: O(26)
// - Optimal approach: O(26)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "AABABBA";
    int n = s.size();

    int k = 1;

    // 1. Brute force approach:
    // int maxLen = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     vector<int> freq(26, 0);
    //     int maxFreq = 0;

    //     for (int j = i; j < n; j++)
    //     {
    //         freq[s[j] - 'A']++;
    //         maxFreq = max(maxFreq, freq[s[j] - 'A']);

    //         int replacements = (j - i + 1) - maxFreq;
    //         if (replacements > k)
    //             break;

    //         maxLen = max(maxLen, j - i + 1);
    //     }
    // }

    // cout << "Longest repeating character replacement: " << maxLen << endl;

    // 2. Better approach:
    int maxLen = 0;

    vector<int> freq(26, 0);
    int maxFreq = 0;
    int left = 0;
    int right = 0;

    while (right < n)
    {
        freq[s[right] - 'A']++;
        maxFreq = max(maxFreq, freq[s[right] - 'A']);

        while ((right - left + 1) - maxFreq > k)
        {
            freq[s[left] - 'A']--;
            maxFreq = 0;
            for (int f : freq)
                maxFreq = max(maxFreq, f);

            left++;
        }

        maxLen = max(maxLen, right - left + 1);
        right++;
    }

    cout << "Longest repeating character replacement: " << maxLen << endl;

    // 3. Optimal approach:
    int maxLen = 0;

    vector<int> freq(26, 0);
    int maxFreq = 0;
    int left = 0;
    int right = 0;

    while (right < n)
    {
        freq[s[right] - 'A']++;
        maxFreq = max(maxFreq, freq[s[right] - 'A']);

        if ((right - left + 1) - maxFreq > k)
        {
            freq[s[left] - 'A']--;
            left++;
        }

        if ((right - left + 1) - maxFreq <= k)
            maxLen = max(maxLen, right - left + 1);

        right++;
    }

    cout << "Longest repeating character replacement: " << maxLen << endl;

    return 0;
}
