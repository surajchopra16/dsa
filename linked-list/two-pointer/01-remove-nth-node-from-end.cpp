// Problem: Remove nth node from end of the linked list
// - Leetcode: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description
// - Return the head after removing the nth node from the end of the linked list

// ⭐ Edge case: If the length is equal to n, then we need to remove the head node

// Solution:
// - Brute force approach: Find the length of the linked list and then remove the nth node from the end
// - Optimal approach: Use two pointers to find the nth node from the end in one pass by moving the second pointer n steps ahead and then moving both pointers until the second pointer reaches the end

// Time complexity:
// - Brute force approach: O(n + n)
// - Optimal approach: O(n)

// Space complexity:
// - Brute force approach: O(1)
// - Optimal approach: O(1)

// ==================== Code ====================>

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int n = 2;

    // 1. Brute force approach:
    // int length = 0;

    // Node *curr = head;
    // while (curr != nullptr)
    // {
    //     length++;
    //     curr = curr->next;
    // }

    // if (length == n)
    // {
    //     Node *temp = head;
    //     head = head->next;
    //     delete temp;
    //     return 0;
    // }

    // int end = length - n;

    // curr = head;
    // while (curr != nullptr)
    // {
    //     end--;
    //     if (end == 0)
    //         break;
    //     curr = curr->next;
    // }

    // Node *temp = curr->next;
    // curr->next = curr->next->next;
    // delete temp;

    // 2. Optimal approach:
    Node *slow = head;
    Node *fast = head;

    for (int i = 0; i < n; i++)
        fast = fast->next;

    if (fast == nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return 0;
    }

    while (fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    return 0;
}