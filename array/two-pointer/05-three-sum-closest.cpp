// Problem: Three sum closest
// - Leetcode: https://leetcode.com/problems/3sum-closest/description
// - Return the sum of the three integers that is closest to the target. You may assume only one solution exists

// Solution:
// - Optimal approach: Sort the array and use two pointers to find the closest sum of three integers to the target

// Time complexity:
// - Optimal approach: O(n^2)

// Space complexity:
// - Optimal approach: O(1)

// ==================== Code ====================>

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    int n = nums.size();

    int target = 1;

    // Optimal approach:
    long long closestSum = nums[0] + nums[1] + nums[2];

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        // Skip the duplicate elements
        if (i != 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (abs(target - sum) < abs(target - closestSum))
                closestSum = sum;

            if (sum == target)
                return sum;
            else if (sum < target)
                left++;
            else
                right--;
        }
    }

    cout << "Closest sum: " << closestSum;

    return 0;
}
