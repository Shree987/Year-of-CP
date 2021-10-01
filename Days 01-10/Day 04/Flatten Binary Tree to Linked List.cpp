/*
Author : Shreeraksha R Aithal
Problem name : Flatten Binary Tree to Linked List
Problem link : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
Difficulty : Medium
Tags : Binary Tree, Depth-first Search, Linked List, Tree
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    stack<TreeNode*> st;
    TreeNode* flattenTree(TreeNode *root){
        if(root->left == nullptr && root->right == nullptr){
            st.push(root);
            return root;
        }
        if(root->left == nullptr){
            root->right = flattenTree(root->right);
            root->left = nullptr;
            return root;
        }
        if(root->right == nullptr){
            root->right = flattenTree(root->left);
            root->left = nullptr;
            return root;
        }
        TreeNode *end;
        auto ptrL = flattenTree(root->left);
        end = st.top();
        st.pop();
        auto ptrR = flattenTree(root->right);
        end->left = nullptr;
        end->right = ptrR;
        root->left = nullptr; 
        root->right = ptrL;
        return root;
    }
public:
    void flatten(TreeNode* root) {
        if(root == nullptr)     return ;
        flattenTree(root);
    }
};