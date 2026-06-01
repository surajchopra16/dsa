// Problem: Max consecutive ones III (Longest subarray with at most K zeros)
// - Leetcode: https://leetcode.com/problems/max-consecutive-ones-iii/description
// - Return the maximum number of consecutive 1's in the array if you can flip at most K 0's

// Solution:
// - Brute force approach: Generate all possible subarrays and count the number of zeros in each subarray. If the count of zeros exceeds K, break the inner loop. Otherwise, update the maximum length of the subarray
// - Better approach: Use a sliding window approach with two pointers and a zero count. Expand the window with the right pointer and shrink the window with the left pointer when the count of zeros exceeds K until it becomes valid again
// - Optimal approach: Use a sliding window approach with two pointers and a zero count. Expand the window with the right pointer and shrink the window with the left pointer when the count of zeros exceeds K by only one step

// Time complexity:
// - Brute force approach: O(n^2)
// - Better approach: O(2n)
// - Optimal approach: O(n)

// Space complexity:
// - Brute force approach: O(1)
// - Better approach: O(1)
// - Optimal approach: O(1)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int n = nums.size();

    int k = 2;

    // 1. Brute force approach:
    // int maxLen = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     int zeroCount = 0;
    //     for (int j = i; j < n; j++)
    //     {
    //         if (nums[j] == 0)
    //             zeroCount++;

    //         if (zeroCount > k)
    //             break;

    //         maxLen = max(maxLen, j - i + 1);
    //     }
    // }

    // cout << "Max consecutive ones: " << maxLen << endl;

    // 2. Better approach:
    int maxLen = 0;

    int zeroCount = 0;
    int left = 0;
    int right = 0;

    while (right < n)
    {
        if (nums[right] == 0)
            zeroCount++;

        while (zeroCount > k)
        {
            if (nums[left] == 0)
                zeroCount--;
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
        right++;
    }

    cout << "Max consecutive ones: " << maxLen << endl;

    // 3. Optimal approach:
    int maxLen = 0;

    int zeroCount = 0;
    int left = 0;
    int right = 0;

    while (right < n)
    {
        if (nums[right] == 0)
            zeroCount++;

        if (zeroCount > k)
        {
            if (nums[left] == 0)
                zeroCount--;
            left++;
        }

        // Only update maxLen when the window is valid
        if (zeroCount <= k)
            maxLen = max(maxLen, right - left + 1);

        right++;
    }

    cout << "Max consecutive ones: " << maxLen << endl;

    return 0;
}
