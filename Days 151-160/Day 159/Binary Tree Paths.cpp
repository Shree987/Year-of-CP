/*
Author : Shreeraksha R Aithal
Problem name : Binary Tree Paths
Problem link : https://leetcode.com/problems/binary-tree-paths/
Difficulty : Easy
Tags : Depth-first Search, Backtracking, Binary Tree, String, Tree
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
    void dfs(vector<string> &vec, string str, TreeNode* root){
        str = str + "->" + to_string(root->val);
        if(root->left == nullptr && root->right == nullptr){
            vec.push_back(str);
            return ;
        }
        if(root->left !=  nullptr){
            dfs(vec, str, root->left);
        }
        if(root->right !=  nullptr){
            dfs(vec, str, root->right);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vec;
        string str = to_string(root->val);
        if(root->left == nullptr && root->right == nullptr){
            vec.push_back(str);
            return vec;
        }
        if(root->left != nullptr){
            dfs(vec, str, root->left);
        }
        if(root->right != nullptr){
            dfs(vec, str, root->right);
        }
        return vec;
    }
};