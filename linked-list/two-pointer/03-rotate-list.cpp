// Problem: Rotate list
// - Leetcode: https://leetcode.com/problems/rotate-list/description
// - Return the head of the linked list after rotating the list to the right by k places

// Solution:
// - Optimal approach: Find the length of the linked list and make it circular linked list and then break the circular linked list at the length - k position

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
    int length = 1;
    Node *tail = head;
    while (tail->next != nullptr)
    {
        length++;
        tail = tail->next;
    }

    k = k % length;
    if (k == 0)
    {
        printLinkedList(head);
        return 0;
    }

    // Rotate the linked list
    tail->next = head;

    int position = length - k;

    Node *curr = head;
    for (int i = 1; i < position; i++)
        curr = curr->next;

    head = curr->next;
    curr->next = nullptr;

    printLinkedList(head);

    return 0;
}