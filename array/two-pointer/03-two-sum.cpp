// Problem: Two sum
// - Leetcode: https://leetcode.com/problems/two-sum/description
// - Return the yes/no if there are two numbers in the array that add up to the target
// - Return the indices of the two numbers such that they add up to the target (exactly one solution)

// Solution:
// - Brute force approach: Use two nested loops to check all pairs of numbers and check if they add up to the target
// - Better approach: Use a hash map to store (number, index) pairs. For each number, check if the more (target - current number) exists in the hash map of the previously seen numbers
// - Optimal approach: Sort the array and use two pointers (left and right) to find if there are two numbers that add up to the target (return yes/no only)

// Time complexity:
// - Brute force approach: O(n^2)
// - Better approach: O(n)
// - Optimal approach: O(n log n) + O(n)

// Space complexity:
// - Brute force approach: O(1)
// - Better approach: O(n)
// - Optimal approach: O(1)

// ==================== Code ====================>

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int n = nums.size();

    int target = 9;

    // 1. Brute force approach (works for both yes/no and indices questions):
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (nums[i] + nums[j] == target)
    //         {
    //             cout << "Indices: " << i << ", " << j << endl;
    //             return 0;
    //         }
    //     }
    // }

    // 2. Better approach (works for both yes/no and indices questions):
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int more = target - nums[i];

        if (mp.find(more) != mp.end())
        {
            cout << "Indices: " << mp[more] << ", " << i << endl;
            break;
        }

        mp[nums[i]] = i;
    }

    // 3. Optimal approach (works for yes/no question only):
    sort(nums.begin(), nums.end());

    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int sum = nums[left] + nums[right];

        if (sum == target)
        {
            cout << "Yes" << endl;
            return 0;
        }
        else if (sum < target)
            left++;
        else
            right--;
    }

    cout << "No" << endl;

    return 0;
}