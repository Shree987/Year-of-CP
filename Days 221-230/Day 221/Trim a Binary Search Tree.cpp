/*
Author : Shreeraksha R Aithal
Problem name : Trim a Binary Search Tree
Problem link : https://leetcode.com/problems/trim-a-binary-search-tree/
Difficulty : Medium
Tags : Binary Tree, Binary Search Tree, Depth-first Search, Tree
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == nullptr)         return nullptr;
        TreeNode *Left = trimBST(root->left, low, high);
        TreeNode *Right = trimBST(root->right, low, high);
        if(root->val >= low && root->val <= high){
            root->left = Left;
            root->right = Right;
            return root;
        }
        else{
            if(root->val > high)        return Left;
            else    return Right;
        }
        return nullptr;
    }
};