// Problem: Middle of the linked list
// - Leetcode: https://leetcode.com/problems/middle-of-the-linked-list/description
// - Return the middle node of the linked list

// Similar problem:
// - Leetcode: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description
// - Initially, we move the fast pointer two steps ahead and then apply the slow and fast pointer approach to land on the node just before the middle node

// ⭐ Middle node:
// - Use the tortoise and hare algorithm
// - For odd number of nodes, return the middle node
// - For even number of nodes, return the second middle node
// - Middle node is (n/2 + 1)th node

// Solution:
// - Brute force approach: Find the length of the linked list and traverse again to find the middle node
// - Optimal approach: Use two pointers (slow and fast). Move slow by one step and fast by two steps, when fast reaches the end, slow will be at the middle node

// Time complexity:
// - Brute force approach: O(n + n/2)
// - Optimal approach: O(n/2)

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
    head->next->next->next->next->next = new Node(6);

    // 1. Brute force approach:
    // int length = 0;

    // Node *curr = head;
    // while (curr != nullptr)
    // {
    //     length++;
    //     curr = curr->next;
    // }

    // int mid = (length / 2) + 1;

    // curr = head;
    // while (curr != nullptr)
    // {
    //     mid--;
    //     if (mid == 0)
    //         break;
    //     curr = curr->next;
    // }

    // cout << "Middle node: " << curr->data << endl;

    // 2. Optimal approach:
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle node: " << slow->data << endl;

    return 0;
}