// Problem: Start node of cycle in the linked list
// - Leetcode: https://leetcode.com/problems/linked-list-cycle-ii/
// - Return the node where the cycle begins

// Solution:
// - Brute force approach: Use a map to store the visited nodes, and check if the node is already visited before
// - Optimal approach: Use the same approach as detecting a cycle, but when the slow and fast pointers meet, reset one pointer to the head and move both pointers one step at a time until they meet again

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
    //         cout << "Starting node of cycle: " << curr->data << endl;
    //         return 0;
    //     }
    //     visited[curr] = true;
    //     curr = curr->next;
    // }

    // cout << "No cycle found in the linked list" << endl;

    // 2. Optimal approach:
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            cout << "Starting node of cycle: " << slow->data << endl;
            return 0;
        }
    }

    cout << "No cycle found in the linked list" << endl;

    return 0;
}