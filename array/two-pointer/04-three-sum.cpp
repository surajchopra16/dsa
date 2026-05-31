// Problem: Three sum
// - Leetcode: https://leetcode.com/problems/3sum/description
// - Return all the unique triplets in the array which gives the sum of zero

// Solution:
// - Brute force approach: Use three nested loops to check all the triplets of numbers and check if they add up to the zero
// - Better approach: Use two nested loops to fix the first two numbers and use a hash set to find the third number between the fixed two numbers
// - Optimal approach: Sort the array and use two pointers (left and right) to find if there are two numbers that add up to the zero

// Time complexity:
// - Brute force approach: O(n^3)
// - Better approach: O(n^2) * O(log m)
// - Optimal approach: O(n log n) + O(n^2)

// Space complexity:
// - Brute force approach: 2 * O(n)
// - Better approach: 2 * O(m) + O(m)
// - Optimal approach: O(n)

// ==================== Code ====================>

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Print all the triplets
void printTriplets(vector<vector<int>> triplets)
{
    for (vector<int> triplet : triplets)
    {
        cout << "[ ";
        for (int num : triplet)
            cout << num << " ";
        cout << "]";
    }
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int n = nums.size();

    // 1.Brute force approach:
    // set<vector<int>> st;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         for (int k = j + 1; k < n; k++)
    //         {
    //             if (nums[i] + nums[j] + nums[k] == 0)
    //             {
    //                 vector<int> triplet = {nums[i], nums[j], nums[k]};
    //                 sort(triplet.begin(), triplet.end());
    //                 st.insert(triplet);
    //             }
    //         }
    //     }
    // }

    // vector<vector<int>> ans(st.begin(), st.end());
    // printTriplets(ans);

    // 2. Better approach:
    // set<vector<int>> st;

    // for (int i = 0; i < n; i++)
    // {
    //     set<int> seen;
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         int more = -(nums[i] + nums[j]);
    //         if (seen.find(more) != seen.end())
    //         {
    //             vector<int> triplet = {nums[i], nums[j], more};
    //             sort(triplet.begin(), triplet.end());
    //             st.insert(triplet);
    //         }
    //         seen.insert(nums[j]);
    //     }
    // }

    // vector<vector<int>> ans(st.begin(), st.end());
    // printTriplets(ans);

    // 3. Optimal approach:
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i != 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0)
            {
                ans.push_back({nums[i], nums[left], nums[right]});

                left++;
                right--;

                while (left < right && nums[left] == nums[left - 1])
                    left++;
                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }
            else if (sum < 0)
                left++;
            else
                right--;
        }
    }

    printTriplets(ans);

    return 0;
}