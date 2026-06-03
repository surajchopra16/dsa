// Problem: Subarrays with k different integers (Exactly K)
// - Leetcode: https://leetcode.com/problems/subarrays-with-k-different-integers/description
// - Return the number of good subarrays which contains exactly k different integers

// Solution:
// - Brute force approach: Generate all possible subarrays and check if they contain exactly k different integers
// - Optimal approach: Use a sliding window technique to find the number of subarrays with at most k different integers and the number of subarrays with at most k - 1 different integers and return the difference between them

// Time complexity:
// - Brute force approach: O(n^2)
// - Optimal approach: O(2 * 2n)

// Space complexity:
// - Brute force approach: O(k)
// - Optimal approach: O(2 * k)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

int atMost(vector<int> nums, int k)
{
    if (k < 0)
        return 0;

    int n = nums.size();

    int count = 0;
    unordered_map<int, int> mp;
    int left = 0;
    int right = 0;

    while (right < n)
    {
        mp[nums[right]]++;

        while (mp.size() > k)
        {
            mp[nums[left]]--;
            if (mp[nums[left]] == 0)
                mp.erase(nums[left]);

            left++;
        }

        count += right - left + 1;
        right++;
    }

    return count;
}

int main()
{
    vector<int> nums = {1, 2, 1, 3, 4};
    int k = 3;

    int n = nums.size();

    // 1. Brute force approach:
    // int count = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     unordered_map<int, int> mp;
    //     for (int j = i; j < n; j++)
    //     {
    //         mp[nums[j]]++;

    //         if (mp.size() == k)
    //             count++;
    //         else if (mp.size() > k)
    //             break;
    //     }
    // }

    // cout << "Number of subarrays: " << count << endl;

    // 2. Optimal approach:
    int count = atMost(nums, k) - atMost(nums, k - 1);
    cout << "Number of subarrays: " << count << endl;

    return 0;
}