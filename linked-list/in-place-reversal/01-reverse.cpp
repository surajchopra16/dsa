// Problem: Reverse a linked list
// - Leetcode: https://leetcode.com/problems/reverse-linked-list/description
// - Return the head of the linked list after reversing it

// Solution:
// - Brute force approach: Use a stack to store the values of the linked list and then pop the values from the stack and update the linked list to reverse it
// - Optimal approach: Use three pointers (prev, curr, next) to reverse the linked list in place

// Time complexity:
// - Brute force approach: O(2n)
// - Optimal approach: O(n)

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

// Print the linked list
void printLinkedList(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// Reverse the linked list
Node *reverse(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev; // Reverse the current node's pointer
        prev = curr;
        curr = next;
    }

    return prev;
}

// Reverse the linked list recursively
Node *reverseRecursive(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *newHead = reverseRecursive(head->next);

    Node *next = head->next;
    next->next = head;
    head->next = nullptr;

    return newHead;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

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
    //     curr->data = top;
    //     curr = curr->next;
    // }

    // printLinkedList(head);

    // 2. Optimal approach:
    head = reverse(head);
    printLinkedList(head);

    head = reverseRecursive(head);
    printLinkedList(head);

    return 0;
}