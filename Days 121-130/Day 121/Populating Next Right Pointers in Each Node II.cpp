/*
Author : Shreeraksha R Aithal
Problem name : Populating Next Right Pointers in Each Node II
Problem link : https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
Difficulty : Medium
Tags : Binary Tree, Breadth-first Search, Depth-first Search, Tree
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)    return root;
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        while(q.size() > 1){
            Node* ptr = q.front();
            q.pop();
            if(ptr == nullptr){
                q.push(nullptr);
            }
            else{
                ptr->next = q.front();
                if(ptr->left != nullptr){
                    q.push(ptr->left);
                }
                if(ptr->right != nullptr){
                    q.push(ptr->right);
                }
            }
        }
        return root;
    }
};