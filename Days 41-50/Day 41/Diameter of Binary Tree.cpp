/*
Author : Shreeraksha R Aithal
Problem name : Diameter of Binary Tree
Problem link : https://leetcode.com/problems/diameter-of-binary-tree/
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
    int Max;
    int dfs(TreeNode* root){
        if(root == nullptr)     return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        Max = max(Max, 1 + left + right);
        return 1 + max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        Max = 0;
        Max = max(Max, dfs(root));
        return Max-1;
    }
};