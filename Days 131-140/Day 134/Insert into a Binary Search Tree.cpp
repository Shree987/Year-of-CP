/*
Author : Shreeraksha R Aithal
Problem name : Insert into a Binary Search Tree
Problem link : https://leetcode.com/problems/insert-into-a-binary-search-tree/
Difficulty : Medium
Tags : Binary Search Tree, Binary Tree, Tree
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            TreeNode *ptr = new TreeNode(val);
            return ptr;
        }
        if(root->val > val){
            root->left = insertIntoBST(root->left, val);
        }
        else{
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};