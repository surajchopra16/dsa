// Problem: Intersection of two linked lists
// - Leetcode: https://leetcode.com/problems/intersection-of-two-linked-lists/description
// - Return the node at which the intersection of two linked lists begins

// Solution:
// - Brute force approach: Use a map to store the nodes of the first linked list and then check for each node of the second linked list if it is visited or not
// - Better approach: Find the lengths of both linked lists and then move the pointer of the longer linked list ahead by the difference and then move both pointers one step at a time until they collide or reach the end
// - Optimal approach: Use two pointers to traverse both linked lists and when one pointer reaches the end, move it to the head of the other linked list and continue until they collide or reach the end

// Time complexity:
// - Brute force approach: O(n1 * log n1 + n2 * log n2)
// - Better approach: O(n1 + n2 + n2)
// - Optimal approach: O(n1 + n2)

// Space complexity:
// - Brute force approach: O(n1)
// - Better approach: O(1)
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

// Node *collision(Node *headA, Node *headB, int diff)
// {
//     Node *currA = headA;
//     Node *currB = headB;

//     for (int i = 0; i < diff; i++)
//         currB = currB->next;

//     while (currA != currB)
//     {
//         currA = currA->next;
//         currB = currB->next;
//     }

//     return currA;
// }

int main()
{
    Node *headA = new Node(4);
    headA->next = new Node(1);
    headA->next->next = new Node(8);
    headA->next->next->next = new Node(4);
    headA->next->next->next->next = new Node(5);

    Node *headB = new Node(5);
    headB->next = new Node(6);
    headB->next->next = new Node(1);
    headB->next->next->next = headA->next->next;

    // 1. Brute force approach:
    // map<Node *, bool> visited;

    // Node *curr = headA;
    // while (curr != nullptr)
    // {
    //     visited[curr] = true;
    //     curr = curr->next;
    // }

    // curr = headB;
    // while (curr != nullptr)
    // {
    //     if (visited.find(curr) != visited.end())
    //     {
    //         cout << "Intersection at node with value: " << curr->data << endl;
    //         return 0;
    //     }
    //     curr = curr->next;
    // }

    // cout << "No intersection found" << endl;

    // 2. Better approach:
    // int lengthA = 0;
    // int lengthB = 0;

    // Node *curr = headA;
    // while (curr != nullptr)
    // {
    //     lengthA++;
    //     curr = curr->next;
    // }

    // curr = headB;
    // while (curr != nullptr)
    // {
    //     lengthB++;
    //     curr = curr->next;
    // }

    // Node *node = nullptr;
    // if (lengthA < lengthB)
    //     node = collision(headA, headB, lengthB - lengthA);
    // else
    //     node = collision(headB, headA, lengthA - lengthB);

    // if (node == nullptr)
    //     cout << "No intersection found" << endl;
    // else
    //     cout << "Intersection at node with value: " << node->data << endl;

    // 3. Optimal approach:
    Node *currA = headA;
    Node *currB = headB;

    while (currA != currB)
    {
        currA = (currA == nullptr) ? headB : currA->next;
        currB = (currB == nullptr) ? headA : currB->next;
    }

    if (currA == nullptr)
        cout << "No intersection found" << endl;
    else
        cout << "Intersection at node with value: " << currA->data << endl;

    return 0;
}