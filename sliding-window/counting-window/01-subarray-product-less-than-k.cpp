// Problem: Subarray product less than k (At most K)
// - Leetcode: https://leetcode.com/problems/subarray-product-less-than-k/description
// - Return the number of subarrays where the product of all the elements in the subarray is less than k

// ⭐ Formula:
// - Number of subarrays formed by adding the new element to the window = (right - left + 1)

// Solution:
// - Brute force approach: Generate all possible subarrays and check if the product of the subarray is less than k
// - Optimal approach: Use a sliding window approach and a product variable. Expand the window by adding the right element to the product and shrink the window from the left if the product is greater than or equal to k. Increment the count by the number of subarrays formed by adding the new element to the window

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
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;

    int n = nums.size();

    // 1. Brute force approach:
    // int count = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     int product = 1;
    //     for (int j = i; j < n; j++)
    //     {
    //         product *= nums[j];

    //         if (product < k)
    //             count++;
    //         else
    //             break;
    //     }
    // }

    // cout << "Number of subarrays: " << count << endl;

    // 2. Optimal approach:
    int count = 0;

    int product = 1;
    int left = 0;
    int right = 0;

    while (right < n)
    {
        product *= nums[right];

        while (product >= k && left <= right)
        {
            product /= nums[left];
            left++;
        }

        count += (right - left + 1);
        right++;
    }

    cout << "Number of subarrays: " << count << endl;

    return 0;
}