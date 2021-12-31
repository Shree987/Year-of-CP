/*
Author : Shreeraksha R Aithal
Problem name : Maximum Difference Between Node and Ancestor
Problem link : https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
Difficulty : Medium
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
    int answer;
    void dfs(int Max, int Min, TreeNode* root){
        answer = max(answer, max(abs(root->val - Min), abs(root->val - Max)));
        Max = max(root->val, Max);
        Min = min(root->val, Min);
        if(root->left != nullptr)       dfs(Max, Min, root->left);
        if(root->right != nullptr)       dfs(Max, Min, root->right);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        answer = 0;
        dfs(root->val, root->val, root);
        return answer;
    }
};