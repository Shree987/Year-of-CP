/*
Author : Shreeraksha R Aithal
Problem name : Range Sum of BST
Problem link : https://leetcode.com/problems/range-sum-of-bst/
Difficulty : Easy
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
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr)     return 0;
        int sum = 0;
        if(root->val <= high && root->val >= low)       sum += root->val;
        if(root->val > high){
            sum += rangeSumBST(root->left, low, high);
        }
        else if(root->val < low){
            sum += rangeSumBST(root->right, low, high);
        }
        else{
            sum += rangeSumBST(root->left, low, high);
            sum += rangeSumBST(root->right, low, high);            
        }
        return sum;
    }
};