/*
Author : Shreeraksha R Aithal
Problem name : Sum of Left Leaves
Problem link : https://leetcode.com/problems/sum-of-left-leaves/
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
    int  dfs(TreeNode* root, bool left){
        if(root == nullptr)     return 0;
        if(root->left == nullptr && root->right == nullptr){
            if(left)    return root->val;
            return 0;
        }
        return dfs(root->left, true) + dfs(root->right, false);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
};