// Problem: Four sum
// - Leetcode: https://leetcode.com/problems/4sum/description
// - Return all the unique quadruplets in the array which add up to the target

// Solution:
// - Brute force approach: Use four nested loops to check all the quadruplets of numbers and check if they add up to the target
// - Better approach: Use three nested loops to fix the first three numbers and use a hash set to find the fourth number between the fixed three numbers
// - Optimal approach: Sort the array and use two nested loops to fix the first two numbers and use two pointers (left and right) to find if there are two numbers that add up to the target

// Time complexity:
// - Brute force approach: O(n^4)
// - Better approach: O(n^3) * O(log m)
// - Optimal approach: O(n log n) + O(n^3)

// Space complexity:
// - Brute force approach: 2 * O(m)
// - Better approach: 2 * O(m) + O(m)
// - Optimal approach: O(n)

// ==================== Code ====================>

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Print all the quadruplets
void printQuadruplets(vector<vector<int>> quadruplets)
{
    for (vector<int> quadruplet : quadruplets)
    {
        cout << "[ ";
        for (int num : quadruplet)
            cout << num << " ";
        cout << "]";
    }
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int n = nums.size();

    int target = 0;

    // 1.Brute force approach:
    // set<vector<int>> st;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         for (int k = j + 1; k < n; k++)
    //         {
    //             for (int l = k + 1; l < n; l++)
    //             {
    //                 if (nums[i] + nums[j] + nums[k] + nums[l] == target)
    //                 {
    //                     vector<int> quadruplet = {nums[i], nums[j], nums[k], nums[l]};
    //                     sort(quadruplet.begin(), quadruplet.end());
    //                     st.insert(quadruplet);
    //                 }
    //             }
    //         }
    //     }
    // }

    // vector<vector<int>> ans(st.begin(), st.end());
    // printQuadruplets(ans);

    // 2. Better approach:
    // set<vector<int>> st;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         set<int> seen;
    //         for (int k = j + 1; k < n; k++)
    //         {
    //             int more = target - (nums[i] + nums[j] + nums[k]);
    //             if (seen.find(more) != seen.end())
    //             {
    //                 vector<int> quadruplet = {nums[i], nums[j], nums[k], more};
    //                 sort(quadruplet.begin(), quadruplet.end());
    //                 st.insert(quadruplet);
    //             }
    //             seen.insert(nums[k]);
    //         }
    //     }
    // }

    // vector<vector<int>> ans(st.begin(), st.end());
    // printQuadruplets(ans);

    // 3. Optimal approach:
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i != 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            if (j != i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1;
            int right = n - 1;

            while (left < right)
            {
                // Use the long long and chained addition to avoid integer overflow
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[left];
                sum += nums[right];

                if (sum == target)
                {
                    ans.push_back({nums[i], nums[j], nums[left], nums[right]});

                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
                else if (sum < target)
                    left++;
                else
                    right--;
            }
        }
    }

    printQuadruplets(ans);

    return 0;
}