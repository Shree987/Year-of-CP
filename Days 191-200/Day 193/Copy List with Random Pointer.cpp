/*
Author : Shreeraksha R Aithal
Problem name : Copy List with Random Pointer
Problem link : https://leetcode.com/problems/copy-list-with-random-pointer/
Difficulty : Medium
Tags : Hash Table, Linked List
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)        return head;
        unordered_map<Node*, Node*> mp;
        mp[nullptr] = nullptr;
        Node *root2, *root, *ptr = head;
        root2 = root = new Node(0);
        while(head != nullptr){
            root2->next = new Node(head->val);
            root2 = root2->next;
            mp[head] = root2;
            head = head->next;
        }
        head = ptr;
        root2 = root->next;
        while(head != nullptr){
            root2->random = mp[head->random];
            root2 = root2->next;
            head = head->next;
        }
        return root->next;
    }
};