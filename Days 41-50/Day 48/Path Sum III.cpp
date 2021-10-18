/*
Author : Shreeraksha R Aithal
Problem name : Path Sum III
Problem link : https://leetcode.com/problems/path-sum-iii/
Difficulty : Medium
Tags : Binary Tree, Depth-first Tree, Tree
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
    vector<int> v;
    int count, len;
    void dfs(TreeNode* root, int &targetSum){
        if(root == nullptr)     return ;
        if(root->val == targetSum)  count++;
        for(int i = 0; i < len; i++){
            v[i] = v[i] + root->val;
            if(v[i] == targetSum)  count++;
        }        
        v[len++] = root->val;
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        v[--len] = 0;
        for(int i = 0; i < len; i++){
            v[i] = v[i] - root->val;
        } 
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        count = len = 0;
        v.resize(1000);
        dfs(root, targetSum);
        return count;
    }
};