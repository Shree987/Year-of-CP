/*
Author : Shreeraksha R Aithal
Problem name : Maximum Depth of N-ary Tree
Problem link : https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
Difficulty : Easy
Tags : Breadth-first Search, Depth-first Search, Tree
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr)     return 0;
        int ans = 1;
        for(auto &ptr : root->children){
            ans = max(ans, 1 + maxDepth(ptr));
        }
        return ans;
    }
};