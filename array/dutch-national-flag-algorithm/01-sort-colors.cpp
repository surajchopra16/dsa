// Problem: Sort colors (0s, 1s and 2s)
// - Leetcode: https://leetcode.com/problems/sort-colors/description

// Solution:
// - Brute force approach: Sort the array using the sorting algorithm (merge sort)
// - Better approach: Count the number of 0s, 1s and 2s in the array and then fill the array with the counted values
// - Optimal approach: Use the Dutch National Flag algorithm

// Dutch National Flag algorithm:
// - It is a three pointer approach where we maintain three pointers: low, mid and high
// - Initially, low and mid are at the beginning of the array and high is at the end of the array
// - It divides the array into four sections:
// - [0 ..... low - 1] -> 0s
// - [low ..... mid - 1] -> 1s
// - [mid ..... high] -> unsorted
// - [high + 1 ..... n - 1] -> 2s

// Time complexity:
// - Brute force approach: O(n log n)
// - Better approach: O(n) + O(n)
// - Optimal approach: O(n)

// Space complexity:
// - Brute force approach: O(n)
// - Better approach: O(1)
// - Optimal approach: O(1)

// ==================== Code ====================>

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Print the vector
void printVector(vector<int> &nums)
{
    cout << "Sorted array: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    int n = nums.size();

    // 1. Brute force approach:
    // sort(nums.begin(), nums.end());
    // printVector(nums);

    // 2. Better approach:
    // int count0 = 0, count1 = 0, count2 = 0;

    // for (int num : nums)
    // {
    //     if (num == 0)
    //         count0++;
    //     else if (num == 1)
    //         count1++;
    //     else
    //         count2++;
    // }

    // for (int i = 0; i < count0; i++)
    //     nums[i] = 0;
    // for (int i = count0; i < count0 + count1; i++)
    //     nums[i] = 1;
    // for (int i = count0 + count1; i < nums.size(); i++)
    //     nums[i] = 2;

    // printVector(nums);

    // 3. Optimal approach:
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }

    printVector(nums);

    return 0;
}