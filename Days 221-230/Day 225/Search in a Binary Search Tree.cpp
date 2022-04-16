/*
Author : Shreeraksha R Aithal
Problem name : Search in a Binary Search Tree
Problem link : https://leetcode.com/problems/search-in-a-binary-search-tree/
Difficulty : Easy
Tags : Binary Tree, Binary Search Tree, Tree
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr)         return nullptr;
        if(root->val < val)         return searchBST(root->right, val);
        if(root->val > val)         return searchBST(root->left, val);
        return root;
    }
};