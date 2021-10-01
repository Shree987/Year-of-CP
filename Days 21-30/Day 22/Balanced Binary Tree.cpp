/*
Author : Shreeraksha R Aithal
Problem name : Balanced Binary Tree
Problem link : https://leetcode.com/problems/balanced-binary-tree/
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
    bool answer;
    int height(TreeNode* root){
        if(root == nullptr || !answer)     return 0;
        int left = height(root->left);
        int right = height(root->right);
        if(abs(left-right) >= 2)    answer = false;
        return 1 + max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        answer = true;
        height(root);
        return answer;
    }
};