/*
Author : Shreeraksha R Aithal
Problem name : Flatten a Multilevel Doubly Linked List
Problem link : https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
Difficulty : Medium
Tags : Depth-First Search, Doubly-Linked List, Linked List
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr)     return nullptr;
        stack<Node*> st;
        st.push(head);
        Node *root, *prev;
        prev = new Node;
        root = nullptr;
        head = prev;
        while(root!= nullptr || !st.empty()){
            if(root == nullptr){
                root = st.top();
                st.pop();
            }
            prev->next = root;
            root->prev = prev;
            prev->child = nullptr;
            prev = root;
            if(root->next != nullptr && root->child != nullptr){
                st.push(root->next);
                root = root->child;
            }
            else if(root->next != nullptr)      root = root->next;
            else if(root->child != nullptr)     root = root->child;
            else    root = nullptr;
        }
        prev->child = prev->next = nullptr;
        head = head->next;
        head->prev = nullptr;
        return head;
    }
};