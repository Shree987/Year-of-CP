/*
Author : Shreeraksha R Aithal
Problem name : House Robber III
Problem link : https://leetcode.com/problems/house-robber-iii/
Difficulty : Medium
Tags : Binary Tree, Depth-first Search, Dynamic Programming, Tree
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
    void dfs(TreeNode* root, int &with, int &without){
        if(root == nullptr){
            with = without = 0;
            return ;
        }
        int with1, with2, without1, without2;
        with1 = with2 = without1 = without2 = 0;
        dfs(root->left, with1, without1);
        dfs(root->right, with2, without2);
        with = root->val + without1 + without2;
        without = max(with1, without1) + max(without2, with2);
    }
    int rob(TreeNode* root) {
        int with = 0, without = 0;
        dfs(root, with, without);
        return max(with, without);
    }
};