/*
Author : Shreeraksha R Aithal
Problem name : Maximum Depth of Binary Tree
Problem link : https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
    int depth;
    void dfs(TreeNode* root, int d){
        if(root->left == nullptr && root->right == nullptr){
            depth = max(d, depth);
            return ;
        }
        if(root->left != nullptr){
            dfs(root->left, d+1);
        }
        if(root->right != nullptr){
            dfs(root->right, d+1);
        }
    }
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)     return 0;
        depth = -1;
        dfs(root, 1);
        return depth;
    }
};