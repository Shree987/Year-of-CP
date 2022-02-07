/*
Author : Shreeraksha R Aithal
Problem name : Univalued Binary Tree
Problem link : https://leetcode.com/problems/univalued-binary-tree/
Difficulty : Easy
Tags : Binary Tree, Breadth-first Search, Depth-first Search, Tree
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
public:
    bool isUnivalTree(TreeNode* root) {
        if(root == nullptr)     return true;
        if(root->left != nullptr){
            if(root->val != (root->left)->val)      return false;
            if(!isUnivalTree(root->left))       return false;
        }
        if(root->right != nullptr){
            if(root->val != (root->right)->val)      return false;
            return isUnivalTree(root->right);
        }
        return true;
    }
};