// Problem: Container with most water
// - Leetcode: https://leetcode.com/problems/container-with-most-water/description
// - Return the maximum amount of water a container can store, where the container is formed by two lines drawn on the x-axis and the x-axis itself

// Solution:
// - Brute force approach: Use two nested loops to calculate the area formed by every pair of lines and keep track of the maximum volume
// - Optimal approach: Use two pointers, one at the start and one at the end of the array, and calculate the volume formed by the lines at these pointers

// Time complexity:
// - Brute force approach: O(n^2)
// - Optimal approach: O(n)

// Space complexity:
// - Brute force approach: O(1)
// - Optimal approach: O(1)

// ==================== Code ====================>

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = height.size();

    // 1. Brute force approach:
    // int maxVolume = INT_MIN;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         int volume = min(height[i], height[j]) * (j - i);
    //         maxVolume = max(maxVolume, volume);
    //     }
    // }

    // cout << "Max volume: " << maxVolume << endl;

    // 2. Optimal approach:
    int maxVolume = INT_MIN;

    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int volume = min(height[left], height[right]) * (right - left);
        maxVolume = max(maxVolume, volume);

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    cout << "Max volume: " << maxVolume << endl;

    return 0;
}