// Problem: Count number of nice subarrays (Similar to binary subarrays with sum problem)
// - Leetcode: https://leetcode.com/problems/count-number-of-nice-subarrays/description
// - Return the number of nice subarrays and a subarray is nice if there are k odd numbers on it

// Solution:
// - Optimal approach: Use the sliding window technique to find the number of subarrays with at most k odd numbers and the number of subarrays with at most k - 1 odd numbers, then return the difference between them

// Time complexity:
// - Optimal approach: O(2 * 2n)

// Space complexity:
// - Optimal approach: O(1)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

// Find the number of subarrays with at most k odd numbers
int atMost(vector<int> nums, int k)
{
    if (k < 0)
        return 0;

    int count = 0;

    int sum = 0;
    int left = 0;
    int right = 0;

    while (right < nums.size())
    {
        sum += nums[right] % 2;

        while (sum > k)
        {
            sum -= nums[left] % 2;
            left++;
        }

        count += right - left + 1;

        right++;
    }

    return count;
}

int main()
{
    vector<int> nums = {1, 1, 2, 1, 1};
    int n = nums.size();

    int k = 3;

    // Optimal approach:
    int count = atMost(nums, k) - atMost(nums, k - 1);
    cout << "Number of nice subarrays: " << count << endl;

    return 0;
}
