// Problems:
// - Reverse an array using recursion
// - Check if a string is a palindrome using recursion

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

// Reverse an array using recursion
void reverseArray(int arr[], int left, int right)
{
    if (left >= right)
        return;

    swap(arr[left], arr[right]);

    reverseArray(arr, left + 1, right - 1);
}

// Check if a string is a palindrome using recursion
bool checkPalindrome(string str, int left, int right)
{
    if (left >= right)
        return true;

    if (str[left] != str[right])
        return false;

    return checkPalindrome(str, left + 1, right - 1);
}

int main()
{
    int n = 5;
    int nums[n] = {1, 2, 3, 4, 5};

    cout << "Array: ";
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";

    cout << endl;
    reverseArray(nums, 0, n - 1);

    cout << "Reversed Array: ";
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";

    cout << endl;

    string str = "12321";

    bool isPalindrome = checkPalindrome(str, 0, str.length() - 1);
    cout << "Is palindrome: " << (isPalindrome ? "Yes" : "No") << endl;

    return 0;
}