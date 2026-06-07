// Problem: Reverse nodes in k-group
// - Leetcode: https://leetcode.com/problems/reverse-nodes-in-k-group/description
// - Return the head of the linked list after reversing the nodes in k-group

// Solution:
// - Optimal approach: Use seven pointers (prevGroup, start, end, nextGroup, prev, curr, next) to reverse nodes in k-group

// Time complexity:
// - Optimal approach: O(2n)

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

    int k = 2;

    // Optimal approach:
    Node *dummy = new Node(-1);
    dummy->next = head;

    Node *prevGroup = dummy;

    while (true)
    {
        Node *start = prevGroup->next;
        Node *end = prevGroup;

        for (int i = 0; i < k && end != nullptr; i++)
            end = end->next;

        if (end == nullptr)
            break;

        Node *nextGroup = end->next;

        // Reverse the current group
        Node *prev = nullptr;
        Node *curr = start;
        Node *next = nullptr;

        while (curr != nextGroup) // Reverse until we reach the next group
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        prevGroup->next = end;
        start->next = nextGroup;

        prevGroup = start;
    }

    printLinkedList(dummy->next);

    return 0;
}