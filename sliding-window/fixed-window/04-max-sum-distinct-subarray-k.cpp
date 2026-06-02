// Problem: Maximum sum of distinct subarrays with length K
// - Leetcode: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description
// - Return the maximum sum of a distinct subarray with length k

// Solution:
// - Optimal approach: Use a sliding window of size k and an frequency map. If the size of the frequency map is equal to k, it means all elements in the current window are distinct, and we can update the maximum sum accordingly

// Time complexity:
// - Optimal approach: O(n)

// Space complexity:
// - Optimal approach: O(k)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1, 5, 4, 2, 9, 9, 9};
    int k = 3;

    int n = nums.size();

    // Optimal approach:
    long long maxSum = 0;

    long long sum = 0;
    unordered_map<int, int> mp;

    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
        mp[nums[i]]++;
    }

    if (mp.size() == k)
        maxSum = max(maxSum, sum);

    for (int i = k; i < n; i++)
    {
        sum += nums[i];
        mp[nums[i]]++;

        sum -= nums[i - k];
        mp[nums[i - k]]--;
        if (mp[nums[i - k]] == 0)
            mp.erase(nums[i - k]);

        if (mp.size() == k)
            maxSum = max(maxSum, sum);
    }

    cout << "Maximum sum of distinct subarrays: " << maxSum << endl;

    return 0;
}
