/*
Author : Shreeraksha R Aithal
Problem name : Average of Levels in Binary Tree
Problem link : https://leetcode.com/problems/average-of-levels-in-binary-tree/
Difficulty : Easy
Tags : Binary Tree, Breadth-first Search, Depth-first Search, Tree, 
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
    vector<double> ans;
    vector<int> count;
    void dfs(TreeNode* root, int level){
        if(root == nullptr)     return ;
        if(count.size() == level){
            count.push_back(1);
            ans.push_back(root->val);
        }
        else{
            count[level]++;
            ans[level] += root->val;
        }
        dfs(root->left, level+1);
        dfs(root->right, level+1);
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(root, 0);
        for(int i = 0; i < count.size(); i++){
            ans[i] /= count[i];
        }
        return ans;
    }
};