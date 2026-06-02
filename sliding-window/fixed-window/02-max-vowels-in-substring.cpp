// Problem: Maximum number of vowels in a substring of given length
// - Leetcode: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description
// - Return the maximum number of vowel letters in any substring with length k

// Solution:
// - Optimal approach: Use a sliding window of size k, count the number of vowels in the initial window, and then slide the window across the string while updating the count of vowels by adding the next character and removing the previous character, and keep track of the maximum count of vowels

// Time complexity:
// - Optimal approach: O(n)

// Space complexity:
// - Optimal approach: O(1)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

// Check if a character is a vowel
bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()

{
    string s = "abciiidef";
    int k = 3;

    int n = s.length();

    // Optimal approach:
    int maxCount = INT_MIN;

    int count = 0;
    for (int i = 0; i < k; i++)
        if (isVowel(s[i]))
            count++;

    maxCount = count;

    for (int i = k; i < n; i++)
    {
        if (isVowel(s[i]))
            count++;
        if (isVowel(s[i - k]))
            count--;

        maxCount = max(maxCount, count);
    }

    cout << "Maximum number of vowels in a substring: " << maxCount << endl;

    return 0;
}