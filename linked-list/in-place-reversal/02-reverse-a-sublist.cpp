// Problem: Reverse a sublist of the linked list
// - Leetcode: https://leetcode.com/problems/reverse-linked-list-ii/description
// - Return the head of the linked list after reversing the nodes from left to right

// Solution:
// - Optimal approach: Use five pointers (prevStart, start, prev, curr, next) to reverse the sublist of the linked list in place

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
    head->next->next->next->next = new Node(5);

    int left = 2;
    int right = 4;

    // Optimal approach:
    Node *dummy = new Node(-1);
    dummy->next = head;

    Node *prevStart = dummy;
    for (int i = 1; i < left; i++)
        prevStart = prevStart->next;

    Node *start = prevStart->next;

    Node *prev = nullptr;
    Node *curr = start;
    Node *next = nullptr;

    for (int i = left; i <= right; i++)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    prevStart->next = prev;
    start->next = curr;

    printLinkedList(dummy->next);

    return 0;
}