// Problem: Swap nodes in pairs
// - Leetcode: https://leetcode.com/problems/swap-nodes-in-pairs/description
// - Return the head of the linked list after swapping every two adjacent nodes

// Solution:
// - Optimal approach: Use three pointers (prev, first, second) to swap nodes in pairs

// Time complexity:
// - Optimal approach: O(n)

// Space complexity:
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

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Optimal approach:
    Node *dummy = new Node(-1);
    dummy->next = head;

    Node *prev = dummy;

    while (prev->next != nullptr && prev->next->next != nullptr)
    {
        Node *first = prev->next;
        Node *second = first->next;

        first->next = second->next;
        second->next = first;
        prev->next = second;

        prev = first;
    }

    printLinkedList(dummy->next);

    return 0;
}