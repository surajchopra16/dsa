// Problem: Permutation in string
// - Leetcode: https://leetcode.com/problems/permutation-in-string/description
// - Return true if one of s1's permutations is the substring of s2

// Similar problem:
// - Leetcode: https://leetcode.com/problems/find-all-anagrams-in-a-string/description

// Solution:
// - Optimal approach: Use a sliding window of size k (length of s1) and maintain frequency counts of characters in the current window of s2 and compare with frequency counts of s1

// Time complexity:
// - Optimal approach: O(n)

// Space complexity:
// - Optimal approach: O(1)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";

    int k = s1.length();
    int n = s2.length();

    // Edge case: If s1 is longer than s2, it's impossible for any permutation of s1 to be a substring of s2

    // Optimal approach:
    bool found = false;

    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);

    for (int i = 0; i < k; i++)
    {
        freq1[s1[i] - 'a']++;
        freq2[s2[i] - 'a']++;
    }

    if (freq1 == freq2)
        found = true;

    for (int i = k; i < n; i++)
    {
        freq2[s2[i] - 'a']++;
        freq2[s2[i - k] - 'a']--;

        if (freq1 == freq2)
        {
            found = true;
            break;
        }
    }

    cout << "Is one of s1's permutations a substring of s2? " << (found ? "Yes" : "No") << endl;

    return 0;
}
