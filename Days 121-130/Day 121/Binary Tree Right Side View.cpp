/*
Author : Shreeraksha R Aithal
Problem name : Binary Tree Right Side View
Problem link : https://leetcode.com/problems/binary-tree-right-side-view/
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
    void dfs(vector<int>& res, TreeNode* root, int depth){
        if(res.size() == depth)     res.push_back(root->val);
        else    res[depth] = root->val;
        if(root->left != nullptr)   dfs(res, root->left, depth+1);
        if(root->right != nullptr)   dfs(res, root->right, depth+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root != nullptr)     dfs(res, root, 0);
        return res;
    }
};