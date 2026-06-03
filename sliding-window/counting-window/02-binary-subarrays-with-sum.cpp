// Problem: Binary subarrays with sum (Exactly K)
// - Leetcode: https://leetcode.com/problems/binary-subarrays-with-sum/description
// - Return the number of non-empty subarrays that have a sum equal to the goal

// ⭐ Formula:
// - Number of subarrays with exactly k = Number of subarrays with at most k - Number of subarrays with at most k - 1
// - Exactly (K) = At most (K) - At most (K - 1)

// Solution:
// - Brute force approach: Generate all possible subarrays and check if the sum of the subarray is equal to the goal
// - Optimal approach: Use a sliding window approach to find the number of subarrays with sum at most equal to the goal and the number of subarrays with sum at most equal to the goal - 1 and subtract the two to get the number of subarrays with sum equal to the goal

// Time complexity:
// - Brute force approach: O(n^2)
// - Optimal approach: O(2 * 2n)

// Space complexity:
// - Brute force approach: O(1)
// - Optimal approach: O(1)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

// Find the number of subarrays with sum at most equal to the goal
int atMost(vector<int> nums, int goal)
{
    if (goal < 0)
        return 0;

    int n = nums.size();

    int count = 0;

    int sum = 0;
    int left = 0;
    int right = 0;

    while (right < n)
    {
        sum += nums[right];

        while (sum > goal)
        {
            sum -= nums[left];
            left++;
        }

        count += right - left + 1;
        right++;
    }

    return count;
}

int main()
{
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    int n = nums.size();

    // 1. Brute force approach:
    // int count = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     int sum = 0;
    //     for (int j = i; j < n; j++)
    //     {
    //         sum += nums[j];
    //         if (sum == goal)
    //             count++;
    //     }
    // }

    // cout << "Number of subarrays: " << count << endl;

    // 2. Optimal approach:
    int count = atMost(nums, goal) - atMost(nums, goal - 1);
    cout << "Number of subarrays: " << count << endl;

    return 0;
}
