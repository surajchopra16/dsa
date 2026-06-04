// Problem: Minimum size subarray sum
// - Leetcode: https://leetcode.com/problems/minimum-size-subarray-sum
// - Return the minimal length of a subarray whose sum is greater than or equal to target

// ⭐ Shortest window approach:
// - Expand the window until the window is invalid
// - Shrink the window until the window is valid to get the shortest window

// Solution:
// - Brute force approach: Generate all possible subarrays and check if their sum is greater than or equal to target
// - Optimal approach: Use a sliding window approach and a minimum length variable. Expand the window when the sum is less than target and shrink the window when the sum is greater than or equal to target and update the minimum length accordingly

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
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    int n = nums.size();

    // 1. Brute force approach:
    // int minLen = INT_MAX;

    // for (int i = 0; i < n; i++)
    // {
    //     int sum = 0;
    //     for (int j = i; j < n; j++)
    //     {
    //         sum += nums[j];

    //         if (sum >= target)
    //         {
    //             minLen = min(minLen, j - i + 1);
    //             break;
    //         }
    //     }
    // }

    // cout << "Minimum length: " << (minLen == INT_MAX ? 0 : minLen) << endl;

    // 2. Optimized approach:
    int minLen = INT_MAX;

    int sum = 0;
    int left = 0;
    int right = 0;

    while (right < n)
    {
        sum += nums[right];

        while (sum >= target)
        {
            minLen = min(minLen, right - left + 1);

            sum -= nums[left];
            left++;
        }

        right++;
    }

    cout << "Minimum length: " << (minLen == INT_MAX ? 0 : minLen) << endl;

    return 0;
}