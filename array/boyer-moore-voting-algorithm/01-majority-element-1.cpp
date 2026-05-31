// Problem: Majority element I
// - Leetcode: https://leetcode.com/problems/majority-element/description
// - Return the majority element, which is the element that appears more than n/2 times

// Solution:
// - Brute force approach: For each element, count its occurrences and check if it is the majority element
// - Better approach: Use a hash map to count the occurrences of each element and find the majority element
// - Optimal approach: Use the Boyer-moore voting algorithm

// Boyer-moore voting algorithm:
// - Traverse the array and maintain a candidate for the majority element and a count
// - If the count is 0, set the current element as the candidate and reset the count to 1
// - If the current element is the same as the candidate, increment the count else decrement the count
// - Verify if the candidate is the majority element by counting its occurrences in the array

// Time complexity:
// - Brute force approach: O(n^2)
// - Better approach: O(n) * O(log n)
// - Optimal approach: O(n) + O(n)

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
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int n = nums.size();

    // 1. Brute force approach:
    // for (int i = 0; i < n; i++)
    // {
    //     int count = 0;
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (nums[i] == nums[j])
    //             count++;
    //     }
    //     if (count > n / 2)
    //     {
    //         cout << "Majority element is: " << nums[i] << endl;
    //         break;
    //     }
    // }

    // 2. Better approach:
    // map<int, int> mp;

    // for (int i = 0; i < n; i++)
    // {
    //     mp[nums[i]]++;

    //     if (mp[nums[i]] == n / 2 + 1)
    //     {
    //         cout << "Majority element is: " << nums[i] << endl;
    //         break;
    //     }
    // }

    // 3. Optimal approach:
    int candidate = INT16_MIN;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            candidate = nums[i];
            count = 1;
        }
        else if (nums[i] == candidate)
            count++;
        else
            count--;
    }

    // Verify if the candidate is the majority element (Only when the majority element is not guaranteed to exist)
    count = 0;
    for (int i = 0; i < n; i++)
        if (nums[i] == candidate)
            count++;

    if (count > n / 2)
        cout << "Majority element is: " << candidate << endl;

    return 0;
}