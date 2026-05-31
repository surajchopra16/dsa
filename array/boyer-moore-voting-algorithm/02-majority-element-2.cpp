// Problem: Majority element II
// - Leetcode: https://leetcode.com/problems/majority-element-ii/description
// - Return all the majority elements that appear more than n/3 times (at most 2 elements)

// Solution:
// - Brute force approach: For each element, count its occurrences and check if it is a majority element
// - Better approach: Use a hash map to count the occurrences of each element and find the majority elements
// - Optimal approach: Use the Boyer-moore voting algorithm (extended version for n/3)

// Edge cases:
// - Check if the selected candidates should not be the same in the loop

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

// Print the vector of majority elements
void printVector(vector<int> ans)
{
    cout << "Majority elements are: ";
    for (int num : ans)
        cout << num << " ";
    cout << endl;
}

int main()
{
    vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};
    int n = nums.size();

    // 1. Brute force approach:
    // vector<int> ans;

    // for (int i = 0; i < n; i++)
    // {
    //     if (ans.size() == 0 || ans[0] != nums[i])
    //     {
    //         int count = 0;
    //         for (int j = 0; j < n; j++)
    //         {
    //             if (nums[i] == nums[j])
    //                 count++;
    //         }
    //         if (count > n / 3)
    //             ans.push_back(nums[i]);
    //     }

    //     if (ans.size() == 2)
    //         break;
    // }

    // printVector(ans);

    // 2. Better approach:
    // vector<int> ans;
    // map<int, int> mp;

    // for (int i = 0; i < n; i++)
    // {
    //     mp[nums[i]]++;

    //     if (mp[nums[i]] == n / 3 + 1)
    //         ans.push_back(nums[i]);
    // }

    // printVector(ans);

    // 3. Optimal approach:
    int candidate1 = INT16_MIN, candidate2 = INT16_MIN;
    int count1 = 0, count2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (count1 == 0 && nums[i] != candidate2)
        {
            candidate1 = nums[i];
            count1 = 1;
        }
        else if (count2 == 0 && nums[i] != candidate1)
        {
            candidate2 = nums[i];
            count2 = 1;
        }
        else if (nums[i] == candidate1)
            count1++;
        else if (nums[i] == candidate2)
            count2++;
        else
        {
            count1--;
            count2--;
        }
    }

    // Verify the candidates are the majority elements (Only when the majority elements are not guaranteed to exist)
    vector<int> ans;

    count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == candidate1)
            count1++;
        if (nums[i] == candidate2)
            count2++;
    }

    if (count1 > n / 3)
        ans.push_back(candidate1);
    if (count2 > n / 3)
        ans.push_back(candidate2);

    printVector(ans);

    return 0;
}