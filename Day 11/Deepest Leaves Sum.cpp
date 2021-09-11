/*
Author : Shreeraksha R Aithal
Problem name : Deepest Leaves Sum
Problem link : https://leetcode.com/problems/deepest-leaves-sum/
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
    int depth, sum;
public:
    void dfs(TreeNode* root, int depth){
        if(root == nullptr)     return ;
        if(root->left == nullptr && root->right == nullptr){
            if(depth == this->depth)    sum += root->val;
            else if(depth > this->depth){
                this->depth = depth;
                sum = root->val;
            }
        }
        else{
            dfs(root->left, depth+1);
            dfs(root->right, depth+1);
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        depth = sum = 0;
        dfs(root, 0);
        return sum;
    }
};