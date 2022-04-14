/*
Author : Shreeraksha R Aithal
Problem name : Convert BST to Greater Tree
Problem link : https://leetcode.com/problems/insert-into-a-binary-search-tree/
Difficulty : Medium
Tags : Binary Tree, Binary Search Tree, Depth-first Search, Tree
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
    int sumNodes(TreeNode* root, int inSum){
        if(root == nullptr)     return inSum;
        inSum = sumNodes(root->right, inSum);
        root->val += inSum;
        inSum = sumNodes(root->left, root->val);
        return inSum;
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        sumNodes(root, 0);
        return root;
    }
};