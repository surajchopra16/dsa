// Problem: Rearrange array elements by sign
// - Leetcode: https://leetcode.com/problems/rearrange-array-elements-by-sign/description
// - Return an array where positive and negative numbers are placed in alternating positions and relative order is preserved
// - (a). Array contains equal number of positive and negative numbers
// - (b). Array contains unequal number of positive and negative numbers

// Solution:
// - Brute force approach: Create two separate arrays for positive and negative numbers, then merge them by alternating elements from both arrays (work for both types of questions)
// - Optimal approach: Use two pointers to place positive and negative numbers in the correct positions (work for only a type of question)

// Time complexity:
// - Brute force approach: 2 * O(n)
// - Optimal approach: O(n)

// Space complexity:
// - Brute force approach: 2 * O(n)
// - Optimal approach: O(n)

// ==================== Code ====================>

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Print the vector
void printVector(vector<int> nums)
{
    for (int num : nums)
        cout << num << ", ";
    cout << endl;
}

int main()
{
    // (a). Array contains equal number of positive and negative numbers
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    int n = nums.size();

    // 1. Brute force approach:
    // vector<int> ans;
    // vector<int> pos;
    // vector<int> neg;

    // for (int num : nums)
    // {
    //     if (num >= 0)
    //         pos.push_back(num);
    //     else
    //         neg.push_back(num);
    // }

    // for (int i = 0; i < n / 2; i++)
    // {
    //     ans.push_back(pos[i]);
    //     ans.push_back(neg[i]);
    // }

    // printVector(ans);

    // 2. Optimal approach:
    vector<int> ans(n);

    int posIndex = 0;
    int negIndex = 1;

    for (int num : nums)
    {
        if (num > 0)
        {
            ans[posIndex] = num;
            posIndex += 2;
        }
        else
        {
            ans[negIndex] = num;
            negIndex += 2;
        }
    }

    printVector(ans);

    // (b). Array contains unequal number of positive and negative numbers
    vector<int> nums2 = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int n2 = nums2.size();

    // 1. Brute force approach:
    vector<int> ans2(n2);
    vector<int> pos2;
    vector<int> neg2;

    for (int num : nums2)
    {
        if (num >= 0)
            pos2.push_back(num);
        else
            neg2.push_back(num);
    }

    int i = 0, j = 0, k = 0;

    while (i < pos2.size() && j < neg2.size())
    {
        ans2[k++] = pos2[i++];
        ans2[k++] = neg2[j++];
    }

    while (i < pos2.size())
        ans2[k++] = pos2[i++];

    while (j < neg2.size())
        ans2[k++] = neg2[j++];

    printVector(ans2);

    return 0;
}