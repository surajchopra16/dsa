// Problem: Binary subarrays with sum
// - Leetcode: https://leetcode.com/problems/binary-subarrays-with-sum/description
// - Return the number of non-empty subarrays that have a sum equal to goal

// Solution:
// - Brute force approach: Generate all possible subarrays and count the number of subarrays with sum equal to the given goal
// - Optimal approach: Use the sliding window technique to find the number of subarrays with sum at most equal to the given goal and subtract the number of subarrays with sum at most equal to the given goal - 1

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

    int count = 0;

    int sum = 0;
    int left = 0;
    int right = 0;

    while (right < nums.size())
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
    int n = nums.size();

    int goal = 2;

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

    // cout << "Number of subarrays with sum: " << count << endl;

    // 2. Optimal approach:
    int count = atMost(nums, goal) - atMost(nums, goal - 1);
    cout << "Number of subarrays with sum: " << count << endl;

    return 0;
}
