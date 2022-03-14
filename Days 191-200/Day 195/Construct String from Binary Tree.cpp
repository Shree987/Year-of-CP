/*
Author : Shreeraksha R Aithal
Problem name : Construct String from Binary Tree
Problem link : https://leetcode.com/problems/construct-string-from-binary-tree/
Difficulty : Easy
Tags : Binary Tree, Depth-first earch, String, Tree
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
    string tree2str(TreeNode* root) {
        if(root == nullptr)     return "";
        string ans = to_string(root->val);
        if(root->left == nullptr && root->right == nullptr)  return ans;
        ans = ans + "(" + tree2str(root->left) + ")";
        if(root->right != nullptr){
            ans = ans + "(" + tree2str(root->right) + ")";
        }
        return ans;
    }
};