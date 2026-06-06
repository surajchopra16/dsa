// Problem: Sliding window maximum
// - Leetcode: https://leetcode.com/problems/sliding-window-maximum
// - Return the maximum value in each sliding window of size k

// Solution:
// - Brute force approach: Use a sliding window of size k and find the maximum element in each window
// - Optimal approach: Use a sliding window of size k and maintain a deque of indices in monotonically decreasing order for the current window. The front of the deque always contains the index of the maximum element in the current window.

// Time complexity:
// - Brute force approach: O(n * k)
// - Optimal approach: O(n)

// Space complexity:
// - Brute force approach: O(n - k + 1)
// - Optimal approach: O(n - k + 1)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

// Print the vector
void printVector(vector<int> nums)
{
    cout << "Sliding window maximum: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    int n = nums.size();

    // 1. Brute force approach:
    // vector<int> result;

    // int maxElement = INT_MIN;
    // for (int i = 0; i < k; i++)
    //     maxElement = max(maxElement, nums[i]);

    // result.push_back(maxElement);

    // for (int i = k; i < n; i++)
    // {
    //     maxElement = *max_element(nums.begin() + i - k + 1, nums.begin() + i + 1);
    //     result.push_back(maxElement);
    // }

    // printVector(result);

    // 2. Optimal approach:
    vector<int> result;

    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && nums[i] > nums[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }

    result.push_back(nums[dq.front()]);

    for (int i = k; i < n; i++)
    {
        while (!dq.empty() && dq.front() < i - k + 1)
            dq.pop_front();

        while (!dq.empty() && nums[i] > nums[dq.back()])
            dq.pop_back();
        dq.push_back(i);

        result.push_back(nums[dq.front()]);
    }

    printVector(result);

    return 0;
}