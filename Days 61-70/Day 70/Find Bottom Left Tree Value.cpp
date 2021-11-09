/*
Author : Shreeraksha R Aithal
Problem name : Find Bottom Left Tree Value
Problem link : https://leetcode.com/problems/find-bottom-left-tree-value/
Difficulty : Medium
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
    int d, val;
    void dfs(TreeNode* root, int depth){
        if(root == nullptr)     return ;
        if(depth > d){
            d = depth;
            val = root->val;
        }
        dfs(root->left, depth+1);
        dfs(root->right, depth+1);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        val = -1;
        d = -1;
        dfs(root, 0);
        return val;
    }
};