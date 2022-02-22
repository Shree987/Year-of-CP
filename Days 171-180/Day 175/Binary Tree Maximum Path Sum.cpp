/*
Author : Shreeraksha R Aithal
Problem name : Binary Tree Maximum Path Sum
Problem link : https://leetcode.com/problems/binary-tree-maximum-path-sum/
Difficulty : Hard
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
    int answer;
    int dfs(TreeNode* root){
        if(root == nullptr)     return 0;
        int left = max(0, dfs(root->left)), right = max(0, dfs(root->right));
        answer = max(answer, root->val + left + right);
        return root->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        answer = root->val;
        dfs(root);
        return answer;
    }
};