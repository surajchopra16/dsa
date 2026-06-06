// Problem: Palindrome linked list
// - Leetcode: https://leetcode.com/problems/palindrome-linked-list/description
// - Return true if the given linked list is a palindrome

// Solution:
// - Brute force approach: Use a stack to store the elements and then compare the elements with the elements in the stack
// - Optimal approach: Find the middle of the linked list (first middle node in case of even length) and reverse the second half of the linked list and then compare the first half and the second half of the linked list

// Time complexity:
// - Brute force approach: O(2n)
// - Optimal approach: O(3n/2)

// Space complexity:
// - Brute force approach: O(n)
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

// Reverse the linked list
Node *reverse(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    // 1. Brute force approach:
    // stack<int> st;

    // Node *curr = head;
    // while (curr != nullptr)
    // {
    //     st.push(curr->data);
    //     curr = curr->next;
    // }

    // curr = head;
    // while (curr != nullptr)
    // {
    //     int top = st.top();
    //     st.pop();
    //     if (curr->data != top)
    //     {
    //         cout << "Not a palindrome" << endl;
    //         return 0;
    //     }
    //     curr = curr->next;
    // }

    // cout << "Palindrome" << endl;

    // 2. Optimal approach:
    Node *slow = head;
    Node *fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *newHead = reverse(slow->next);

    Node *first = head;
    Node *second = newHead;

    while (second != nullptr)
    {
        if (first->data != second->data)
        {
            cout << "Not a palindrome" << endl;
            return 0;
        }
        first = first->next;
        second = second->next;
    }

    cout << "Palindrome" << endl;

    return 0;
}