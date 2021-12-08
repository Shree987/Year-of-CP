/*
Author : Shreeraksha R Aithal
Problem name : Binary Tree Tilt
Problem link : https://leetcode.com/problems/binary-tree-tilt/
Difficulty : Easy
Tags : Binary Tree, Depth-first Search, Tree
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
    int total = 0;
    int dfs(TreeNode* root){
        if(root == nullptr)     return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        total += abs(left - right);
        return left+right+root->val;
    }
public:
    int findTilt(TreeNode* root) {
        if(root == nullptr)     return 0;
        total = 0;
        dfs(root);
        return total;
    }
};