// Problem: Number of substrings containing all three characters (At least K)
// - Leetcode: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description
// - Return the number of substrings that contain at least one occurrence of all three characters: a, b, and c

// ⭐ Formula:
// - Once we have a valid window (contains all three characters), all its extensions to the right will also be valid
// - Number of valid substrings = (n - right)

// Solution:
// - Brute force approach: Generate all possible substrings and check if they contain all three characters
// - Optimal approach: Use a sliding window of the size 3a and maintain a frequency vector. Expand the window by moving the right pointer and shrink it by moving the left pointer until all three characters are present. Count the valid substrings at each step

// Time complexity:
// - Brute force approach: O(n^2)
// - Optimal approach: O(n)

// Space complexity:
// - Brute force approach: O(1)
// - Optimal approach: O(1)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abcabc";

    int n = s.size();

    // 1. Brute force approach:
    // int count = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     vector<int> freq(3, 0);
    //     for (int j = i; j < n; j++)
    //     {
    //         freq[s[j] - 'a']++;

    //         if (freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
    //             count++;
    //     }
    // }

    // cout << "Number of substrings containing all three characters: " << count << endl;

    // 2. Optimal approach:
    int count = 0;

    vector<int> freq(3, 0);
    int left = 0;
    int right = 0;

    while (right < n)
    {
        freq[s[right] - 'a']++;

        // Shrink the window until it is valid (contains all three characters)
        while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
        {
            count += n - right;

            freq[s[left] - 'a']--;
            left++;
        }

        right++;
    }

    cout << "Number of substrings containing all three characters: " << count << endl;

    return 0;
}
