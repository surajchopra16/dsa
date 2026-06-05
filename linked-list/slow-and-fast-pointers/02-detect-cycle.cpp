// Problem: Detect a cycle in the linked list
// - Leetcode: https://leetcode.com/problems/linked-list-cycle/description
// - Return true if there is a cycle in the linked list

// ⭐ Detect cycle:
// - Use the floyd's cycle detection algorithm
// - If there is a cycle, the fast pointer will eventually meet the slow pointer because the fast pointer moves two steps towards the slow pointer and slow pointer moves one step towards the fast pointer, thus reducing the distance between them by one step each iteration (2 - 1 = 1)

// Solution:
// - Brute force approach: Use a map to store the visited nodes, and check if the node is already visited before
// - Optimal approach: Use the two pointers (slow and fast) to traverse the linked list and check if the fast pointer meets the slow pointer

// Time complexity:
// - Brute force approach: O(n) * O(2 * log n)
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

int main()
{
    Node *head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(-4);
    head->next->next->next->next = head->next;

    // 1. Brute force approach:
    // map<Node *, bool> visited;

    // Node *curr = head;
    // while (curr != nullptr)
    // {
    //     if (visited.find(curr) != visited.end())
    //     {
    //         cout << "Cycle detected!" << endl;
    //         return 0;
    //     }
    //     visited[curr] = true;
    //     curr = curr->next;
    // }

    // cout << "No cycle detected!" << endl;

    // 2. Optimal approach:
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cout << "Cycle detected!" << endl;
            return 0;
        }
    }

    cout << "No cycle detected!" << endl;

    return 0;
}