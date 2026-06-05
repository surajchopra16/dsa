// Problem: Length of cycle in a linked list
// - GFG: https://www.geeksforgeeks.org/problems/find-length-of-loop/1
// - Return the length of the cycle in a linked list

// Solution:
// - Brute force approach: Use a map to store the visited nodes and their indices, and when we encounter a visited node, we can calculate the length of the cycle by (current index - index of the visited node)
// - Optimal approach: Use the same approach as detecting a cycle, but when the slow and fast pointers meet, we can keep one pointer fixed and move the other pointer until they meet again

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
    // map<Node *, int> visited;
    // int counter = 1;

    // Node *curr = head;
    // while (curr != nullptr)
    // {
    //     if (visited.find(curr) != visited.end())
    //     {
    //         cout << "Length of cycle: " << counter - visited[curr] << endl;
    //         return 0;
    //     }
    //     visited[curr] = counter++;
    //     curr = curr->next;
    // }

    // cout << "Length of cycle: 0" << endl;

    // 2. Optimal approach:
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            int length = 1;
            fast = fast->next;
            while (slow != fast)
            {
                length++;
                fast = fast->next;
            }
            cout << "Length of cycle: " << length << endl;
            return 0;
        }
    }

    cout << "Length of cycle: 0" << endl;

    return 0;
}