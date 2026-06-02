// Problem: Maximum average subarray I
// - Leetcode: https://leetcode.com/problems/maximum-average-subarray-i/description
// - Leetcode: https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description (similar problem)
// - Return the maximum average value of a subarray of length k

// Solution:
// - Brute force approach: Generate all possible subarrays of length k, calculate their sums, and keep track of the maximum sum and finally return the maximum average by dividing the maximum sum by k
// - Optimal approach: Use a sliding window of size k, update the window sum by adding the next element and removing the previous one, and keep track of the maximum sum and finally return the maximum average by dividing the maximum sum by k

// Time complexity:
// - Brute force approach: O(n * k)
// - Optimal approach: O(n)

// Space complexity:
// - Brute force approach: O(1)
// - Optimal approach: O(1)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    int n = nums.size();

    // 1. Brute force approach:
    // int maxSum = INT_MIN;

    // for (int i = 0; i <= n - k; i++)
    // {
    //     int sum = 0;
    //     for (int j = i; j < i + k; j++)
    //         sum += nums[j];
    //     maxSum = max(maxSum, sum);
    // }

    // cout << "Maximum average of subarray: " << (double)maxSum / k << endl;

    // 2. Optimal approach:
    int maxSum = INT_MIN;

    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += nums[i];

    maxSum = sum;

    for (int i = k; i < n; i++)
    {
        sum += nums[i];
        sum -= nums[i - k];
        maxSum = max(maxSum, sum);
    }

    cout << "Maximum average of subarray: " << (double)maxSum / k << endl;

    return 0;
}
