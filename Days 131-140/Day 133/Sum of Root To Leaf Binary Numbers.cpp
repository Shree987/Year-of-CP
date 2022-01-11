/*
Author : Shreeraksha R Aithal
Problem name : Sum of Root To Leaf Binary Numbers
Problem link : https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
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
    int sum;
    void dfs(TreeNode* root, int cnt){        
        cnt = cnt*2 + root->val;
        if(root->left == nullptr && root->right == nullptr){
            sum += cnt;
            return ;
        }
        if(root->left != nullptr)   dfs(root->left, cnt);
        if(root->right != nullptr)   dfs(root->right, cnt);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        sum = 0;
        dfs(root, 0);
        return sum;
    }
};